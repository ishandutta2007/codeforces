#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k, a, f[200008], ans, m;
map<int, int> par, impar;
vector <int>add;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;

	for(int i=1;i<=n;i++)
	{
		cin >> f[i];
		a = f[i];
		if(a%2==1)
			impar[a];
		else par[a];
	}
	int req = n/2 - par.size();
	for(int i=2; i<=m; i+=2)
	{
		if(req <= 0)
			break;

		if(par.find(i) == par.end())
		{
			req--;
			ans++;
			par[i];
			add.push_back(i);
		}
	} 
	if(req > 0)
	{
		cout << -1 << '\n';
		return 0;
	}
	req = n/2 - impar.size();
	for(int i=1; i<=m; i+=2)
	{
		if(req <= 0)
			break;

		if(impar.find(i) == impar.end())
		{
			req--;
			ans++;
			impar[i];
			add.push_back(i);
		}
	}

	if(req > 0)
	{
		cout << -1 << '\n';
		return 0;
	}
	cout << ans << '\n';
	int nrp = 0;
	int nri = 0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]%2 == 0)
		{
			if(par[f[i]]!= -1 && nrp<n/2)
			cout << f[i] << ' ', par[f[i]] = -1, nrp++;
			else cout << add.back() << ' ', add.pop_back();
		}
		if(f[i]%2 == 1)
		{
			if(impar[f[i]]!= -1 && nri < n/2)
			cout << f[i] << ' ', impar[f[i]] = -1, nri++;
			else cout << add.back() << ' ', add.pop_back();
		}
	}

	cout << '\n';

	return 0;
}