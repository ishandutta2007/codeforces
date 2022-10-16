#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 200100
#define NMAX 1
#define MMAX 1

using namespace std;


int n, k, x;
int a[DMAX];
int ans[DMAX];
int b[DMAX];
int v[DMAX];

bool comp(int x, int y)
{
	if(b[x] < b[y])
		return 1;
	return 0;
}

string s;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i], v[i] = i;

	sort(v + 1, v + n + 1, comp);
	sort(a+1, a + n + 1, greater<int>());
	for(int i = 1; i <= n; i++)
	{
		ans[v[i]] = a[i];
	}
	//dbg_v(v, n+1);
	//dbg_v(a, n+1);
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' '; 
	return 0;
}