#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 150;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> pii;
const int inf = 1e9+100500;
typedef long long i64;

int l[maxn][maxn][2], r[maxn][maxn][2];
int n, k;
string s;

void rmx (int &a, int b) {a = max(a, b);}
void rmn (int &a, int b) {a = min(a, b);}

void solve()
{
	//1 - look left, 0 - look right
	forn(i, maxn) forn(j, maxn) forn(t, 2) l[i][j][t] = inf, r[i][j][t] = -inf;
	l[0][0][1] = r[0][0][1] = 0;
	forn(i, n+1) forn(j, k+1) forn(t, 2)
	{
		if (l[i][j][t] == inf) continue;
		//printf("l[%d][%d][%d] = %d\n", i, j, t, l[i][j][t]);
		//printf("r[%d][%d][%d] = %d\n", i, j, t, r[i][j][t]);
		if (s[i] == 'F')
		{
			for (int d = 0; j + d <= k+1; d += 2)
			{
				rmx(r[i+1][j+d+1][!t], r[i][j][t]), rmn(l[i+1][j+d+1][!t], l[i][j][t]);
				rmx(r[i+1][j+d][t], r[i][j][t] + (t ? 1 : -1)), rmn(l[i+1][j+d][t], l[i][j][t] + (t ? 1 : -1));
			}
		}
		else
		{
			for (int d = 0; j + d <= k+1; d += 2)
			{
				rmx(r[i+1][j+d][!t], r[i][j][t]), rmn(l[i+1][j+d][!t], l[i][j][t]);
				rmx(r[i+1][j+d+1][t], r[i][j][t] + (t ? 1 : -1)), rmn(l[i+1][j+d+1][t], l[i][j][t] + (t ? 1 : -1));
			}
		}
	}
}
int mmax (int a, int b) {if (a == inf) return b; if (b == inf) return a; return max(a, b);}
int main()
{
	//freopen("input.txt", "r", stdin);
	
	getline(cin, s);
	cin >> k;
	n = s.length();
	
	solve();
	
	int mx = 0;
	forn(i, 2) mx = mmax(mx, mmax(abs(l[n][k][i]), abs(r[n][k][i])));
	
	cout << mx << endl;
	
	return 0;
}