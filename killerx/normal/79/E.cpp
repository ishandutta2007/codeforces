#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;

int n, a, b, c;
i64 T;

inline int dist(int x0, int y0, int x1, int y1) {
	return std::abs(x0 - x1) + std::abs(y0 - y1);
};

inline i64 sum(int S, int E, int d) {
	assert((E - S) / d >= 0);
	return 1LL * ((E - S) / d) * (S + E + d) / 2;
};

int main() {
	scanf("%d %lld %d %d %d", &n, &T, &a, &b, &c);
	-- a, -- b;
	const int Ax = a, Ay = b + c - 1;
	const int Bx = a + c - 1, By = b + c - 1;
	const int Cx = a, Cy = b;
	const int Dx = a + c - 1, Dy = b;
/*
   A  B

   C  D
*/
	std::function <bool(int, int, int, int, i64, i64, i64, i64, int, int, int, int)> go;
	std::function <bool(int, int, i64, i64, i64, i64)> can;
	go = [&] (int x, int y, int nx, int ny, i64 A, i64 B, i64 C, i64 D, int dA, int dB, int dC, int dD) -> bool {
		i64 nA = A - sum(dist(x, y, Ax, Ay), dist(nx, ny, Ax, Ay), dA);
		i64 nB = B - sum(dist(x, y, Bx, By), dist(nx, ny, Bx, By), dB);
		i64 nC = C - sum(dist(x, y, Cx, Cy), dist(nx, ny, Cx, Cy), dC);
		i64 nD = D - sum(dist(x, y, Dx, Dy), dist(nx, ny, Dx, Dy), dD);
		return can(nx, ny, nA, nB, nC, nD);
	};
	can = [&] (int x, int y, i64 A, i64 B, i64 C, i64 D) -> bool {
		// eprintf("%d %d %lld %lld %lld %lld\n", x, y, A, B, C, D);
		if (A < 0 || B < 0 || C < 0 || D < 0) return false;
		if (x == n - 1 && y == n - 1) return true;
		if (x >= Bx && y >= By) return go(x, y, n - 1, n - 1, A, B, C, D, +1, +1, +1, +1);
		if (Cx <= x && Cy <= y && x <= Bx && y <= By) {
			i64 nARU = A - sum(dist(x, y, Ax, Ay), dist(Bx, y, Ax, Ay), +1) - sum(dist(Bx, y, Ax, Ay), dist(Bx, By, Ax, Ay), -1);
			i64 nBRU = B - sum(dist(x, y, Bx, By), dist(Bx, y, Bx, By), -1) - sum(dist(Bx, y, Bx, By), dist(Bx, By, Bx, By), -1);
			i64 nCRU = C - sum(dist(x, y, Cx, Cy), dist(Bx, y, Cx, Cy), +1) - sum(dist(Bx, y, Cx, Cy), dist(Bx, By, Cx, Cy), +1);
			i64 nDRU = D - sum(dist(x, y, Dx, Dy), dist(Bx, y, Dx, Dy), -1) - sum(dist(Bx, y, Dx, Dy), dist(Bx, By, Dx, Dy), +1);
			i64 nAUR = A - sum(dist(x, y, Ax, Ay), dist(x, By, Ax, Ay), -1) - sum(dist(x, By, Ax, Ay), dist(Bx, By, Ax, Ay), +1);
			i64 nBUR = B - sum(dist(x, y, Bx, By), dist(x, By, Bx, By), -1) - sum(dist(x, By, Bx, By), dist(Bx, By, Bx, By), -1);
			i64 nCUR = C - sum(dist(x, y, Cx, Cy), dist(x, By, Cx, Cy), +1) - sum(dist(x, By, Cx, Cy), dist(Bx, By, Cx, Cy), +1);
			i64 nDUR = D - sum(dist(x, y, Dx, Dy), dist(x, By, Dx, Dy), +1) - sum(dist(x, By, Dx, Dy), dist(Bx, By, Dx, Dy), -1);
			assert(nBRU == nBUR && nCRU == nCUR);
			if (nBRU < sum(dist(Bx, By, Bx, By), dist(n - 1, n - 1, Bx, By), +1)) return false;
			if (nCRU < sum(dist(Bx, By, Cx, Cy), dist(n - 1, n - 1, Cx, Cy), +1)) return false;
			assert(std::abs(nARU - nAUR) % 2 == 0);
			assert(std::abs(nARU - nAUR) == std::abs(nDRU - nDUR));
			i64 Anw = sum(dist(Bx, By, Ax, Ay), dist(n - 1, n - 1, Ax, Ay), +1);
			i64 Dnw = sum(dist(Bx, By, Dx, Dy), dist(n - 1, n - 1, Dx, Dy), +1);
			i64 LA = 0, RA = std::abs(nARU - nAUR);
			i64 LD = 0, RD = std::abs(nDRU - nDUR);
			LA = std::max(LA, Anw - std::min(nARU, nAUR));
			RD = std::min(RD, std::max(nDRU, nDUR) - Dnw);
			i64 L = std::max(LA, LD);
			i64 R = std::min(RA, RD);
			while (L % 2 != 0) ++ L;
			while (R % 2 != 0) -- R;
			return L <= R;
		}
		if (x <= Cx && y <= Cy) return go(x, y, Cx, Cy, A, B, C, D, -1, -1, -1, -1);
		if (x < Cx) return go(x, y, Cx, y, A, B, C, D, -1, -1, -1, -1);
		if (y < Cy) return go(x, y, x, Cy, A, B, C, D, -1, -1, -1, -1);
		if (x > Bx) return go(x, y, x, By, A, B, C, D, -1, -1, +1, +1);
		if (y > By) return go(x, y, Bx, y, A, B, C, D, +1, -1, +1, -1);
		assert(false);
	};
	i64 A = T, B = T, C = T, D = T;
	int x = 0, y = 0;
	if (!can(x, y, A, B, C, D)) {
		puts("Impossible");
		return 0;
	}
	auto chk = [&] (int x, int y) {
		return can(x, y, A - dist(x, y, Ax, Ay), B - dist(x, y, Bx, By), C - dist(x, y, Cx, Cy), D - dist(x, y, Dx, Dy));
	};
	rep(i, (n - 1) * 2) {
		if (x + 1 < n && chk(x + 1, y)) putchar('R'), ++ x;
		else if (y + 1 < n && chk(x, y + 1)) putchar('U'), ++ y;
		else eprintf("no way!\n"), assert(false);
		A -= dist(x, y, Ax, Ay);
		B -= dist(x, y, Bx, By);
		C -= dist(x, y, Cx, Cy);
		D -= dist(x, y, Dx, Dy);
	}
	puts("");
	// eprintf("%lld %lld %lld %lld\n", A, B, C, D);
	return 0;
}