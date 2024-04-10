#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 100500;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
typedef pair<int, int> pii;
typedef long long i64;

int n;
map<string, int> score;

void scan()
{
	cin >> n;
	string s;
	int x;
	forn(i, n)
	{
		cin >> s >> x;
		score[s] = max(score[s], x);
	}
}

void solve()
{
	vector<pair<string, int> > a(score.begin(), score.end());
	
	cout << a.size() << endl;
	forn(i, a.size())
	{
		int cur = a[i].se;
		int gt = 0;
		forn(j, a.size()) if (a[j].se > cur) ++gt;
		gt *= 100;
		int n = a.size();
		//cout << a[i].fi << " " << gt / n << endl;
		cout << a[i].fi << " ";
		if (gt > 50*n)
			cout << "noob";
		else if (gt > 20*n)
			cout << "random";
		else if (gt > 10*n)
			cout << "average";
		else if (gt > 1*n)
			cout << "hardcore";
		else
			cout << "pro";
		cout << endl;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	
	scan();
	solve();
	
	return 0;
}