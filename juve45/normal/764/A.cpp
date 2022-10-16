#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"


using namespace std;
int n, m, k, ans;
int main()
{

	cin >> n >> m >> k;
	for(int i=1;i<=k;i++)
	{
		if(i%m == 0 && i%n == 0)
			ans ++;
	}
	cout << ans;

	return 0;
}