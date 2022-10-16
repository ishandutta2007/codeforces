#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, k, x, b[100100];
long long s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> x, s += 1LL * x;	
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	sort(b + 1,  b + n + 1);
	s -= 1LL * b[n];
	s -= 1LL * b[n - 1];
	if(s <= 0) cout << "YES";
	else cout << "NO";	
}