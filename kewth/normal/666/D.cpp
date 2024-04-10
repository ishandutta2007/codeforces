#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

int calc(int *x, int *y, int *nx, int *ny, int *ansp) {
	int p[4] = {0, 1, 2, 3}, res = 1000000000;
	do {
		int now = 0;
		for(int i = 0; i < 4; i ++)
			if(x[i] == nx[p[i]])
				now = std::max(now, std::abs(y[i] - ny[p[i]]));
			else if(y[i] == ny[p[i]])
				now = std::max(now, std::abs(x[i] - nx[p[i]]));
			else
				now = 1000000000;
		if(now < res) {
			res = now;
			for(int i = 0; i < 4; i ++) ansp[i] = p[i];
		}
	} while(std::next_permutation(p, p + 4));
	return res;
}

int main() {
	const int _ = 20200202; // magic
	int T = read;

	while(T --) {
		int x[5], y[5];
		for(int i = 0; i < 4; i ++) {
			x[i] = read;
			y[i] = read;
		}
		x[4] = 1;
		y[4] = 0;

		int ans = 1000000000;

		int ansx[4], ansy[4];
		int nx[4], ny[4];

		auto update = [&]() {
			int p[4] = {0, 1, 2, 3};
			int tmp = calc(x, y, nx, ny, p);
#if 0
			debug(">>>  get %d\n", tmp);
			for(int i = 0; i < 4; i ++)
				debug("%d %d\n", nx[p[i]], ny[p[i]]);
#endif
			if(tmp < ans) {
				ans = tmp;
				if(x[4] == 1)
					for(int i = 0; i < 4; i ++) {
						ansx[i] = nx[p[i]];
						ansy[i] = ny[p[i]];
					}
				if(x[4] == 0)
					for(int i = 0; i < 4; i ++) {
						ansx[i] = ny[p[i]];
						ansy[i] = nx[p[i]];
					}
			}
		};

		for(int S = 0; S < 16; S ++) {
			int xx[4] = {_, _, _, _}, yy[4] = {_, _, _, _};
			for(int i = 0; i < 4; i ++) {
				int *tar = (S >> i & 1) == x[4] ? xx : yy;
				int v = (S >> i & 1) == x[4] ? x[i] : y[i];
				int j = 0;
				while(tar[j] != _ and tar[j] != v) ++ j;
				tar[j] = v;
			}

			if(xx[2] != _ or yy[2] != _) continue;
			if(xx[1] == _ and yy[1] == _) continue;

			if(yy[0] == _) {
				std::swap(xx, yy);
				std::swap(x, y);
			}

			if(xx[0] == _) {
				int d = std::abs(yy[0] - yy[1]);
				ny[0] = ny[2] = yy[0];
				ny[1] = ny[3] = yy[1];

				for(int T = 0; T < 4; T ++) {
					int shit[2] = {T >> 1, T & 1};
					int l = 1000000000, r = - 1000000000;
					for(int i = 0; i < 4; i ++) {
						int o = y[i] == yy[1];
						int v = shit[o] ? x[i] + d : x[i];
						shit[o] ^= 1;
						l = std::min(l, v);
						r = std::max(r, v);
					}

					// debug("fcuk %d %d %d\n", d, l, r);
					int mid = (l + r + 1) >> 1;
					nx[0] = nx[1] = mid;
					nx[2] = nx[3] = mid - d;
					update();
				}
				continue;
			}

			if(yy[1] == _) {
				std::swap(xx, yy);
				std::swap(x, y);
			}

			if(xx[1] == _) {
				int d = std::abs(yy[0] - yy[1]);
				nx[0] = nx[1] = xx[0];
				ny[0] = ny[2] = yy[0];
				ny[1] = ny[3] = yy[1];

				nx[2] = nx[3] = xx[0] - d;
				update();
				nx[2] = nx[3] = xx[0] + d;
				update();
				continue;
			}

			if(std::abs(xx[0] - xx[1]) == std::abs(yy[0] - yy[1])) {
				nx[0] = nx[1] = xx[0];
				nx[2] = nx[3] = xx[1];
				ny[0] = ny[2] = yy[0];
				ny[1] = ny[3] = yy[1];
				update();
			}
		}

		if(ans == 1000000000) puts("-1");
		else {
			printf("%d\n", ans);
			for(int i = 0; i < 4; i ++)
				printf("%d %d\n", ansx[i], ansy[i]);
		}
	}
}