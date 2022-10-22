#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, s;
int c[6];
int ans = 0x3f3f3f3f;
int ak3 = -1, ak4 = -1, ak5 = -1;

inline void chk(int k3, int k4, int k5) {
	int res = std::abs(c[3] * k3 - c[4] * k4) + std::abs(c[4] * k4 - c[5] * k5);
	if (res < ans) ans = res, ak3 = k3, ak4 = k4, ak5 = k5;
}

int main() {
	scanf("%d %d", &n, &s);
	rep(i, n) {
		int x;
		scanf("%d", &x);
		c[x] += 1;
	}
	for (int k3 = 0; c[3] * k3 <= s; ++ k3) {
		rep(r, c[5]) if (c[4] * r % c[5] == (s - c[3] * k3) % c[5]) {
			int e4L = k3 <= r ? 0 : (k3 - r + c[5] - 1) / c[5];
			if ((s - c[3] * k3) / c[4] - r < 0) continue;
			int e4R = ((s - c[3] * k3) / c[4] - r) / c[5];
			if (s - c[3] * k3 - (c[4] + c[5]) * r < 0) continue;
			e4R = std::min(e4R, (s - c[3] * k3 - (c[4] + c[5]) * r) / (c[5] * (c[5] + c[4])));
			if (e4L > e4R) continue;
			int b34 = -1;
			{
				int lb = e4L, rb = e4R + 1;
				while (lb < rb) {
					int md = (lb + rb) >> 1;
					int k4 = md * c[5] + r;
					if (c[3] * k3 <= c[4] * k4) rb = md;
					else lb = md + 1;
				}
				b34 = lb;
			}
			int b45 = -1;
			{
				int lb = e4L, rb = e4R + 1;
				while (lb < rb) {
					int md = (lb + rb) >> 1;
					int k4 = md * c[5] + r;
					int k5 = (s - c[3] * k3 - c[4] * k4) / c[5];
					if (c[5] * k5 <= c[4] * k4) rb = md;
					else lb = md + 1;
				}
				b45 = lb;
			}
			std::vector <int> vec;
			vec.push_back(e4L);
			vec.push_back(e4R + 1);
			vec.push_back(b34);
			vec.push_back(b45);
			std::sort(vec.begin(), vec.end());
			rep(i, vec.size() - 1) if (vec[i] != vec[i + 1]) {
				int k4 = vec[i] * c[5] + r;
				int k5 = (s - c[3] * k3 - c[4] * k4) / c[5];
				chk(k3, k4, k5);
				k4 = (vec[i + 1] - 1) * c[5] + r;
				k5 = (s - c[3] * k3 - c[4] * k4) / c[5];
				chk(k3, k4, k5);
			}
		}
	}
	if (~ak3) printf("%d %d %d\n", ak3, ak4, ak5);
	else printf("-1\n");
	return 0;
}