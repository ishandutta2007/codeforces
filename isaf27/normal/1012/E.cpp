#include <bits/stdc++.h>

using namespace std;

const int M = 2e5 + 239;

int n, s, a[M], p[M];
pair<int, int> b[M];

int parent[M], r[M];

inline void init()
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		r[i] = 0;
	}
}
	
inline int find_set(int p)
{
	if (parent[p] == p) return p;
	return (parent[p] = find_set(parent[p]));
}

inline void merge_set(int i, int j)
{
	i = find_set(i);
	j = find_set(j);
	if (i == j) return;
	if (r[i] > r[j]) swap(i, j);
	if (r[i] == r[j]) r[j]++;
	parent[i] = j;
}

inline bool is_connect(int i, int j)
{
	return (find_set(i) == find_set(j));
}

int t;
bool used[M];
vector<int> c[M];

void dfs(int x)
{                         
	used[x] = true;
	c[t].push_back(x);
	if (!used[p[x]]) dfs(p[x]);	
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = make_pair(a[i], i);
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++) p[b[i].second] = i;
	for (int i = 0; i < n; i++)
		if (a[i] == b[i].first && p[i] != i)
		{                                  
			p[b[i].second] = p[i];
			b[p[i]].second = b[i].second;
			p[i] = i;
			b[i].second = i;
		}              
	init();
	for (int i = 0; i < n; i++) merge_set(p[i], i);
	int ls = -1;
	for (int i = 0; i < n; i++)
	{
		if (p[b[i].second] == b[i].second) continue;
		if (ls >= 0 && a[ls] == a[b[i].second])
		{
			int x = ls;
			int y = b[i].second;
			if (is_connect(x, y)) continue;
			merge_set(x, y);
			swap(p[x], p[y]);		
		}
		ls = b[i].second;
	}
	t = 0;
	for (int i = 0; i < n; i++)
		if (!used[i] && p[i] != i)
		{
			dfs(i);
			t++;
		}    
	int kol = 0;
	for (int i = 0; i < t; i++)
		kol += (int)c[i].size();
	if (kol > s)
	{
		cout << "-1";
		return 0;
	}
	s -= kol; 
	s = min(s, t);
	if (s <= 1)
	{
		cout << t << "\n";
		for (int i = 0; i < t; i++)
		{
			cout << c[i].size() << "\n";
			for (int x : c[i])
				cout << (x + 1) << " ";
			cout << "\n";
		}
		return 0;
	}
	cout << (t - s + 2) << "\n";
	for (int i = 0; i < t - s; i++)
	{
		cout << c[i + s].size() << "\n";
		for (int x : c[i + s])
			cout << (x + 1) << " ";
		cout << "\n";
		kol -= (int)c[i + s].size();		
	}   
	cout << kol << "\n";
	for (int i = 0; i < s; i++)
		for (int x : c[i])
			cout << (x + 1) << " "; 
	cout << "\n";
	cout << s << "\n";
	for (int i = s - 1; i >= 0; i--)
		cout << (c[i][0] + 1) << " ";
	cout << "\n";
	return 0;
}