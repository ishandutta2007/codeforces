#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, k, ans, f[1245];
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> k >> s;

	for(int i = 0; i < s.size(); i++) f[s[i] - '0']++, n += s[i] - '0';

	int c = 0;
	while(n < k)
	{
		while(f[c] == 0) c++;
		ans++;
		n += 9;
		n -= c;
		f[c]--;
	}	
	cout << ans << '\n';


}