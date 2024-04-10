#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, k, x, y;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> s;
	for(auto i : s)
		if(i == '-')x++;
		else y++;

	if(y == 0 || x % y == 0)
		cout << "YES\n";
	else cout << "NO\n";
}