#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int n, T;
std::vector<std::pair<int, std::pair<int, int>>> data; // (i_0, (t_i, a_i))

bool possible(int k, std::vector<int>* output)
{
	int counter = 0;
	int total_time = 0;

	for(int i = 0; i < data.size(); ++i)
	{
		if(output)
		{
			if(output->size() == k)
				break;
		}
		else if(counter == k)
		{
			break;
		}

		if(k <= data[i].second.second)
		{
			if(output)
				output->push_back(data[i].first);
			else
				++counter;

			total_time += data[i].second.first;

			if(total_time > T)
				return false;
		}
	}

	if(output)
	{
		if(output->size() < k)
			return false;
	}
	else if(counter < k)
	{
		return false;
	}

	return true;
}

int main(int argc, char** argv)
{
	std::cin >> n >> T;

	for(int i = 0; i < n; ++i)
	{
		int t, a;
		std::cin >> a >> t;

		data.push_back(std::make_pair(i + 1, std::make_pair(t, a)));
	}

	std::sort(data.begin(), data.end(),
			[](std::pair<int, std::pair<int, int>> l, std::pair<int, std::pair<int, int>> r) { return l.second.first < r.second.first; });

	int lo  = 0;
	int hi  = n;
	int ans = 0;

	while(lo != hi && hi != lo + 1)
	{
		int m = lo + (hi - lo) / 2;

		if(possible(m, nullptr))
		{
			lo = m;
		}
		else
		{
			hi = m;
		}
	}

	if(lo > ans && possible(lo, nullptr))
		ans = lo;

	if(hi > ans && possible(hi, nullptr))
		ans = hi;

	std::cout << ans << std::endl << ans << std::endl;

	if(ans)
	{
		std::vector<int> indecies;
		possible(ans, &indecies);

		for(int i = 0; i < indecies.size(); ++i)
			std::cout << indecies[i] << " ";

		std::cout << std::endl;
	}

	return 0;
}