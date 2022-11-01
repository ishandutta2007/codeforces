#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> pii;
#define se second
#define fi first
#define mp make_pair

map<string, int > a;

pair<string, int> get(string s)
{
	int c1 = 0, c2=0;
	forn(i, s.length())
		if (s[i] == '&') c1++;
		else if (s[i] == '*') c2++;
	return mp(s.substr(c1, s.length()-c1-c2), c2-c1);
};

int main()
{
	//freopen("input.txt", "r" ,stdin);
	a["void"] = 0;
	a["errtype"] = -1;
	int n;
	string s1, s2, t;
	cin >> n;
	forn(i, n)
	{
		cin >> t >> s1;
		pair<string, int> q = get(s1);
		if (t == "typeof")
		{
			if (!a.count(q.fi) || a[q.fi] == -1 || a[q.fi] + q.se < 0)
				cout << "errtype\n";
			else
			{
				cout << "void";
				for (int i = a[q.fi] + q.se; i; i--) cout << "*";
				cout << endl;
			}
		}
		else
		{
			cin >> s2;
			pair<string, int> t = get(s1);
			if (!a.count(t.fi) || a[t.fi] == -1 || a[t.fi] + t.se < 0)
				a[s2] = -1;
			else
				a[s2] = a[t.fi] + t.se;
		}
	}
};