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

const int N = 105;
const int mod = 1e9+7;

void pp(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int n;
ll a[N];
ll k;

struct Mat {
	int v[N][N];
	Mat() {memset(v, 0, sizeof(v));}
	Mat operator * (const Mat& c) const {
		Mat ans;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					pp(ans.v[i][j], 1ll * v[i][k] * c.v[k][j] % mod);
		return ans;
	}
};

Mat pow_mod(Mat x, ll k) {
	Mat ans;
	for (int i = 0; i < n; i++) ans.v[i][i] = 1;
	while (k) {
		if (k&1) ans = ans * x;
		x = x * x;
		k >>= 1;
	}
	return ans;
}

int main() {
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	Mat A;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (__builtin_popcountll(a[i]^a[j]) % 3 == 0) {
				A.v[i][j] = 1;
			}
		}
	}
	A = pow_mod(A, k - 1);
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			pp(ans, A.v[i][j]);
	printf("%d\n", ans);
	return 0;
}