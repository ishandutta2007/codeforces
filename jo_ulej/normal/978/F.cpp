#include <iostream>
#include <algorithm>
#include <vector>

struct P
{
	int i;
	int r;

	bool operator<(const P& other)
	{
		return r < other.r;
	}
};

int main(int argc, char** argv)
{
	int n, k;
	std::vector<int> r;
	std::vector<int> ans;
	std::vector<P>   ps;

	std::cin >> n >> k;

	for(int i = 0; i < n; ++i)
	{
		r.push_back(0);

		std::cin >> r[i];

		P new_p;
		new_p.i = i;
		new_p.r = r[i];

		ps.push_back(new_p);
	}

	std::sort(ps.begin(), ps.end());
	std::reverse(ps.begin(), ps.end());
	ans.resize(n, 0);

	for(int j = n - 1; j >= 0; --j)
	{
		int i = ps[j].i;

		if(j + 1 < n && ps[j].r == ps[j + 1].r)
		{
			ans[i] = ans[ps[j + 1].i];
		}
		else
		{
			ans[i] = n - j - 1;
		}
	}

	for(int a = 0; a < k; ++a)
	{
		int i1, i2;

		std::cin >> i1 >> i2;
		--i1;
		--i2;

		if(r[i1] > r[i2])
		{
			--ans[i1];
		}
		else if(r[i1] < r[i2])
		{
			--ans[i2];
		}
	}

	for(int i = 0; i < n; ++i)
	{
		std::cout << ans[i] << " ";
	}

	std::cout << std::endl;

	return 0;
}