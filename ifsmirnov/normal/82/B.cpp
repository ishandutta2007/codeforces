#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++) 
#define pb push_back
const int maxn = 210;

vector<int> a[maxn]; //where lies
bool b[maxn];
vector<int> s[maxn*maxn]; //sets

int n;
void scan();
void solve();

int main()
{
	//freopen("input.txt", "r", stdin);
	ios :: sync_with_stdio(false);
	scan();
	solve();
	return 0;
};

void scan()
{
	cin >> n;
	forn(i, n*(n-1)/2)
	{
		int k;
		cin >> k;
		s[i].resize(k);
		forn(j, k)
		{
			cin >> s[i][j];
			a[s[i][j]].pb(i);
		}
	}
};
void solve()
{
	if (n == 2)
	{
		cout << 1 << " " << s[0][0] << "\n";
		cout << s[0].size() - 1 << " ";forn(i, s[0].size()-1) cout << s[0][i+1] << " ";
		return;
	}
	set<int> t;
	vector<int> p;
	for (int i = 1; i <= 200; i++)
	{
		if (b[i] || a[i].empty()) continue;
		//cout << endl;
		//cout << i << endl;
		p.resize(0);
		t.clear();
		int a1 = a[i][0], a2 = a[i][1];
		//cout << "a1 = " << a1 << ", a2 = " << a2 << endl;
		forn(j, s[a1].size()) t.insert(s[a1][j]);
		forn(j, s[a2].size()) if (t.count(s[a2][j])) p.pb(s[a2][j]);
		cout << p.size() << " ";
		forn(j, p.size()) cout << p[j] << " ";
		cout << "\n";
		forn(j, p.size()) b[p[j]] = 1;
	}
};