#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"


using namespace std;

int n, a, b;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> a >> b;
	int ans = 0;
	while(a <= b)
	{
		a*=3;
		b*=2;
		ans ++;
	}
	cout << ans << '\n';
}