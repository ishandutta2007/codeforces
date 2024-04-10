#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

int n, k;

vector <pair<int, int>> v;
int sol[300008];

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> k;
		v.push_back({k, i});
	}

	sort(v.begin(), v.end());
	int c = v[0].x;
	sol[v[0].y] = c;
	for(int i=1;i<v.size();i++)
	{
		c = max(c+1, v[i].x);
		sol[v[i].y] = c;
	}

	for(int i=1;i<=n;i++)
		cout << sol[i] << ' ';

	return 0;
}