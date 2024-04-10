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
const int LIM = 100005;

const int bitN = 1 << 17;

void bitAdd(Int bit[], int pos, Int val) {
	for (int x = pos; x <= bitN; x += x & -x) {
		bit[x] += val;
	}
}
Int bitSum(Int bit[], int pos) {
	Int ret = 0;
	for (int x = pos; x > 0; x &= x - 1) {
		ret += bit[x];
	}
	return ret;
}
int bitLowerBound(Int bit[], Int val) {
	if (val <= 0) return 0; 
	int x = 0;
	for (int k = bitN; k > 0; k /= 2) { 
		if (x + k <= bitN && bit[x + k] < val) { 
			val -= bit[x + k]; 
			x += k; 
		} 
	} 
	return x + 1; 
}

Int bitCnt[bitN + 10];
Int bitVal[bitN + 10];

int N;
int A[100010];
Int B[100010];

pair<Int,int> bs[100010];
int ids[100010];
vector<pair<Int,int>> is[100010];
int sz[100010];
vint events[100010];

int main() {
	
	
	for (; ~scanf("%d", &N); ) {
		for (int i = 0; i < N; ++i) {
			A[i] = in();
			B[i] = in();
		}
		
		int me = 0;
		for (int u = 0; u < LIM; ++u) {
			is[u].clear();
		}
		for (int j = 0; j <= N; ++j) {
			events[j].clear();
		}
		
		for (int i = 0; i < N; ++i) {
			bs[i] = mp(B[i], i);
		}
		sort(bs, bs + N);
		for (int i = 0; i < N; ++i) {
			ids[bs[i].second] = i + 1;
		}
		for (int i = 0; i < N; ++i) {
			if (A[i] == 0) {
				++me;
			} else {
				is[A[i]].emplace_back(B[i], i);
			}
		}
		for (int u = 1; u < LIM; ++u) {
			sort(is[u].begin(), is[u].end(), greater<pint>());
			sz[u] = is[u].size();
			for (int j = 0; j < sz[u]; ++j) {
				events[j + 1].push_back(is[u][j].second);
			}
		}
// for(int j=0;j<=N;++j){cout<<"events["<<j<<"] : ";pv(events[j].begin(),events[j].end());}cout<<endl;
		
		fill(bitCnt, bitCnt + bitN + 1, 0);
		fill(bitVal, bitVal + bitN + 1, 0);
		for (int i = 0; i < N; ++i) {
			if (A[i] != 0) {
				bitAdd(bitCnt, ids[i], +1);
				bitAdd(bitVal, ids[i], +B[i]);
			}
		}
		
		Int ans = INF;
		Int must = 0;
		for (int j = N; j >= me; --j) {
// cout<<"j = "<<j<<endl;
			for (const int i : events[j]) {
				must += B[i];
				++me;
				bitAdd(bitCnt, ids[i], -1);
				bitAdd(bitVal, ids[i], -B[i]);
			}
			const int pos = bitLowerBound(bitCnt, j - me);
// cout<<"must = "<<must<<", pos = "<<pos<<" : "<<bitSum(bitVal,pos)<<endl;
			chmin(ans, must + bitSum(bitVal, pos));
		}
		cout << ans << endl;
	}
	
	return 0;
}