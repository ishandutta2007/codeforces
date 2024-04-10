#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <bitset>
#include <memory.h>
using namespace std;

const int MAXM = 20;
int bitcount[1 << MAXM];
int coof[MAXM + 1][MAXM + 1][MAXM + 1];
int mod, m;
long long t;

typedef long long ll;

vector<int> mulB(const vector<int>& left, const vector<int>& right) {
	vector<int> result(m + 1);
	for (int i = 0; i <= m; ++i) {
		ll res = 0;
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k <= m; ++k) {
				ll val = coof[i][j][k];
				val *= left[j];
				val %= mod;
				val *= right[k];
				val %= mod;
				res += val;
			}
		}
		result[i] = res % mod;
	}
	return result;
}

vector<int> pow(vector<int> v, long long pow) {
	vector<int> result(m + 1);
	result[0] = 1;
	while (pow != 0) {
		if (pow % 2 == 1) {
			result = mulB(result, v);
		}
		v = mulB(v, v);
		pow /= 2;
	}
	return result;
}

void precalc() {
	for (int i = 0; i < (1<<m); ++i) {
		bitcount[i] = bitset<20>(i).count();
	}
	memset(coof, 0, sizeof(coof));
	for (int i = 0; i <= m; ++i) {
		int qq = (1<<i) - 1;
		for (int j = 0; j < (1<<m); ++j) {
			++coof[i][bitcount[j]][bitcount[j ^ qq]];
		}
	}
}

void safeAdd(int &left, int right) {
	left += right;
	if (left >= mod)
		left -= mod;
}

void transform(const int* ar, size_t len, vector<int> *out) {
	if (len == 1) {
		out[0].assign(m + 1, 0);
		out[0][0] = ar[0] % mod;
	} else {
		transform(ar, len / 2, out);
		transform(ar + len / 2, len / 2, out + len/2);
		for (size_t i = 0; i < len / 2; ++i) {
			for (int j = m; j >= 0; --j) {
				if (j != m) {
					safeAdd(out[i + len/2][j+1], out[i][j]);
					safeAdd(out[i][j + 1], out[i + len/2][j]);
				}
			}
		}
	}
}

int main(void) {
	scanf("%d%I64d%d", &m, &t, &mod);
	precalc();
	int n = 1<<m;
	vector<int> e0(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &e0[i]);
	}
	vector<int> b(m + 1);
	for (int i = 0; i <= m; ++i) {
		scanf("%d", &b[i]);
	}
	b = pow(b, t);

	// stupid
	/*vector<int> et(n);
	for (int i = 0; i < n; ++i) {
		long long q = 0;
		for (int j = 0; j < n; ++j) {
			q += ll(e0[j]) * b[bitcount[j ^ i]] % mod;
		}
		et[i] = q % mod;
		printf("%d\n", et[i]);
	}*/

	vector<vector<int>> res(n);
	transform(e0.data(), e0.size(), res.data());
	for (int i = 0; i < n; ++i) {
		ll out = 0;
		for (int j = 0; j<= m; ++j) {
			out += ll(b[j]) * res[i][j];
			out %= mod;
		}
		printf("%d\n", int(out));
	}
}