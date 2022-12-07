#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 100005;
int a, b, h, w, n;
int x[N];

vector<pair<ll, ll> > A, B;

void get(int l, int r, vector<pair<ll, ll> >& A) {
	if (l > r) {
		A.pb(mp(1, 1));
		return;
	}
	int len = r - l + 1;
	for (int i = 0; i < (1<<len); i++) {
		ll a1 = 1, a2 = 1;
		for (int j = l; j <= r; j++) {
			if (i>>(j - l)&1) a1 *= x[j];
			else a2 *= x[j];
		}
		A.pb(mp(a1, a2));
	}
}

ll mx[N * 10];

bool go() {
	for (int ti = 0; ti <= n; ti++) {
		A.clear(); B.clear();
		get(1, ti / 2, A); get(ti / 2 + 1, ti, B);
		sort(A.begin(), A.end()); sort(B.begin(), B.end());
		ll Max = 1;
		int j = sz(B) - 1;
		for (int i = 0; i < sz(A); i++) {
			while (j >= 0 && A[i].fi * h >= (a + B[j].fi - 1) / B[j].fi) Max = max(B[j--].se,Max);
			if(j != sz(B) - 1){
				if (A[i].se * w >= (b + Max - 1) / Max) {
					printf("%d\n", ti);
					return true;
				}
			}
		}
		j = sz(B) - 1;
		Max = 1;
		for (int i = 0; i < sz(A); i++) {
			while (j >= 0 && A[i].fi * w >= (a + B[j].fi - 1) / B[j].fi) Max = max(B[j--].se,Max);
			if(j != sz(B) - 1){
				if (A[i].se * h >= (b + Max - 1) / Max) {
					printf("%d\n", ti);
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	sort(x + 1, x + 1 + n); reverse(x + 1, x + 1 + n);
	if (go()) return 0; 
	printf("-1\n");
	return 0;
}