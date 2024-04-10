#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, cand = 0, a;
string s;

double dabs(double a)
{
	if(a > 0) return a;
	return -a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> a;
	double vf = 180.*(1.*n-2)/n;
	vf /= (n-2);
	double an = 10000;
	//dbg(vf);
	for(int i = 3; i <= n; i++)
	{
		//dbg(dabs(vf*(i-2)-a));
		if(an > dabs(vf*(i-2)-a))
		{
			an = dabs(vf*(i-2)-a);
			cand = i;
		}
	}

	cout << "2 1 " << cand << '\n';
}