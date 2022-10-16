#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, a[10000];
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	if(a[0]%2 && a[n-1]%2 && n%2)
		cout << "Yes";
	else cout << "No";

}