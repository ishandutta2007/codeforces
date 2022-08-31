//	Codeforces Beta Round #13
//	Problem D

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
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() {
	int x = 0, c;
	for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; }
	do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
	return x;
}

struct Pt {
	Int x, y;
	Pt() {}
	Pt(Int x, Int y) : x(x), y(y) {}
	Pt operator-(const Pt &a) {
		return Pt(x - a.x, y - a.y);
	}
	Pt operator*(const Int &k) {
		return Pt(x * k, y * k);
	}
	Int det(const Pt &a) const {
		return x * a.y - a.x * y;
	}
	bool operator<(const Pt &a) const {
		return (x != a.x) ? (x < a.x) : (y < a.y);
	}
};
Int tri(Pt a, Pt b, Pt c) {
	return (b - a).det(c - a);
}
bool cmp(const pair<Pt,int> &a, const pair<Pt,int> &b) {
	return (a.first.det(b.first) > 0);
}

int N, M, L;
pair<Pt,int> P[1010], Q[1010];

int main() {
	int i, j, k;
	int ans = 0;
	Pt R;
	
	N = in();
	M = N + in();
	for (i = 0; i < M; ++i) {
		P[i].first.x = in();
		P[i].first.y = in();
		P[i].second = (i < N);
	}
	sort(P, P + M);
	for (i = 0; i < M; ++i) if (P[i].second) {
		L = 0;
		for (j = i + 1; j < M; ++j) {
			Q[L++] = mp(P[j].first - P[i].first, P[j].second);
		}
		sort(Q, Q + L, cmp);
//for(j=0;j<L;++j)printf("(%lld,%lld)%s ",Q[j].first.x,Q[j].first.y,Q[j].second?"*":" ");cout<<endl;
		for (j = 0; j < L; ++j) if (Q[j].second) {
			R = Q[j].first * 2;
			for (k = j + 1; k < L; ++k) {
				if (Q[k].second) {
					if (tri(Q[j].first, Q[k].first, R) < 0) {
						++ans;
					}
				} else {
					if (tri(Q[j].first, R, Q[k].first) > 0) {
						R = Q[k].first;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}