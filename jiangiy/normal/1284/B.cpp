#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define xx first
#define yy second

typedef long long ll;

const int N = 200005;

int n, ma[N], mi[N];
pair<int, int> s[N];

int main() {
	scanf("%d", &n);
	ll ans = 0;
	int t = 0;
	for (int i = 1; i <= n; i++) {
		int l;
		scanf("%d", &l);
		mi[i] = 1e9;
		bool flag = 0;
		for (int j = 0; j < l; j++) {
			int x; scanf("%d", &x);
			if (x > mi[i]) flag = 1;
			mi[i] = min(mi[i], x);
			ma[i] = max(ma[i], x);
		}
		if (!flag) {
			t++;
			s[t * 2] = mp(mi[i], 1);
			s[t * 2 - 1] = mp(ma[i], 0);
		}
		//ans -= mi[i] != ma[i];
	}
	ans += (ll)n * n - (ll)t * t;
	std::sort(s + 1, s + t * 2 + 1);
	int c = 0;
	for (int i = t * 2; i; i--) {
		if (s[i].yy) ans += c;
		else c++;
		//printf("%d %d %d %d %d\n",i,s[i].xx,s[i].yy,(int)ans,c);
	}
	printf("%lld\n", ans);
}