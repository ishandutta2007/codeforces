#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 200500;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double ld;
const int inf = 1e9+100500;
const ld eps = 1e-9;
typedef long long i64;

int n;
char s[maxn];

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%s", s);
	n = strlen(s);
	
	int cnt1 = count(s, s+n, '1');
	int cnt0 = count(s, s+n, '0');
	int cntv = n-cnt1-cnt0;
	
	vector<string> res;
	
	int kill0 = n/2-1;
	int kill1 = (n+1)/2-1;
	
	if (cnt0 <= kill0)
		res.pb("11");
	
	if (cnt1 <= kill1)
		res.pb("00");
	
	int add0 = kill0-cnt0+1;
	int add1 = kill1-cnt1+1;
	
	if (add0 >= 0 && add1 >= 0 && add0+add1 == cntv)
	{
		if (s[n-1] == '1' || (s[n-1] == '?' && add1 > 0))
			res.pb("01");
		if (s[n-1] == '0' || (s[n-1] == '?' && add0 > 0))
			res.pb("10");
	}
	
	sort(all(res));
	forn(i, res.size()) cout << res[i] << endl;
	
	
}