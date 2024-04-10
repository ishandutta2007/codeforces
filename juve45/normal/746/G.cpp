#include <bits/stdc++.h>
#define x first
#define y second
#define DMAX 200010
#define dbg(x) //cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k, t, a[DMAX], kmin, kmax;
vector <int> lst[DMAX], v[DMAX];

void add(int a, int b)
{
	v[a].push_back(b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> t >> k;
	for(int i=1;i<=t;i++)
	{
		cin >> a[i];
	}
	a[t+1]=0;
	for(int i=1;i<=t;i++)
	{
		if(a[i] > a[i+1])
			kmin+=a[i]-a[i+1];		
		kmax += a[i]-1;
	}
	kmax++;

	if(k < kmin || k > kmax)
	{
		cout << -1 << '\n';
		return 0;
	}
	lst[0].push_back(1);
	int nc = 2;
	for(int i=1;i<=t;i++)
	{
		dbg(lst[i-1].size());
		lst[i].push_back(nc);
		add(lst[i-1][0], nc++);
		int in = 1;
		for(int j=2;j<=a[i];j++)
		{
			lst[i].push_back(nc);
			dbg(kmax);
			dbg(k);
			if(kmax > k && in<lst[i-1].size())
				add(lst[i-1][in++], nc++), kmax--;
			else add(lst[i-1][0], nc++);

		}
	}

	cout << n <<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout << i << ' ' << v[i][j] << '\n';

		}
	}
	return 0;
}