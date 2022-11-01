#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef unsigned long long u64;
typedef double ld;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define unq(x) {sort(all(x));(x).resize(unique(all(x))-(x).begin());}
#define lb lower_bound
const int inf = 1e9+100500;
const int maxn = 1050;

int n, m;
vector<pii> t, k;

int main()
{
	//freopen("input.txt", "r", stdin);
	
	cin >> n >> m;
	i64 s = 0;
	forn(i, n)
	{
		int a, b;
		cin >> a >> b;
		s += a;
		if (b == 1)
			t.pb(mp(a, i));
		else
			k.pb(mp(a, i));
	}
	sort(all(t), greater<pii>());
	sort(all(k), greater<pii>());
	//cout << s << endl;
	if ((int)t.size() < m)
	{
		i64 sk = 0;
		forn(i, t.size()) 
			sk += t[i].fi;
		s = s*2 - sk;
		cout << s/2 << (s%2?".5":".0") << endl;
		forn(i, t.size())
		{
			cout << 1 << " " << t[i].se + 1 << endl;
		}
		forn(i, m-1-t.size())
		{
			cout << 1 << " " << k.back().se + 1 << endl;
			k.pop_back();
		}
		cout << k.size() << " ";
		forn(i, k.size()) cout << k[i].se + 1 << " ";
		cout << endl;
	}
	else
	{
		i64 sk = 0;
		forn(i, m-1)
			sk += t[i].fi;
		if (k.empty())
			sk += t.back().fi;
		else
			sk += min(t.back().fi, k.back().fi);
		s = s*2 - sk;
		cout << s/2 << (s%2?".5":".0") << endl;
		forn(i, m-1)
			cout << 1 << " " << t[i].se + 1 << endl;
		cout << n-m+1 << " ";
		for (int i = m-1; i < (int)t.size(); i++)
			cout << t[i].se + 1 <<  " ";
		forn(i, k.size())
			cout << k[i].se + 1 << " ";
		cout << endl;	
	}
	
	return 0;
}