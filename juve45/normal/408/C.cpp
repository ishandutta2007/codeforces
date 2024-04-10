#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

using namespace std;
int a,b ,n, x, y;
#define DMAX 100010

bool check(int x1, int y1, int x2, int y2)
{
	if(y1 == y2) return 0;
	int X = abs(x1-x2);
	int Y = abs(y1-y2);

	if(X*X + Y*Y == a*a + b*b)
	{
		cout << "YES\n";
		cout << x1 << ' ' << y1 << '\n';
		cout << x2 << ' ' << y2 << '\n';
		cout << 0 << ' ' << 0 << '\n';
		return 1;
	}
	return 0;
}	

int main()
{
	cin >> a >> b;


	for(int i=1;i<=a;i++)
	{
		int y = sqrt(a*a-i*i);
		if(y*y + i*i == a*a && y!=0)
		{
			for(int j=1;j<=b;j++)
			{
				int x=sqrt(b*b-j*j);
				if(x*x+j*j == b*b && x!=0)
				{
					if(check(-i, y, x, j))
						return 0;
					if(check(-y, i, x, j))
						return 0;
					if(check(-i, y, j, x))
						return 0;
					if(check(-y, i, j, x))
						return 0;
				}
			}
		}
	}

	cout << "NO";

 	return 0;
}