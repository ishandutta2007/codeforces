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

const int N = 1e6 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n;
char s[N]; 
int main() {
	scanf("%d%s", &n, s + 1);
	int x = 0;
	for(int i = 1; i <= n; i ++) x += s[i] == '(';
	if(x != n - x) {
		puts("-1");
		return 0;
	}
	int ans = 0, sum = 0, pos = -1;
	for(int i = 1; i <= n; i ++) {
		if(s[i] == '(') {
			sum ++;
			if(sum == 0 && ~ pos) {
				ans += i - pos + 1; 
				pos = -1;
			}
		} else {
			sum --;
			if(-1 == pos && sum < 0) {
				pos = i;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}