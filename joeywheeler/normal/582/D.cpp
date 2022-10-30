#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())



using namespace std;

typedef vector<int> lnum;

const int base = 1000*1000*1000;

lnum rd(char *s) {
	lnum a;
	for (int i=(int)strlen(s); i>0; i-=9) {
		s[i] = 0;
		a.push_back (atoi (i>=9 ? s+i-9 : s));
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
	return a;
}

pair<lnum,int> div(lnum a, int b) {
	int carry = 0;
	for (int i=(int)a.size()-1; i>=0; --i) {
		long long cur = a[i] + carry * 1ll * base;
		a[i] = int (cur / b);
		carry = int (cur % b);
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
	return make_pair(a,carry);
}

typedef long long ll;

ll p, a;
char S[3500];
int b[3500];
int n;

void check(vector<int> x, int vl) {
	ll pw = 1;
	for (int y : x) {
		vl -= pw * y;
		pw *= p;
		assert(0 <= y && y < p);
	}
	assert(vl == 0);
}

ll ff(ll x) {
	if (x < 0) return 0;
	return ((x+2)*(x+1))/2;
}

ll f(ll x) {
	return ff(x) - 2*ff(x-p) + ff(x-2*p);
}

int cache[3500][2][2][3500];
ll MOD = 1000000007ll;
ll MOD2 = MOD*MOD;

ll dp(int i, int c, int s, int nc) {
	if (nc < 0) nc = 0;
	if (i == n) return s == 0 && nc == 0 && c == 0;
	if (cache[i][c][s][nc] != -1) return cache[i][c][s][nc];
	ll res = 0;

	int v = b[i];
	// anything
	ll z = p*p;
	// a+b <= p+v-c
	ll h = f(p+v-c);
	// a+b < p+v-c
	ll j = f(p+v-c-1);
	// a+b < p-c
	ll x = f(p-c-1);
	// a+b <= v-c
	ll y = f(v-c);
	// a+b < v-c
	ll g = f(v-c-1);

	z = z-h;
	h = h-j;
	j = j-x;
	x = x-y;
	y = y-g;

	//printf("%lld\n", z+h+j+x+y+g);

	z %= MOD;
	h %= MOD;
	j %= MOD;
	x %= MOD;
	y %= MOD;
    g %= MOD;

	res += z * dp(i+1, 1, 1, nc-1);
    if (res >= MOD2) res -= MOD2;
	res += h * dp(i+1, 1, s, nc-1);
    if (res >= MOD2) res -= MOD2;
	res += j * dp(i+1, 1, 0, nc-1);
    if (res >= MOD2) res -= MOD2;
	res += x * dp(i+1, 0, 1, nc);
    if (res >= MOD2) res -= MOD2;
	res += y * dp(i+1, 0, s, nc);
    if (res >= MOD2) res -= MOD2;
	res += g * dp(i+1, 0, 0, nc);

    res %= MOD;

	return cache[i][c][s][nc] = res;
}

int main() {
	scanf("%lld%lld", &p, &a);
	scanf("%s", S);
	lnum x = rd(S);
	while (sz(x) > 1 || x[0]) {
		pair<lnum,int> rs = div(x,p);
		b[n] = rs.second;
		x = rs.first;
		n++;
	}
	memset(cache,-1,sizeof cache);
	if (a > n) printf("0\n");
	else {
		printf("%lld\n", dp(0,0,0,a));
		//printf("%lld\n", dp(0,0,0,0));
	}
}