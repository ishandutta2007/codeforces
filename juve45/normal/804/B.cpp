#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define MOD 1000000007
using namespace std;

int n, ans, c;
string s;
int main()
{
	cin >> s;
	reverse(s.begin(), s.end());
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'b')
		{
			c++;
		}
		else{
			ans += c;
			c *= 2;
			c %= MOD;
			ans %= MOD;
		}
	}
	cout << ans << '\n';

}