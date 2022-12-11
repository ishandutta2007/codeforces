#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, c[27];
char s[N];
ll T;
int main(){
	scanf("%d%lld%s", &n, &T, s + 1);
	rep(i, 1, n) s[i] -= 'a';
	T = T - (1ll << s[n]) + (1ll << s[n - 1]);
	rep(i, 1, n - 2) {
		T += 1ll << s[i];
		c[s[i] + 1] ++;
	}
	per(i, 26, 1) {
		while(c[i] && (1ll << i) <= T) {
			c[i] --; T -= 1ll << i;
		}
	}
	puts(T == 0 ? "Yes" : "No");
	return 0;
}