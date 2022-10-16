#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1

using namespace std;

int n;

int main()
{
	cin >> n;
	int ans = 0, k = 0;
	for(int i=1;i<=n;i++)
	{
		ans += k;
		if(i%2) k++;
	}
	cout << ans << '\n';

	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(i%2 + j%2 == 1)
				cout << i << ' ' << j << '\n';
}