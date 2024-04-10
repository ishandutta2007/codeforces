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

const Int INF = 1001001001001001001LL;

int N;
Int A[100010];
Int ASum[100010];
pair<Int,Int> ps[100010];

bool cmpY(const pair<Int,Int> &a, const pair<Int,Int> &b) {
	return ((a.second != b.second) ? (a.second < b.second) : (a.first < b.first));
}

inline Int dist(const pair<Int,Int> &a, const pair<Int,Int> &b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

Int ans;

int asLen, bsLen;
pair<Int,Int> as[100010], bs[100010];

void solve(int S, int T) {
	if (T - S <= 4) {
		for (int i = S; i < T; ++i) for (int j = i + 1; j < T; ++j) {
			chmin(ans, dist(ps[i], ps[j]));
		}
		sort(ps + S, ps + T, cmpY);
		return;
	}
	const int U = (S + T) / 2;
	const Int xMid = ps[U].first;
	solve(S, U);
	solve(U, T);
	const Int r = (Int)sqrt(ans) + 5;
	asLen = bsLen = 0;
	for (int i = S; i < U; ++i) if (xMid - r <= ps[i].first) as[asLen++] = ps[i];
	for (int j = U; j < T; ++j) if (ps[j].first <= xMid + r) bs[bsLen++] = ps[j];
// cout<<xMid<<" "<<r<<endl;
// cout<<"as : ";for(int i=0;i<asLen;++i)cout<<"("<<as[i].first<<", "<<as[i].second<<") ";cout<<endl;
// cout<<"bs : ";for(int j=0;j<bsLen;++j)cout<<"("<<bs[j].first<<", "<<bs[j].second<<") ";cout<<endl;
	for (int i = 0, j0 = 0, j1 = 0; i < asLen; ++i) {
		for (; j0 < bsLen && bs[j0].second <  as[i].second - r; ++j0);
		for (; j1 < bsLen && bs[j1].second <= as[i].second + r; ++j1);
		for (int j = j0; j < j1; ++j) {
			chmin(ans, dist(as[i], bs[j]));
		}
	}
	inplace_merge(ps + S, ps + U, ps + T, cmpY);
}

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int i = 0; i < N; ++i) {
			A[i] = in();
		}
		partial_sum(A, A + N, ASum + 1);
		for (int i = 0; i <= N; ++i) {
			ps[i] = mp(i, ASum[i]);
		}
// cout<<"ps : ";for(int i=0;i<=N;++i)cout<<"("<<ps[i].first<<", "<<ps[i].second<<") ";cout<<endl;
		ans = INF;
		solve(1, N + 1);
		cout << ans << endl;
	}
	
	return 0;
}