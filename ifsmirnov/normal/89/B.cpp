#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <map>
using namespace std;
const int maxn = 110;
const int inf = 1e9+100500;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<ll, ll> pii;

enum{norm, hbox, vbox};

#define index fskfjdskfh
map<string, int> index;

int n = 0;
string name[maxn];
int t[maxn];
ll w[maxn], h[maxn];
ll border[maxn], spacing[maxn];
vector<int> kids[maxn];

pii get(int);

int main()
{
	//freopen("input.txt", "r", stdin);
	
	forn(i, maxn) w[i] = h[i] = -1;
	
	int m;
	string s;
	cin >> m;
	forn(i, m)
	{
		cin >> s;
		if (s[0] == 'W')
		{
			cin >> s;
			string nm = s.substr(0, s.find("("));
			int a = s.find("("), b = s.find(","), c = s.find(")");
			int W = atoi(s.substr(a+1, b-a-1).c_str()), H = atoi(s.substr(b+1, c-b-1).c_str());
			t[n] = norm;
			name[n] = nm;
			index[nm] = n;
			w[n] = W, h[n] = H;
			n++;
		}
		else if (s == "HBox")
		{
			cin >> name[n];
			index[name[n]] = n;
			t[n] = hbox;
			n++;
		}
		else if (s == "VBox")
		{
			cin >> name[n];
			index[name[n]] = n;
			t[n] = vbox;
			n++;
		}
		else
		{
			int a = s.find(".");
			int i = index[s.substr(0, a)];
			s = s.substr(a+1, s.length()-a-1);
			if (s[0] == 'p')
			{
				//pack
				//cout << s.substr(5, s.length()-6) << endl;
				int j = index[s.substr(5, s.length()-6)];
				kids[i].pb(j);
				//cout << "push " << name[i] << " " << name[j] << endl;
			}
			else
			{
				int c = s.find("("), d = s.find(")");
				int x = atoi(s.substr(c+1, d-c-1).c_str());
				if (s[4] == 'b') border[i] = x;
				else spacing[i] = x;
			}
		}
	}
	vector<pair<string, pii> > a;
	forn(i, n)
		a.pb(mp(name[i], get(i)));
	sort(a.begin(), a.end());
	forn(i, n)
		cout << a[i].fi << " " << a[i].se.fi << " " << a[i].se.se << endl;
	
	return 0;
};

pii get (int x)
{
	if (w[x] == -1)
	{
		ll wi, hi;
		if (kids[x].empty()) w[x] = h[x] = 0;
		else if (t[x] == hbox)
		{
			wi = hi = 0;
			forn(i, kids[x].size())
			{
				pii t = get(kids[x][i]);
				wi += t.fi;
				hi = max(hi, t.se);
			}
			w[x] = wi + 2*border[x] + spacing[x] * (kids[x].size()-1);
			h[x] = hi + 2*border[x];
		}
		else if (t[x] == vbox)
		{
			wi = hi = 0;
			forn(i, kids[x].size())
			{
				pii t = get(kids[x][i]);
				hi += t.se;
				wi = max(wi, t.fi);
			}
			w[x] = wi + 2*border[x];
			h[x] = hi + 2*border[x] + spacing[x] * (kids[x].size()-1); 
		}
	}
	return mp(w[x], h[x]);
};