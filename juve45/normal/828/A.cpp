#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, a, b, ans;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b;
	int c = 0;
	int x;
	for(int i = 1; i <= n; i++)
	{
		cin >> x;
		if(x == 2)
		{
			if(b == 0) ans+=2;
			else b--;
		}
		else{
			if(a == 0)
			{
				if(b == 0)
				{
					if(c == 0) ans++;
					else c--;
				}else b--, c++;	
			}
			else a--;
		}
	}


cout << ans << '\n';

}