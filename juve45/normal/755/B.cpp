#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k, m, h;
string s;
map<string, int>c;
int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> s;
		c[s]++;
	}

	for(int i=1;i<=m;i++)
	{
		cin >> s;
		if(c[s]) h++;
	}

	n-=h;
	m-=h;
	h=h%2;
	n+=h;

	if(n > m)
	{
		cout << "YES";
	}
	else cout <<"NO";

	return 0;
}