#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxn = 1 << 20;
const int inf = 1e9;
const double pi = acos(-1.0);

struct complex {
        double x, y;
 
        complex() {}
        complex(double x, double y) : x(x), y(y) {}
 
        complex operator+ (const complex &c) const {
                return complex(x + c.x, y + c.y);
        }
 
        complex operator- (const complex &c) const {
                return complex(x - c.x, y - c.y);
        }
 
        complex operator* (const complex &c) const {
                return complex(x * c.x - y * c.y, x * c.y + y * c.x);
        }
 
        complex operator/ (double d) const {
                return complex(x / d, y / d);
        }
};
 
int rev(int x, int lg) {
        int res = 0;
        for (int i = 0; i < lg; i++) if (x & (1 << i)) res |= 1 << (lg - i - 1);
        return res;
}
 
void fft(complex *a, int n, bool inv) {
        int lg = 0;
        while ((1 << lg) < n) lg++;
 
        for (int i = 0; i < n; i++) {
                int j = rev(i, lg);
                if (i < j) {
                        swap(a[i], a[j]);
                }
        }
 
        for (int len = 1; len < n; len <<= 1) {
                double angle = pi / len;
                if (inv) angle = -angle;
                complex w0(cos(angle), sin(angle));
                for (int i = 0; i < n; i += 2 * len) {
                        complex w(1, 0);
                        for (int j = 0; j < len; j++) {
                                complex u = a[i + j], v = a[i + j + len] * w;
                                a[i + j] = u + v;
                                a[i + j + len] = u - v;
                                w = w * w0;
                        }
                }
        }
        if (inv) {
                for (int i = 0; i < n; i++) {
                        a[i] = a[i] / n;
                }
        }
}
 
const int T = 4e6 + 10;
 
complex a[T], b[T];
 
vector<int > mul(vector<int > _a, vector<int > _b) {
        int n = 1;
        while (n < (int)max(_a.size(), _b.size())) n *= 2;
        n *= 2;
 
        for (int i = 0; i < n; i++) {
                if (i < (int)_a.size()) a[i] = complex(_a[i], 0);
                else a[i] = complex(0, 0);
 
                if (i < (int)_b.size()) b[i] = complex(_b[i], 0);
                else b[i] = complex(0, 0);
        }
 
        fft(a, n, 0);
        fft(b, n, 0);
        for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
        fft(a, n, 1);
 
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
                res[i] = (int)(a[i].x + 0.5);
        }
        return res;
}

int n, m, k;
char s[maxn], t[maxn];
int cnt[maxn];

void solve(char c) {
	vector<int> a;
	for (int i = 0; i < m; i++) a.push_back(t[i] == c);
	while (a.size() < n) a.push_back(0);
	reverse(a.begin(), a.end());
	while (a.size() < 2 * n) a.push_back(0);

	int last = -1;
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == c) {
			for (int j = max(last + 1, i - k); j <= min(i + k, n - 1); j++) {
				b[j] = 1;
			}
			last = i + k;
		}
	}
	for (int i = 0; i < n; i++) b.push_back(b[i]);

	vector<int> cc = mul(a, b);

	for (int i = n - 1; i <= 2 * n - 2; i++) {
		//cout << cc[i] << " ";
		cnt[i - (n - 1)] += cc[i];
	}
	//cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d%d\n", &n, &m, &k) == 3) {
		gets(s);
		gets(t);
		for (int i = 0; i < n; i++) cnt[i] = 0;
		solve('A');
		solve('C');
		solve('G');
		solve('T');
		int ans = 0;
		for (int i = 0; i <= n - m; i++) {
			ans += cnt[i] == m;
		}
		printf("%d\n", ans);
	}

	return 0;
}