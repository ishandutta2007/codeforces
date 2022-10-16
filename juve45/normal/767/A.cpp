#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100010
#define MOD 1000000007
using namespace std;

int n, x;
priority_queue <int> p;

int main()
{
	cin >> n;
	int c = n;
	for(int i=1;i<=n;i++)
	{
		cin >> x;
		p.push(x);
		while(!p.empty() && p.top()==c)
		{
			cout << c << ' ';
			p.pop();
			c--;
		}
		cout << '\n';
	}
 	return 0;
}