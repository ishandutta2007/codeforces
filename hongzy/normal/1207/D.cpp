#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 3e5 + 10;
const int mo = 998244353;

int n, ans1, ans2, ans3, fac[N];
pii a[N];
bool cmp1(pii x, pii y) { return x < y; }
bool cmp2(pii x, pii y) { return mp(x.sc, x.fs) < mp(y.sc, y.fs); }

int main() {
	ucin();
	cin >> n;
	for(int i = 1; i <= n; i ++) 
		cin >> a[i].fs >> a[i].sc;
	fac[0] = 1;
	for(int i = 1; i <= n; i ++)
		fac[i] = 1ll * fac[i - 1] * i % mo;
		
	sort(a + 1, a + n + 1, cmp1);
	ans1 = 1;
	int sz = 0;
	for(int i = 1; i <= n; i ++) {
		if(i > 1 && a[i].fs == a[i - 1].fs) sz ++;
		else {
			ans1 = 1ll * ans1 * fac[sz] % mo;
			sz = 1;
		}
	}
	if(sz) ans1 = 1ll * ans1 * fac[sz] % mo;
	
	sort(a + 1, a + n + 1, cmp2);
	
	ans2 = 1;
	sz = 0;
	for(int i = 1; i <= n; i ++) {
		if(i > 1 && a[i].sc == a[i - 1].sc) sz ++;
		else {
			ans2 = 1ll * ans2 * fac[sz] % mo;
			sz = 1;
		}
	}
	if(sz) ans2 = 1ll * ans2 * fac[sz] % mo;
	
	sort(a + 1, a + n + 1, cmp1);
	ans3 = 1;
	for(int i = 2; i <= n; i ++)
		if(a[i].fs < a[i - 1].fs || a[i].sc < a[i - 1].sc) ans3 = 0;
	sz = 0;
	for(int i = 1; i <= n; i ++) {
		if(i > 1 && a[i] == a[i - 1]) sz ++;
		else {
			ans3 = 1ll * ans3 * fac[sz] % mo;
			sz = 1;
		}
	}
	if(sz) ans3 = 1ll * ans3 * fac[sz] % mo;
	
	ans1 = ((1ll * fac[n] - (ans1 + ans2 - ans3)) % mo + mo) % mo;
	cout << ans1 << endl;
	return 0;
}