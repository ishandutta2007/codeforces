#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 2e5 + 10;
const int mo = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}
int n, x[N], ans[N];
char s[N];
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		scanf("%d%s", &n, s + 2);
		int l = 1, r = n;
		for(int i = 2; i <= n; ) {
			int j = i;
			for(; j < n && s[j + 1] == s[i]; j ++) ;
			if(s[i] == '<') {
				for(int k = j; k >= i; k --) x[k] = r --;
				if(i == 2) x[1] = r --;
				else {
					int t = x[i - 1];
					for(int k = i; k <= j; k ++) x[k - 1] = x[k];
					x[j] = t;
				}
			} else {
				if(i == 2) x[1] = r --;
				for(int k = i; k <= j; k ++) x[k] = r --;
			}
			i = j + 1; 
		}
		for(int i = 1; i <= n; i ++) printf("%d%c", x[i], " \n"[i == n]);
		
		x[1] = 1; l = 1, r = 1; int mp = 1;
		for(int i = 2; i <= n; i ++) {
			if(s[i] == '<') x[i] = ++ r;
			else x[i] = -- l;
			mp = min(mp, x[i]);
		}
		if(mp != 1) { for(int i = 1; i <= n; i ++) x[i] -= mp - 1; }
		for(int i = 1; i <= n; i ++) printf("%d%c", x[i], " \n"[i == n]);
	}
	return 0;
}