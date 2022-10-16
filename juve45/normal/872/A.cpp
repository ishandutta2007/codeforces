#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1010
#define NMAX 1
#define MMAX 1

using namespace std;

int n, x, k, f[DMAX], use[DMAX], m;
string s;

int main()
{
	
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	int ans1, ans2;
	for(int i = 1; i <= n; i++)
		cin >> x, f[x]++;
	for(int i = 1; i <= m; i++)
		cin >> x, f[x]+=2;

	for(int i = 1; i <= 9; i++)
		if(f[i] == 3)
		{
			cout << i << '\n';
			return 0;
		}
	for(int i = 1; i <= 9; i++)
		if(f[i] == 1)
		{
			ans1 = 10 * i;
			ans2 = i;
			break;
		}
	for(int i = 1; i <= 9; i++)
		if(f[i] == 2)
		{
			ans1 += i;
			ans2 += 10*i;
			break;
		}
		cout << min(ans1, ans2);
}