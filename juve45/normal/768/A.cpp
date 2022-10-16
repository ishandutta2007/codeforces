#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"


using namespace std;
int x[100009], n, m=1000000009, M=0;
int main()
{
	int ans = 0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x[i];
		m = min(x[i], m);
		M=max(x[i], M);
	}

	for(int i=1;i<=n;i++)
		if(m < x[i] && M>x[i])
			ans++;
		cout << ans;
}