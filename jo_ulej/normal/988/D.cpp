#include <iostream>
#include <set>
#include <vector>

typedef long long int ll;

std::vector<ll> count(const std::set<ll>& s, ll min_val, ll max_val, ll val)
{
	ll d = 1;
	std::vector<ll> max_ans;

	while(val + d <= max_val || val - d >= min_val)
	{
		std::vector<ll> ans;

		if(s.find(val + d) != s.end())
			ans.push_back(val + d);

		if(s.find(val - d) != s.end())
			ans.push_back(val - d);

		if(ans.size() > max_ans.size())
			max_ans = ans;

		if(ans.size() == 2)
			break;

		d *= 2;
	}

	max_ans.push_back(val);

	return max_ans;
}

int main(int argc, char** argv)
{
	int n, temp, min, max;
	bool once = true;
	std::set<ll> s;

	std::cin >> n;

	for(int i = 0; i < n; ++i)
	{
		std::cin >> temp;

		s.insert(temp);

		if(once)
		{
			once = false;

			min = temp;
			max = temp;
		}

		if(temp < min)
			min = temp;

		if(temp > max)
			max = temp;
	}

	std::vector<ll> ans;

	for(int elem: s)
	{
		std::vector<ll> attempt = count(s, min, max, elem);

		if(attempt.size() > ans.size())
			ans = attempt;

		if(ans.size() == 3)
			break;
	}

	std::cout << ans.size() << std::endl;

	for(int elem: ans)
		std::cout << elem << " ";

	std::cout << std::endl;

	return 0;
}