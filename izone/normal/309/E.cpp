#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define SZ 65536
#define pii pair<int,int>
using namespace std;
int n, INF = 1.5e9;
struct point {
	int b, e, num;
	bool operator <(const point &p)const {
		return b != p.b ? b < p.b : e < p.e;
	}
}w[50100];
struct Tree {
	int LM[SZ + SZ], S[SZ + SZ];
	void init() {
		int b = SZ, e = SZ + n;
		while (b) {
			for (int i = b; i <= e; i++)LM[i] = S[i] = 0;
			b >>= 1, e = (e + 1) >> 1;
		}
	}
	void Add(int a, int b) {
		a += SZ;
		S[a] += b;
		LM[a] = min(0, S[a]);
		while (a != 1) {
			a >>= 1;
			S[a] = S[a * 2] + S[a * 2 + 1];
			LM[a] = min(LM[a * 2], S[a * 2] + LM[a * 2 + 1]);
		}
	}
	int Get(int b) {
		if (LM[1] < 0)return -1;
		if (S[b + SZ] == 0)return b;
		int s = S[b + SZ];
		b += SZ + 1;
		int e = SZ + n;
		while (b <= e) {
			if (b & 1) {
				if (LM[b] + s == 0) {
					break;
				}
				s += S[b];
			}
			b = (b + 1) >> 1;
			e = (e - 1) >> 1;
		}
		while (b < SZ) {
			b *= 2;
			if (LM[b] + s != 0) {
				s += S[b];
				b++;
			}
		}
		return b - SZ;
	}
}T;
struct RMQ {
	int IT[SZ + SZ];
	void init() {
		for (int i = 0; i < SZ + SZ; i++)IT[i] = INF;
	}
	void Put(int a, int b) {
		a += SZ;
		IT[a] = b;
		while (a != 1) {
			a >>= 1;
			IT[a] = min(IT[a * 2], IT[a * 2 + 1]);
		}
	}
	pii GetMin(int b, int e) {
		b += SZ, e += SZ;
		int r = INF, pv = -1;
		while (b <= e) {
			if (r > IT[b])r = IT[b], pv = b;
			if (r > IT[e])r = IT[e], pv = e;
			b = (b + 1) >> 1, e = (e - 1) >> 1;
		}
		if (pv == -1)return { -1,-1 };
		while (pv < SZ) {
			pv *= 2;
			if (IT[pv] != r)pv++;
		}
		return { r,pv - SZ };
	}
}RM;
int ED[50100], PV, vis[50100], KK, Res[50100], Z[50100];
void Go(int cur, int a) {
	Res[cur] = a;
	T.Add(cur, -1);
	T.Add(ED[a], 1);
	vis[a] = 1;
	while (PV <= n && w[PV].b <= w[a].e) {
		if (!vis[PV]) {
			T.Add(ED[PV], 1);
			ED[PV] = min(cur + KK - 1, n);
			T.Add(ED[PV], -1);
			Z[ED[PV]] = PV;
		}
		PV++;
	}
}
bool Pos(int K) {
	KK = K;
	int i;
	PV = 1;
	for (i = 1; i <= n; i++)T.Add(i, 1);
	for (i = 1; i <= n; i++) {
		Z[i] = 0;
		vis[i] = 0;
		ED[i] = n;
		T.Add(n, -1);
		RM.Put(i, w[i].e);
	}
	Z[n] = n;
	pii tp = RM.GetMin(1, n);
	int a = tp.second;
	RM.Put(a, INF);
	Go(1, a);
	for (i = 2; i <= n; i++) {
		int pv = T.Get(i);
		if (pv == -1)return false;
		Z[n] = n;
		pii tp = RM.GetMin(1, Z[pv]);
		if (tp.second == -1)return false;
		a = tp.second;
		RM.Put(a, INF);
		Go(i, a);
	}
	int Mx = 0;
	for (i = 1; i <= n - K; i++) {
		Mx = max(Mx, w[Res[i]].e);
		if (Mx >= w[Res[i + K]].b)return false;
	}
	return true;
}
void Solve() {
	int i;
	scanf("%d", &n);
	map<int, int>Map;
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &w[i].b, &w[i].e);
		w[i].num = i;
		Map[w[i].b] = 1; Map[w[i].e] = 1;
	}
	vector<int>TM;
	for (auto &t : Map)TM.push_back(t.first);
	for (i = 0; i < TM.size(); i++)Map[TM[i]] = i + 1;
	for (i = 1; i <= n; i++)w[i].b = Map[w[i].b], w[i].e = Map[w[i].e];
 
	sort(w + 1, w + n + 1);
	int b = 1, e = n, r = 0, mid;
	while (b <= e) {
		mid = (b + e) >> 1;
		if (Pos(mid)) {
			r = mid;
			e = mid - 1;
		}
		else b = mid + 1;
		T.init();
	}
	Pos(r);
	T.init();
	for(i=1;i<=n;i++)printf("%d ",w[Res[i]].num);
}
int main() {
	int TC;
	TC = 1;
	while (TC--) {
		Solve();
	}
}