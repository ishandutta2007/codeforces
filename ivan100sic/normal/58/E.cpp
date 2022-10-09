// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string a, b, c;

struct korak {
	int i, j, k, carry;
	int p, q, r;
};

int d[9][9][9][2], A, B, C;
korak step[9][9][9][2];

template<class F>
void mn(int& x, int y, F f) {
	if (y < x) {
		x = y;
		f();
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	memset(d, 63, sizeof(d));
	memset(step, 255, sizeof(step));
	d[0][0][0][0] = 0;

	string s;
	cin >> s;

	int pp = s.find('+');
	int ee = s.find('=');

	a = s.substr(0, pp);
	b = s.substr(pp+1, ee-pp-1);
	c = s.substr(ee+1);

	auto sredi = [](string& a, int& A) {
		reverse(begin(a), end(a));
		for (char& x : a)
			x -= '0';
		A = a.size();
	};

	sredi(a, A);
	sredi(b, B);
	sredi(c, C);

	for (int i=0; i<=A+1; i++) {
		for (int j=0; j<=B+1; j++) {
			for (int k=0; k<=C+1; k++) {
				for (int carry=0; carry<=1; carry++) {

					// stavi cifru
					for (int p=-1; p<=9; p++) {
						for (int q=-1; q<=9; q++) {
							for (int r=-1; r<=9; r++) {

								int diff = max(p, 0) + max(q, 0) - max(r, 0) + carry;

								int carry2 = 0;
								if (diff == 0) {
									//
								} else if (diff == 10) {
									carry2 = 1;
								} else {
									continue;
								}

								int cost = 0, ii = i, jj = j, kk = k, cont = 0;

								auto proc = [&](int i, int& ii, int A, string& a, int p) {
									if (i == A+1) { // implicitna nula stavljena, moze samo to
										if (p != -1) {
											cont = 1;
										}
									} else if (i == A) {
										if (p == -1) {
											ii++;
										} else {
											cost++;
										}
									} else if (a[i] == p) {
										ii++;
									} else if (p == -1) {
										cont = 1;
									} else {
										cost++;
									}
								};

								proc(i, ii, A, a, p);
								proc(j, jj, B, b, q);
								proc(k, kk, C, c, r);

								if (!cont) {
									mn(d[ii][jj][kk][carry2], d[i][j][k][carry] + cost, [&]() {
										step[ii][jj][kk][carry2] = {i, j, k, carry, p, q, r};
									});
								}
							}
						}
					}
				}
			}
		}
	}

	int ii = A+1, jj = B+1, kk = C+1, carry2 = 0;

	vector<tuple<int, int, int>> resenje;

	while (1) {
		auto [i, j, k, carry, p, q, r] = step[ii][jj][kk][carry2];
		if (i == -1) {
			break;
		}

		resenje.push_back({p, q, r});
		ii = i;
		jj = j;
		kk = k;
		carry2 = carry;
	}

	string aa, bb, cc;

	for (auto [x, y, z] : resenje) {
		if (x != -1) aa += char(x+48);
		if (y != -1) bb += char(y+48);
		if (z != -1) cc += char(z+48);
	}

	cout << aa << "+" << bb << "=" << cc << '\n';
}