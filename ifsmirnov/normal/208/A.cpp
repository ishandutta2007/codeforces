#include <iostream>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
typedef vector<int> vi;
typedef pair<int, int> pii;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef long long i64;
const int inf = 1e9+100500;
const int maxn = 100500;

int main()
{
	string s;
	cin >> s;
	s = "WUB" + s + "WUBWUB";
	vector<string> res;
	string cur = "";
	forn(i, s.length() - 3)
	{
		if (s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B')
		{
			if (cur != "")
				res.pb(cur);
			cur = "";
			i += 2;
		}
		else
			cur += s[i];
	}
	forn(i, res.size())
		cout << res[i] << " ";
	cout << endl;
	
	return 0;
}