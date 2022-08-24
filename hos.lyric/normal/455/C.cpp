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


//

const int INF = 1001001001;
const int LIM_N = 300000;//100000;

int N, M;//, L;
int A[LIM_N + 10], B[LIM_N + 10];//, C[LIM_N + 10];

vector<int> graph[LIM_N + 10];
int numComps, compIds[LIM_N + 10];
int depths[LIM_N + 10];
int memoDfsDepth[LIM_N * 2 + 10];

void dfsMark(int u, int p) {
	compIds[u] = numComps;
	for (unsigned j = 0; j < graph[u].size(); ++j) {
		int i = graph[u][j];
		int v = (i % 2 == 0) ? B[i / 2] : A[i / 2];
		if (v != p) {
			dfsMark(v, u);
		}
	}
}

pair<int,int> dfsDiameter(int u, int p) {
	pair<int,int> ret = make_pair(0, u);
	for (unsigned j = 0; j < graph[u].size(); ++j) {
		int i = graph[u][j];
		int v = (i % 2 == 0) ? B[i / 2] : A[i / 2];
		if (v != p) {
			pair<int,int> tmp = dfsDiameter(v, u);
			tmp.first += 1;//C[i / 2];
			if (ret < tmp) {
				ret = tmp;
			}
		}
	}
	return ret;
}

int dfsDepth(int i) {
	int &ret = memoDfsDepth[i];
	if (ret == -1) {
		ret = 0;
		int u = (i % 2 == 0) ? B[i / 2] : A[i / 2];
		for (unsigned j = 0; j < graph[u].size(); ++j) {
			if (graph[u][j] != (i ^ 1)) {
				int tmp = dfsDepth(graph[u][j]);
				if (ret < tmp) {
					ret = tmp;
				}
			}
		}
		ret += 1;//C[i / 2];
	}
	return ret;
}

int dfsDepthRoot(int u) {
	int ret = 0;
	for (unsigned j = 0; j < graph[u].size(); ++j) {
		int tmp = dfsDepth(graph[u][j]);
		if (ret < tmp) {
			ret = tmp;
		}
	}
	return ret;
}

int solve() {
	int ans = 0;
	numComps = 0;
	for (int u = 0; u < N; ++u) {
		compIds[u] = -1;
		graph[u] = vector<int>();
	}
	for (int i = 0; i < M; ++i) {
		graph[A[i]].push_back(i * 2 + 0);
		graph[B[i]].push_back(i * 2 + 1);
	}
	for (int u = 0; u < N; ++u) if (compIds[u] == -1) {
		dfsMark(u, -1);
		pair<int,int> res1 = dfsDiameter(u, -1);
		pair<int,int> res2 = dfsDiameter(res1.second, -1);
		if (ans < res2.first) {
			ans = res2.first;
		}
		++numComps;
	}
	for (int i = 0; i < M * 2; ++i) {
		memoDfsDepth[i] = -1;
	}
	for (int k = 0; k < numComps; ++k) {
		depths[k] = INF;
	}
	for (int u = 0; u < N; ++u) {
		int tmp = dfsDepthRoot(u);
		if (depths[compIds[u]] > tmp) {
			depths[compIds[u]] = tmp;
		}
	}
	int bests[3] = {};
	for (int k = 0; k < numComps; ++k) {
		int tmp = depths[k];
		for (int l = 0; l < 3; ++l) {
			if (bests[l] < tmp) {
				swap(bests[l], tmp);
			}
		}
	}
	if (numComps >= 2) {
		int tmp = bests[0] + bests[1] + 1;//L;
		if (ans < tmp) {
			ans = tmp;
		}
	}
	if (numComps >= 3) {
		int tmp = bests[1] + bests[2] + 1 * 2;//L * 2;
		if (ans < tmp) {
			ans = tmp;
		}
	}
	return ans;
}

//

int uf[300010];
int root(int u) {
	return (uf[u] < 0) ? u : (uf[u] = root(uf[u]));
}
void conn(int u, int v) {
	u = root(u);
	v = root(v);
	if (u == v) return;
	if (uf[u] > uf[v]) swap(u, v);
	uf[u] += uf[v];
	uf[v] = u;
}

int diams[300010];
pint centers[300010];

int main() {
	int Q;
	
	for (; ~scanf("%d%d%d", &N, &M, &Q); ) {
		for (int i = 0; i < M; ++i) {
			A[i] = in() - 1;
			B[i] = in() - 1;
		}
		solve();
// cout<<"dfsDepthRoot : ";for(int u=0;u<N;++u)cout<<dfsDepthRoot(u)<<" ";cout<<endl;
		
		fill(uf, uf + N, -1);
		for (int i = 0; i < M; ++i) {
			conn(A[i], B[i]);
		}
		fill(diams, diams + N, 0);
		fill(centers, centers + N, mp(INF, -1));
		for (int u = 0; u < N; ++u) if (uf[u] < 0) {
			const auto res1 = dfsDiameter(u, -1);
			const auto res2 = dfsDiameter(res1.second, -1);
			diams[u] = res2.first;
		}
		for (int u = 0; u < N; ++u) {
			const int r = root(u);
			chmin(centers[r], mp(dfsDepthRoot(u), u));
		}
		
		for (; Q--; ) {
/*
cout<<"uf : ";pv(uf,uf+N);
cout<<"diams : ";for(int r=0;r<N;++r)if(uf[r]<0)cout<<diams[r]<<" ";cout<<endl;
cout<<"centers : ";for(int r=0;r<N;++r)if(uf[r]<0)cout<<centers[r].first<<","<<centers[r].second<<" ";cout<<endl;
//*/
			switch (in()) {
				case 1: {
					const int u = root(in() - 1);
					printf("%d\n", diams[u]);
				} break;
				case 2: {
					int u = root(in() - 1);
					int v = root(in() - 1);
					if (u != v) {
						if (uf[u] > uf[v]) swap(u, v);
						uf[u] += uf[v];
						uf[v] = u;
						diams[u] = max({
							diams[u], 
							diams[v], 
							centers[u].first + 1 + centers[v].first
						});
						centers[u] = min(
							mp(max(centers[u].first, 1 + centers[v].first), centers[u].second), 
							mp(max(centers[v].first, 1 + centers[u].first), centers[v].second)
						);
					}
				} break;
				default: assert(false);
			}
		}
	}
	
	return 0;
}