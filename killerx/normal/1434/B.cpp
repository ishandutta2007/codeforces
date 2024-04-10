#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
int n;
char tp[mxn];
int x[mxn];
int val[mxn];
int stk[mxn], top;
int cnt, id[mxn];

int main() {
	scanf("%d", &n);
	rep(i, n * 2) {
		char temp[5];
		scanf("%s", temp);
		tp[i] = temp[0];
		if (tp[i] == '+') {
			stk[top ++] = id[i] = cnt ++;
		} else {
			scanf("%d", &x[i]);
			if (!top) {
				puts("NO");
				return 0;
			}
			val[stk[-- top]] = x[i];
		}
	}
	set <int> nw;
	rep(i, n * 2) {
		if (tp[i] == '+') {
			nw.insert(val[id[i]]);
		} else {
			if (*nw.begin() != x[i]) {
				puts("NO");
				return 0;
			}
			nw.erase(nw.begin());
		}
	}
	puts("YES");
	rep(i, n) printf("%d%c", val[i], " \n"[i + 1 == n]);
	return 0;
}