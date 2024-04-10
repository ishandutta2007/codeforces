#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, s, t1, t2, v1, v2;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> s >> v1 >> v2 >> t1 >> t2;

	if(s*v1 + 2*t1 < s*v2 + 2*t2) cout << "First";
	if(s*v1 + 2*t1 == s*v2 + 2*t2) cout << "Friendship";
	if(s*v1 + 2*t1 > s*v2 + 2*t2) cout << "Second";	


}