#include <bits/stdc++.h>
#define x first
#define y second
#define inf 1000000000
#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k;

int v[200009];
int d[200009];

int main()
{
	ios_base::sync_with_stdio(false);
	
	int Max = inf;
	int Min = -inf;
	int div;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> v[i] >> d[i];
	}

	v[0] = -100000000;
	for(int i=1;i<=n;i++)
	{
		v[i] += v[i-1];
	}

	int dif = -inf;
	for(int i=1;i<=n;i++)
	{
		if(d[i] == 2)
			dif = max(dif, v[i-1]);
	}
	
	if(dif == -inf)
	{
		cout << "Infinity\n";
		return 0;
	}	

	dif = 1899 - dif;

	for(int i=0;i<=n;i++)
		v[i]+=dif;

	for(int i=1;i<=n;i++)
	{
		if(d[i] == 1 && v[i-1] <= 1899)
		{
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << v[n] << '\n';

	return 0;
}