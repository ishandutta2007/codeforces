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

ll n, k;
int l, m;

struct Mat {
	int v[2][2];
	Mat() {memset(v, 0, sizeof(v));}
	Mat operator * (const Mat& c) const {
		Mat ans;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					ans.v[i][j] = (ans.v[i][j] + 1ll * v[i][k] * c.v[k][j] % m) % m;
				}
			}
		}
		return ans;
	}
};

Mat pow_mod(Mat x, ll k) {
	Mat ans;
	ans.v[0][0] = ans.v[1][1] = 1;
	while (k) {
		if (k&1) ans = ans * x;
		x = x * x;
		k >>= 1;
	}
	return ans;
}

int pow_mod(int x, ll k) {
	int ans = 1;
	while (k) {
		if (k&1) ans = 1ll * ans * x % m;
		x = 1ll * x * x % m;
		k >>= 1;
	}
	return ans;
}

//f0 = 1, f1 = 2, f2 = 3, f3 = 5

int main() {
	scanf("%lld%lld%d%d", &n, &k, &l, &m);
	int ans = 1;
	for (int i = l; i < 63; i++) {
		if (k>>i&1) {
			printf("0\n");
			return 0;
		}
	}
	for (int i = 0; i < l; i++) {
		Mat A; A.v[0][0] = A.v[0][1] = A.v[1][0] = 1;
		A = pow_mod(A, n);
		int tmp[2];
		tmp[0] = (A.v[0][0] + A.v[0][1]) % m;
		tmp[1] = (pow_mod(2, n) - tmp[0] + m) % m;
		ans = 1ll * ans * tmp[k>>i&1] % m;
	}
	printf("%d\n", ans % m);
	return 0;
}