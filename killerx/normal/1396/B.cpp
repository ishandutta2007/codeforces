#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int t;
	scanf("%d", &t);
	while (t --) {
		int n;
		scanf("%d", &n);
		vector <int> a(n);
		int mx = 0, sm = 0;
		rep(i, n) scanf("%d", &a[i]), mx = max(mx, a[i]), sm += a[i];
		if (sm - mx < mx || sm & 1) puts("T");
		else puts("HL");
	}
	return 0;
}