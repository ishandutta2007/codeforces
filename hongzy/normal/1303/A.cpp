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
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 1e5 + 10;
const int mo = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mo)
		if(b & 1) ans = (ll) ans * a % mo;
	return ans;
}

int main() {
	int t; scanf("%d", &t);
	while(t --) {
		static char s[N];
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		static bool l[N], r[N];
		bool t = 0;
		for(int i = 1; i <= n; i ++) {
			if(s[i] == '1') t = 1;
			l[i] = t;
		}
		t = 0;
		for(int i = n; i >= 1; i --) {
			if(s[i] == '1') t = 1;
			r[i] = t;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i ++) {
			if(s[i] == '0' && l[i] && r[i]) {
				cnt ++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}