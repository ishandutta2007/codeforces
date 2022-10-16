#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100006
#define NMAX 1
#define MMAX 1

using namespace std;

long long n, k;
long long s[DMAX];
map<long long, long long> m, v;
priority_queue <pair<long long, long long>> p;

long long comb(long long n, long long k)
{
	long long ans = 1;
	for(long long i = 0; i < k; i++)
	{
		ans *= n-i;
	}
	for(long long i = 1; i <= k; i++)
		ans /= i;
	return ans;
}

long long C(long long n,long long r){
    long long ans[27][27]={0};
    long long i,j;
    for(i=0;i<27;i++){
        ans[i][0]=1;
        for(j=1;j<=i;j++)ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
    }
    return ans[n][r];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(long long i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
//	cin >> k;
	k = 3;
	for(long long i = 1; i <= n; i++)
	{
		m[s[i]]++;
	}

	for(auto x : m)
	{
		p.push({-x.first, x.second});
	}
	long long cnt = 0;
	long long ans = 1;
	long long len = 0;
	//dbg(comb(100000, 3));
	while(!p.empty())
	{
		auto x = p.top();
		p.pop();
		if(cnt + x.second > k)
		{
			ans = comb(x.second, k-cnt);
			break;
		}
		cnt += x.second;
	}
	cout << ans << '\n';
}