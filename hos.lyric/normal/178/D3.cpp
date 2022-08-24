#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int N, NN;
int A[20];
int S;
int B[20][20];

bool check() {
	int x, y, z;
	for (x = 0; x < N; ++x) {
		int sum = 0;
		for (y = 0; y < N; ++y) sum += B[x][y];
		if (sum != S) return 0;
	}
	for (y = 0; y < N; ++y) {
		int sum = 0;
		for (x = 0; x < N; ++x) sum += B[x][y];
		if (sum != S) return 0;
	}
	for (z = 0; z < 2; ++z) {
		int sum = 0;
		for (x = 0; x < N; ++x) sum += B[x][z ? (N - 1 - x) : x];
		if (sum != S) return 0;
	}
	return 1;
}

int f[20] = {};
int get(int a) {
	int i = lower_bound(A, A + NN, a) - A;
	for (; i < NN && f[i]; ++i);
	return (i < NN && A[i] == a && !f[i]) ? i : -1;
}

void solve4() {
	int i00, i01, i02, i03;
	int i10, i11, i12, i13;
	int i20, i21, i22, i23;
	int i30, i31, i32, i33;
	memset(f, 0, sizeof(f));
	for (i00 = 0; i00 < NN; ++i00) 
	for (i03 = i00 + 1; i03 < NN; ++i03) 
	for (i30 = i03 + 1; i30 < NN; ++i30) 
	{
		++f[i00]; ++f[i03]; ++f[i30];
		for (i01 = 0; i01 < NN; ++i01) if (!f[i01]) {
			++f[i01];
			i02 = get(S - A[i00] - A[i01] - A[i03]);
			if (~i02) {
				++f[i02];
				for (i10 = 0; i10 < NN; ++i10) if (!f[i10]) {
					++f[i10];
					i20 = get(S - A[i00] - A[i10] - A[i30]);
					if (~i20) {
						++f[i20];
						--f[i20];
						for (i12 = 0; i12 < NN; ++i12) if (!f[i12]) {
							++f[i12];
							i21 = get(S - A[i03] - A[i12] - A[i30]);
							if (~i21) {
								++f[i21];
								for (i11 = 0; i11 < NN; ++i11) if (!f[i11]) {
									++f[i11];
									i13 = get(S - A[i10] - A[i11] - A[i12]);
									if (~i13) {
										++f[i13];
										i31 = get(S - A[i01] - A[i11] - A[i21]);
										if (~i31) {
											++f[i31];
											for (i22 = 0; i22 < NN; ++i22) if (!f[i22]) {
												++f[i22];
												i23 = get(S - A[i20] - A[i21] - A[i22]);
												if (~i23) {
													++f[i23];
													i32 = get(S - A[i02] - A[i12] - A[i22]);
													if (~i32) {
														++f[i32];
														i33 = get(S - A[i00] - A[i11] - A[i22]);
														if (~i33) {
															if (S == A[i30] + A[i31] + A[i32] + A[i33]) 
															if (S == A[i03] + A[i13] + A[i23] + A[i33]) 
															{
																B[0][0] = A[i00]; B[0][1] = A[i01]; B[0][2] = A[i02]; B[0][3] = A[i03]; 
																B[1][0] = A[i10]; B[1][1] = A[i11]; B[1][2] = A[i12]; B[1][3] = A[i13]; 
																B[2][0] = A[i20]; B[2][1] = A[i21]; B[2][2] = A[i22]; B[2][3] = A[i23]; 
																B[3][0] = A[i30]; B[3][1] = A[i31]; B[3][2] = A[i32]; B[3][3] = A[i33]; 
																return;
															}
														}
														--f[i32];
													}
													--f[i23];
												}
												--f[i22];
											}
											--f[i31];
										}
										--f[i13];
									}
									--f[i11];
								}
								--f[i21];
							}
							--f[i12];
						}
					}
					--f[i10];
				}
				--f[i02];
			}
			--f[i01];
		}
		--f[i00]; --f[i03]; --f[i30];
	}
}

int main() {
	int i;
	int x, y;
	
	for (; ~scanf("%d", &N); ) {
		NN = N * N;
		for (i = 0; i < NN; ++i) {
			A[i] = in();
		}
		sort(A, A + NN);
		S = accumulate(A, A + NN, 0) / N;
		if (N <= 3) {
			do {
				for (x = 0; x < N; ++x) for (y = 0; y < N; ++y) {
					B[x][y] = A[x * N + y];
				}
				if (check()) {
					break;
				}
			} while (next_permutation(A, A + NN));
		} else {
			solve4();
		}
assert(check());
		printf("%d\n", S);
		for (x = 0; x < N; ++x) {
			for (y = 0; y < N; ++y) {
				if (y) printf(" ");
				printf("%d", B[x][y]);
			}
			puts("");
		}
	}
	
	return 0;
}