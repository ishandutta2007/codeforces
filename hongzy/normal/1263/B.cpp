#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 1e5 + 10;
int a[12], b[12], pw[10] = {1, 10, 100, 1000};
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		int n; scanf("%d", &n);
		static int st[10002], use[10002];
		fill(use, use + 10002, 0);
		fill(st, st + 10002, 0);
		for(int i = 0; i < n; i ++) {
			scanf("%d", a + i); st[a[i]] ++;
		}
		int c = 0;
		for(int i = 0; i < n; i ++) {
			if(!use[a[i]]) use[b[i] = a[i]] = 1;
			else {
				c ++;
				for(int j = 0; j < 10; j ++) {
					int x = a[i] / 10 * 10 + j;
					if(!st[x] && !use[x]) {
						b[i] = x; break ;
					}
				}
				use[b[i]] = 1;
			}
			st[a[i]] --;
		}
		printf("%d\n", c);
		for(int i = 0; i < n; i ++) printf("%04d\n", b[i]);
	}
	return 0;
}