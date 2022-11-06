#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

typedef long long llong;

const double pi = 4.0 * atan(1.0);
struct complex {
	double r, i;
	complex operator+(const complex &x) {
		return{ r + x.r, i + x.i };
	}
	complex operator-(const complex &x) {
		return{ r - x.r, i - x.i };
	}
	complex operator*(const complex &x) {
		return { r * x.r - i * x.i, r * x.i + i * x.r };
	}
};

int bitRev(int x, int n) {
	int ans = 0;
	while (n >>= 1) {
		ans <<= 1;
		ans += (x & 1);
		x >>= 1;
	}
	return ans;
}

void FFT(vector<complex> &x, bool rev = false) {
	int n = x.size();
	int tmp;
	for (int i = 0; i < n; ++i) {
		tmp = bitRev(i, n);
		if (tmp <= i) continue;
		swap(x[tmp], x[i]);
	}
	double exp;
	for (int i = 2; i <= n; i <<= 1) {
		exp = 2 * pi / i;
		if (rev) exp = -exp;
		complex w = { cos(exp), sin(exp) };
		for (int j = 0; j < n; j += i) {
			complex wi = { 1.0, 0.0 };
			for (int k = j; k < j + i / 2; ++k) {
				complex t1 = x[k];
				complex t2 = wi * x[k + i / 2];
				x[k] = t1 + t2; x[k + i / 2] = t1 - t2;
				wi = wi * w;
			}
		}
	}
	if (rev) {
		for (int i = 0; i < n; ++i) {
			x[i].r /= n; x[i].i /= n;
		}
	}
}

void multiple(vector<complex> &a, vector<complex> &b) {
	int n = 1;
	while (n < a.size() * 2) n <<= 1;
    a.resize(n);
    b.resize(n);
    FFT(a);
    FFT(b);
	for (int i = 0; i < n; ++i) {
        a[i] = a[i] * b[i];
	}
	FFT(a, true);
}

const int MAXN = 2e5 + 7;
int n, x;
int a[MAXN];
int sum[MAXN];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x;
	for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] < x) a[i] = 1;
        else a[i] = 0;
        sum[i] = sum[i - 1] + a[i];
	}
	vector<complex> vt1(n + 1, {0.0, 0.0});
	vector<complex> vt2(n + 1, {0.0, 0.0});
	for (int i = 0; i <= n; ++i) {
        vt1[sum[i]].r += 1;
        vt2[n - sum[i]].r += 1;
	}
	multiple(vt1, vt2);
	printf("%lld ", llround(vt1[n].r - n) / 2);
	for (int i = 1; i <= n; ++i) {
        printf("%lld ", llround(vt1[n + i].r));
	}
	return 0;
}