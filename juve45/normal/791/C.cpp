#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 100

using namespace std;

int n, a, b, m, nrc, use[DMAX], k;
int v[DMAX];

string name = "Abcqwert", s, ans[100];

int main()
{
	cin >> n >> k;
	for(int i=1;i<=n-k+1;i++)
	{
		cin >> s;
		if(s == "NO") v[i+k-1] = 1;
	}



	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			next_permutation(name.begin()+1, name.end());
			ans[i] = name;
		}
		else ans[i] = ans[i-k+1];
	}
	for(int i=1;i<=n;i++)
		cout << ans[i] << '\n';
}