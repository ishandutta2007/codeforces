#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int maxn = 100500;
typedef pair<int, int> pii;
typedef long long i64;

int n, k;
string s;
int curl = 0;
string curs = "";

vector<int> pos, npos;
int addSymb(char c, bool force = 0)
{
	//returns amt of substrs starting with curs+c
	if (curl == 0)
	{
		int res = 0;
		forn(i, n) if (s[i] == c)
		{
			if (force)
				pos.pb(i);
			if (res < 200000) res += n-i;
		}
		if (force)
		{
			curl ++;
			curs += c;
		}
		return res;
	}
	else
	{
		if (force)
			npos.clear();
		int res = 0;
		forn(I, pos.size())
		{
			int i = pos[I];
			if (i + curl >= n) continue;
			if (s[i+curl] == c)
			{
				if (res < 200000) res += n-(i+curl);
				if (force)
					npos.pb(i);
			}
		}
		if (force)
		{
			pos = npos;
			curl++;
			curs += c;
		}
		return res;
	}
}

void scan()
{
	cin >> s >> k;
	k--;
	n = s.length();
}
void solve()
{
	if ((i64) n * (n+1) / 2 <= k)
	{
		cout << "No such line.";
		return;
	}
	
	while (1)
	{
		for (char c = 'a'; c <= 'z'; c++)
		{
			int t = addSymb(c);
			if (t <= k)
				k -= t;
			else
			{
				//cout << "Added " << c << endl;
				//cout << "k = " << k << endl;
				addSymb(c, 1);
				break;
			}
		}
		if (k < (int)pos.size())
		{
			cout << curs << endl;
			return;
		}
		else
			k -= (int)pos.size();
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scan();
	solve();
	
	return 0;
}