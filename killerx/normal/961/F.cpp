#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

std::random_device rd;
std::mt19937 rng(rd());

int rand(int l, int r) {
	return std::uniform_int_distribution <int> (l, r)(rng);
}

bool isprime(int x) {
	for (int i = 2; i * i <= x; ++ i) {
		if (x % i == 0) return false;
	}
	return true;
}

int randp(int l, int r) {
	int x = 0;
	while (!isprime(x = rand(l, r)));
	return x;
}

int moda = randp(1e7, 1e9), modb = randp(1e7, 1e9);

struct Hash {
	int a, b;

	Hash(): a(), b() {}
	Hash(int x): a(x), b(x) {}
	Hash(int _a, int _b): a(_a), b(_b) {}

	Hash operator + (const Hash &oth) const { return Hash((a + oth.a) % moda, (b + oth.b) % modb); }
	Hash operator - (const Hash &oth) const { return Hash((a + moda - oth.a) % moda, (b + modb - oth.b) % modb); }
	Hash operator * (const Hash &oth) const { return Hash(1LL * a * oth.a % moda, 1LL * b * oth.b % modb); }

	bool operator == (const Hash &oth) const { return a == oth.a && b == oth.b; }
};

Hash mul = 233;

const int mxn = 1e6 + 5;
int n;
char s[mxn];
int res[mxn];

Hash pw[mxn], pre[mxn];

Hash get_hash(int l, int r) {
	return pre[r] - pre[l] * pw[r - l];
}

int main() {
	rep(i, mxn) pw[i] = i ? pw[i - 1] * mul : Hash(1);
	scanf("%d", &n);
	scanf("%s", s);
	rep(i, n) pre[i + 1] = pre[i] * mul + Hash(s[i]);
	int h = -1;
	for (int i = (n - 1) / 2; i >= 0; -- i) {
		for (h += 2; h >= 0 && (h >= (n - i) - i || !(get_hash(i, i + h) == get_hash(n - i - h, n - i))); h -= 2);
		res[i] = h;
	}
	for (int i = 0; i <= (n - 1) / 2; ++ i) printf("%d ", res[i]);
	printf("\n");
	return 0;
}