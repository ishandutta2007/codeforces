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
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<typename T> void chmax(T &t, const T &f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

const int INF = 1001001001;

int N;
int A[300010];

bool brute() {
	for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) for (int k = j + 1; k < N; ++k) {
		if (A[i] + A[k] == A[j] + A[j]) {
			return true;
		}
	}
	return false;
}

pint minQ[300010], *minQB, *minQE;
pint maxQ[300010], *maxQB, *maxQE;

void init() {
	minQB = minQE = minQ;
	maxQB = maxQE = maxQ;
}
void push(int id, int val) {
	for (; minQE - minQB >= 1 && (minQE - 1)->first >= val; --minQE);
	*minQE++ = mp(val, id);
	for (; maxQE - maxQB >= 1 && (maxQE - 1)->first <= val; --maxQE);
	*maxQE++ = mp(val, id);
}
void pop(int id) {
	for (; minQE - minQB >= 1 && minQB->second <= id; ++minQB);
	for (; maxQE - maxQB >= 1 && maxQB->second <= id; ++maxQB);
}
int getMin() {
	if (minQE - minQB == 0) return +INF;
	return minQB->first;
}
int getMax() {
	if (maxQE - maxQB == 0) return -INF;
	return maxQB->first;
}

int B[300010];
int pos[300010];

int bsLen[2];
int bs[2][300010];

bool solve(int S, int T) {
	if (T - S <= 2) {
		return false;
	}
// cout<<"solve ";pv(B+S,B+T);
	const int n = T - S;
	for (int i = S; i < T; ++i) {
		pos[B[i]] = i;
	}
	
	int maxEven = n - 1;
	int maxOdd  = n - 1;
	for (; maxEven % 2 != 0; --maxEven);
	for (; maxOdd  % 2 == 0; --maxOdd );
	
	//	odd even odd
	{
		init();
		int l = 1, r = 1;
		for (int a = 0; a < n; a += 2) {
			const int width = min(a - 1, maxOdd - a);
			if (width > 0) {
				for (; r <= a + width; r += 2) {
					push(r, pos[r]);
				}
				for (; l <  a - width; l += 2) {
					pop(l);
				}
				if (getMin() < pos[a] && pos[a] < getMax()) {
					return true;
				}
			}
		}
	}
	
	//	even odd even
	{
		init();
		int l = 0, r = 0;
		for (int a = 1; a < n; a += 2) {
			const int width = min(a - 0, maxEven - a);
			if (width > 0) {
				for (; r <= a + width; r += 2) {
					push(r, pos[r]);
				}
				for (; l <  a - width; l += 2) {
					pop(l);
				}
				if (getMin() < pos[a] && pos[a] < getMax()) {
					return true;
				}
			}
		}
	}
	
	bsLen[0] = bsLen[1] = 0;
	for (int i = S; i < T; ++i) {
		bs[B[i] % 2][bsLen[B[i] % 2]++] = B[i] / 2;
	}
	const int U = S + bsLen[0];
	copy(bs[0], bs[0] + bsLen[0], B + S);
	copy(bs[1], bs[1] + bsLen[1], B + U);
	if (solve(S, U)) {
		return true;
	}
	if (solve(U, T)) {
		return true;
	}
	return false;
}

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
// cout<<"===="<<endl;
// cout<<"A : ";pv(A,A+N);
		for (int i = 0; i < N; ++i) {
			A[i] = in() - 1;
		}
		copy(A, A + N, B);
		const bool res = solve(0, N);
// cout<<(brute()?"yes":"no")<<" ";
		puts(res ? "YES" : "NO");
// if(brute()!=res){cerr<<"fail"<<endl;exit(0);}
	}
	
	return 0;
}