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
const int maxn = 5050;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define all(x) (x).begin(), (x).end()
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;
typedef double ld;
const ld eps = 1e-12;
#define le(x, y) ((x)<(y)+eps)
#define eq(x, y) (abs((x)-(y))<eps)
#define lt(x, y) ((x)<(y)-eps)
const int mod = 1e9+7;
int madd (int x, int y) {return (x+y)%mod;}

int d[maxn];
int dp[maxn];
string s, t;
int n, m;

int main()
{
	cin >> s >> t;
	n = s.length(), m = t.length();
	
	int res = 0;
	forn(i, n)
	{		
		forn(j, m)
			if (s[i] == t[j]) d[j] = madd(1, j ? dp[j-1] : 0);
			else d[j] = 0;
		forn(j, m)
			dp[j] = madd(j ? dp[j-1] : 0, d[j]);
		res = madd(res, dp[m-1]);
	}
	
	cout << res << endl;
	
	return 0;
}