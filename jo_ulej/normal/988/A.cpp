#include <iostream>
#include <algorithm>

#define MAX 100

int main(int argc, char** argv)
{
	int idx[MAX + 1];
	int n, k, a;

	for(int i = 1; i <= MAX; ++i)
		idx[i] = -1;

	std::cin >> n >> k;

	for(int i = 0; i < n; ++i)
	{
		std::cin >> a;

		if(idx[a] == -1)
			idx[a] = i + 1;
	}

	std::vector<int> ans;

	for(a = 1; ans.size() < k && a <= MAX; ++a)
	{
		if(idx[a] != -1)
			ans.push_back(idx[a]);
	}

	if(ans.size() < k)
	{
		std::cout << "NO" << std::endl;
	}
	else
	{
		std::cout << "YES" << std::endl;

		for(int i = 0; i < ans.size(); ++i)
			std::cout << ans[i] << " ";

		std::cout << std::endl;
	}

	return 0;
}