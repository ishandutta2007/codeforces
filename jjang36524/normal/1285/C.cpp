#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#define int long long
using namespace std;
int N, M;
map<int, int>ava;
set<int>poss;
set<int>np;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int oN;
	cin >> N;
	oN = N;
	int s = sqrt(N);
	int i;
	for (i = 2; i <= s; i++)
	{
		while (N % i == 0)
		{
			N /= i;
			ava[i]++;
		}
	}
	if (N != 1)
		ava[N]++;
	poss.insert(1);
	auto it=ava.begin();
	for (it = ava.begin(); it != ava.end(); it++)
	{
		int at = 1;
		for (auto j = poss.begin(); j != poss.end(); j++)
		{
			np.insert(at * (*j));
		}
		for (i = 0; i <(*it).second; i++)
		{
			at *= (*it).first;
		}
		for (auto j = poss.begin(); j != poss.end(); j++)
		{
			np.insert(at * (*j));
		}
		poss = np;
	}
	pair<int, int>a = { 1LL << 60,0 };
	for (auto j = poss.begin(); j != poss.end(); j++)
	{
		if (max(a.first, a.second) > max(*j, oN / (*j)))
		{
			a={*j,oN/(*j)};
		}
	}
	cout << a.first<<' '<<a.second;

}