#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
char s[N];
bool use[N];
int suf[N];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = n; i >= 1; i --)
		suf[i] = suf[i + 1] + (s[i] == ')');
	bool tag = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = i + 1; j <= n; j ++) {
			tag |= s[i] == '(' && s[j] == ')';
		}
	}
	if(!tag) {
		puts("0"); return 0;
	}
	int c = 0;
	for(int i = 1; i <= n; i ++) if(s[i] == '(') {
		c ++;
		if(suf[i + 1] < c) {
			c --;
			break ;
		}
	}
	int t = c;
	for(int i = n; i >= 1; i --) if(s[i] == ')') {
		if(t >= 1) {
			t --; use[i] = 1;
		} else break ;
	}
	t = c;
	for(int i = 1; i <= n; i ++) if(s[i] == '(') {
		if(t >= 1) {
			use[i] = 1;
			t --;
		} else break ;
	}
	int dd = 0;
	for(int i = 1; i <= n; i ++) dd += use[i];
	printf("1\n%d\n", dd);
	for(int i = 1; i <= n; i ++) if(use[i]) printf("%d ", i);
	return 0;
}