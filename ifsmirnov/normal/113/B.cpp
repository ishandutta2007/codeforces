#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <string>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define se second
#define fi first
#define pb push_back
#define mp make_pair
const int maxn = 2050;
typedef long long ll;
ll base = 10099;

string s, b, e;
ll h[maxn], hb, he;
ll p[maxn];

void buildHash()
{
	p[0] = 1;
	for (int i = 1; i < maxn; i++)
		p[i] = p[i-1] * base;
	h[0] = s[0];
	for (int i = 1; i < (int)s.length(); i++)
		h[i] = h[i-1] * base + s[i];
	
	hb = 0;
	forn(i, b.size())
		hb = hb * base + b[i];
	he = 0;
	forn(i, e.size())
		he = he * base + e[i];
}
ll getHash (int l, int r)
{
	ll curh = h[r];
	if (l != 0)
		curh -= h[l-1] * p[r-l+1];
	return curh;
}

int htsz = 10, htn = 0;
vector<ll> ht(htsz, -1);
void addht (ll a)
{
	if (htn * 2 > htsz)
	{
		htsz *= 2;
		htn = 0;
		vector<ll> t(ht);
		ht.assign(htsz, -1);
		forn(i, htsz/2)
			if (t[i] != -1)
				addht(t[i]);
	}
	int i = abs(a) % htsz;
	while (ht[i] != -1 && ht[i] != a)
		i = (i+1) % htsz;
	if (ht[i] == -1)
		ht[i] = a, htn++;
	
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> s >> b >> e;
	buildHash();
	
	int n = s.length();
	for (int i = 0; i < n; i++)
		for (int j = i + max(b.length(), e.length()) - 1; j < n; j++)
			if (getHash(i, i + b.length() - 1) == hb && getHash(j - e.length() + 1, j) == he)
				addht(getHash(i, j));
	cout << htn << endl;
	return 0;
}