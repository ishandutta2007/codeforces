#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100010

using namespace std;

string s1, s2;
set<string>s;
int n, c[DMAX];

void ciur()
{
	for(int i=2;i<DMAX;i++)
	{
		if(c[i] == 1) continue;

		for(int j=2*i;j<DMAX;j+=i)
			c[j] = 1;

	}

}

int main()
{
	cin >> n;
	ciur();
	if(n>2)
	cout << "2\n";
else cout << "1\n";
	for(int i=2;i<=n+1;i++)
	{
		if(c[i] == 0) cout << "1 ";
		else cout << "2 ";
	}
	return 0;
}