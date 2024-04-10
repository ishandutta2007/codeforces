#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 300100
#define NMAX 1
#define MMAX 1

using namespace std;

int n, t[2*DMAX], c[DMAX], k, use[2*DMAX];
long long ans;
string s;
priority_queue<pair<int, int> > p;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		use[i] = 1;
		p.push({-c[i], i});
	}	
	for(int i = k+n; i > k; i--)
	{
		if(use[i] == 1) 
		{
			t[i] = i;
			use[i] = 0;
		}
		else{
			while(use[p.top().second] == 0)
				p.pop();
			int x = p.top().second;
			t[x] = i;
			use[x] = 0;
			ans += 1LL * (i - x) * c[x];
			p.pop();
		}
	}

	cout << ans << '\n';
	for(int i = 1; i <= n; i++)
		cout << t[i] << ' ';

}