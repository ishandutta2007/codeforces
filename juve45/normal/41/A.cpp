#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1

using namespace std;

int n;
string s, t;
int main()
{
	cin >> s >> t;
	reverse(s.begin(), s.end());
	if(s == t)
		cout << "YES\n";
	else cout << "NO\n";


}