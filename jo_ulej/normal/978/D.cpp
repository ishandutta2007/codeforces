#include <bits/stdc++.h>

int solve(std::vector<int> arr, int diff)
{
	// std::cout << "diff=" << diff << std::endl;

	int changes = 0;

	for(int i = 0; i < arr.size(); ++i)
	{
		int x = arr[i];
		int y = arr[0] + i * diff;

		// std::cout << "\tx,y=" << x << "," << y << std::endl;

		if(std::abs(x - y) > 1)
			return -1000;

		if(std::abs(x - y) == 1)
			++changes;
	}

	// std::cout << "changes=" << changes << std::endl;

	return changes;
}

void update(int& x, int val)
{
	if(val >= 0 && (x < 0 || val < x))
		x = val;
}

int main(int argc, char** argv)
{
	std::vector<int> data;
	std::set<int> diffs;
	int n;

	std::cin >> n;
	data.resize(n);

	for(int i = 0; i < n; ++i)
		std::cin >> data[i];

	if(n <= 2)
	{
		std::cout << "0" << std::endl;

		return 0;
	}

	int d = data[1] - data[0];

	for(int j = -2; j <= 2; ++j)
		diffs.insert(d + j);

	int ans   = -1;

	for(int d: diffs)
		update(ans, solve(data, d));

	--data[0];

	for(int d: diffs)
		update(ans, solve(data, d) + 1);

	data[0] += 2;

	for(int d: diffs)
		update(ans, solve(data, d) + 1);

	std::cout << ans << std::endl;

	return 0;
}