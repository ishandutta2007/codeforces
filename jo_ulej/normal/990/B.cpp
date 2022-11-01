#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main(int argc, char** argv)
{
	int n, K;
	std::vector<int> data;

	std::cin >> n >> K;
	data.resize(n);

	for(int i = 0; i < n; ++i)
		std::cin >> data[i];

	std::sort(data.begin(), data.end());

	int ans = 1;

	for(int i = 0; i < n - 1;)
	{
		int j = i + 1;

		while(j < n - 1 && data[j] == data[i])
			++j;

		int delta = data[j] - data[i];

		if(delta > K || delta == 0)
			ans += j - i;

		i = j;
	}

	std::cout << ans << std::endl;

	return 0;
}