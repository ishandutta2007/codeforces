#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1001000
#define NMAX 100100
#define MMAX 1

using namespace std;

long long n, m, k, d, depc, arrc, c1;
string s;

long long dp1[DMAX], dp2[DMAX], cst[DMAX], nr, tot;

vector <pair<long long, pair<long long, long long> > > dep, arr;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m >> k;


	for(long long i = 1; i <= m; i++)
	{
		cin >> d >> depc >> arrc >> c1;

		if(depc == 0) 
			dep.push_back({-d, {arrc, c1}});
		else
			arr.push_back({d, {depc, c1}});

	}

	sort(dep.begin(), dep.end());
	sort(arr.begin(), arr.end());

	nr = 0;
	memset(cst, -1, sizeof cst);
	memset(dp1, -1, sizeof dp1);
	long long index = 0, sum = 0;

	for(long long i = 1; i <= 1000000; i++)
	{
		dp1[i] = dp1[i-1];

		while(index < arr.size() && arr[index].first <= i)
		{
			if(cst[arr[index].second.first] == -1)
			{
				nr++;
				cst[arr[index].second.first] = arr[index].second.second;
				sum += arr[index].second.second;
				if(nr == n)	
				{
					dp1[i] = sum;
				}
			}
			else if(arr[index].second.second < cst[arr[index].second.first])
			{
				if(nr == n)
					dp1[i] -= cst[arr[index].second.first] - arr[index].second.second;
				else
					sum -= cst[arr[index].second.first] - arr[index].second.second;
				cst[arr[index].second.first] = arr[index].second.second;
			}
			index++;
		}
	}

	//dbg_v(dp1, 20);


	nr = 0;
	memset(cst, -1, sizeof cst);
	memset(dp2, -1, sizeof dp1);
	index = 0, sum = 0;

	for(long long i = 1000000; i > 0; i--)
	{
		dp2[i] = dp2[i+1];

		while(index < dep.size() && -dep[index].first >= i)
		{
			if(cst[dep[index].second.first] == -1)
			{
				nr++;
				cst[dep[index].second.first] = dep[index].second.second;
				sum += dep[index].second.second;
				if(nr == n)	
				{
					dp2[i] = sum;
				}
			}
			else if(dep[index].second.second < cst[dep[index].second.first])
			{
				if(nr == n)
					dp2[i] -= cst[dep[index].second.first] - dep[index].second.second;
				else
					sum -= cst[dep[index].second.first] - dep[index].second.second;
				cst[dep[index].second.first] = dep[index].second.second;
			}
			index++;
		}
	}

	long long ans = 1000000000000000000LL;
	for(long long i = 1; i + k + 1 <= 1000000; i++)
	{
		if(dp1[i] != -1 && dp2[i+k+1] != -1)
		{
			ans = min(ans, dp1[i] + dp2[i+k+1]);
		}
	}
	if(ans == 1000000000000000000LL)
		cout << "-1";
	else cout << ans;

	//dbg_v(dp2, 20);
}