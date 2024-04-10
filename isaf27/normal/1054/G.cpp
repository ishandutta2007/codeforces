#include <bits/stdc++.h>

using namespace std;

const int BIG = 1e9 + 239;
const int M = 2010;

int n, m, kol[M], id[M][M];
vector<int> v[M];
bitset<M> a[M]; 
string s;
bool used[M], need[M];
vector<pair<int, int> > ans;          

inline void upd(int s, int f)
{
	used[s] = false;
	for (int i = 0; i < n; i++)
		if (used[i])
		{
			if (id[s][i] == -1) continue;
			int bk = (int)v[i].back();
			id[bk][i] = id[s][i];
			v[i][id[s][i]] = bk;
			v[i].pop_back();
			id[s][i] = -1;
		}
	for (int i = 0; i < m; i++)
		if (a[s][i])
			kol[i]--;
	bool ch = false;
	for (int i = 0; i < m; i++)
		if (kol[i] < 2 && a[f][i] == 1)
			a[f][i] = 0, ch = true;
	if (ch)
	{
		for (int i = 0; i < n; i++) need[i] = true;
		for (int i : v[f]) need[i] = false;
		for (int i = 0; i < n; i++)
			if (need[i] && used[i] && i != f && ((a[f] & a[i]) == a[f]))
			{
				id[i][f] = (int)v[f].size();
				v[f].push_back(i);	
			}
	}	
}

inline void solve()
{        
	ans.clear();                             
	cin >> n >> m;  
	for (int i = 0; i < n; i++) v[i].clear();
	for (int i = 0; i < n; i++) a[i] = 0;
	for (int i = 0; i < m; i++) kol[i] = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		for (int x = 0; x < n; x++)  
		{
			a[x][i] = (s[x] - '0');	
			if (s[x] == '1') kol[i]++;
		}				
	}            
	for (int i = 0; i < m; i++)
		if (kol[i] < 2)
			for (int x = 0; x < n; x++)
				a[x][i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			id[i][j] = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
				if ((a[i] & a[j]) == a[i]) 
				{
					id[j][i] = (int)v[i].size();
					v[i].push_back(j);
				}
	for (int i = 0; i < n; i++) used[i] = true;
	for (int iter = 0; iter < n - 1; iter++)
	{
		int s = -1;
		for (int i = 0; i < n; i++)
			if (used[i] && !v[i].empty())
			{
				s = i;
				break;
			}
		if (s == -1)
		{
			cout << "NO\n";
			return;	
		}
		int f = v[s].back();
		ans.push_back(make_pair(s, f));
		upd(s, f);
	}
	cout << "YES\n";
	for (pair<int, int> t : ans)
		cout << (t.first + 1) << " " << (t.second + 1) << "\n";		
}

int main()
{
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) solve();	
	return 0;
}