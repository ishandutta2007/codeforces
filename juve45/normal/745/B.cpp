#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k, m, xa=10000, ya=1000, xb, yb;
char c[555][555];
int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin >> c[i][j];
			if(c[i][j] == '.') continue;
			xa=min(xa, i);
			xb=max(xb, i);
			yb=max(yb, j);
			ya=min(ya, j);
		}

	for(int i=xa;i<=xb;i++)
	{
		for(int j=ya;j<=yb;j++)
		{
			if(c[i][j]=='.')
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}