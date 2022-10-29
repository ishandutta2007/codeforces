#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MM = 1e9 + 9;
const int M2 = 23456789;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

/*
struct hash_t {
  int length;
  unsigned long long value;
  hash_t(): length(0), value(0) {}
  hash_t(char c): length(1), value(c) {}
  hash_t(int l, unsigned long long v): length(l), value(v) {}
  bool operator == (const hash_t &rhs) const {
    return length == rhs.length && value == rhs.value;
  }
  hash_t operator + (const hash_t &rhs) const {
    return hash_t(length + rhs.length, value * pw[rhs.length] + rhs.value);
  }
  bool operator < (const hash_t &rhs) const {
    return value < rhs.value;
  }
};*/

ll hh[MAXN], hh2[MAXN], rd[MAXN], rd2[MAXN];
vector<int> E[MAXN];
map<PLL, int> nico;
int ans, nowans;

void dfs(int x, int fa){
	int y;
	hh[x] = 0;
	hh2[x] = 0;
	for(int i = 0; i < E[x].size(); i++)
		if ((y = E[x][i]) != fa){
			dfs(y, x);
			hh[x] = (hh[x] + hh[y] * hh[y]) % MM;
			hh2[x] = (hh2[x] + hh2[y] * hh2[y]) % M2;
		}
	hh[x] += rd[E[x].size() - (fa != 0)];
	hh[x] %= MM;
	hh2[x] += rd2[E[x].size() - (fa != 0)];
	hh2[x] %= M2;
	nico[PLL(hh[x], hh2[x])]++;
}

void rm(PLL maki){
	auto umi = nico.find(maki);
	if (umi->second == 1){
		nico.erase(maki);
	}
	else
		nico[maki] --;
}

void ist(PLL maki){
	nico[maki]++;
}

void DFS(int x, int fa){
//	cout<<x<<' '<<nico.size()<<endl;
	if (nico.size() > ans){
		ans = nico.size();
		nowans = x;
	} /*else if (nico.size() == ans){
		nowans = min(nowans, x);
	}*/
	int y;
	rm(PLL(hh[x], hh2[x]));
	PLL tmp = PLL(hh[x], hh2[x]);
	for(int i = 0; i < E[x].size(); i++){
		if ((y = E[x][i]) != fa){
			hh[x] = ((hh[x] - hh[y] * hh[y] - rd[E[x].size()] + rd[E[x].size() - 1]) % MM + MM) % MM;
			hh2[x] = ((hh2[x] - hh2[y] * hh2[y] - rd2[E[x].size()] + rd2[E[x].size() - 1]) % M2 + M2) % M2;
		//	hh[x] = ((hh[x] - hh[y] * hh[y] - rd[E[x].size() - (fa != 0)] + rd[E[x].size() - (fa != 0) - 1]) % MM + MM) % MM;
		//	hh2[x] = ((hh2[x] - hh2[y] * hh2[y] - rd2[E[x].size() - (fa != 0)] + rd2[E[x].size() - (fa != 0) - 1]) % M2 + M2) % M2;
			ll tq = hh[y];
			ll tq2 = hh2[y];
			hh[y] = ((hh[y] + hh[x] * hh[x] - rd[E[y].size() - 1] + rd[E[y].size()]) % MM + MM) % MM;
			hh2[y] = ((hh2[y] + hh2[x] * hh2[x] - rd2[E[y].size() - 1] + rd2[E[y].size()]) % M2 + M2) % M2;
			ist(PLL(hh[x], hh2[x]));
			rm(PLL(tq, tq2));
			ist(PLL(hh[y], hh2[y]));
			DFS(y, x);
			rm(PLL(hh[y], hh2[y]));
			ist(PLL(tq, tq2));
			rm(PLL(hh[x], hh2[x]));
			hh[y] = tq;
			hh2[y] = tq2;
			hh[x] = tmp.first;
			hh2[x] = tmp.second;
		}
	}
	ist(PLL(hh[x], hh2[x]));
}

void solve(int casi){
  	scanf("%d", &n);
  	srand(time(NULL));
  	for(int i = 0; i <= n; i++)
  		rd[i] = rand() % MM, rd2[i] = rand() % M2;
  	for(int i = 1; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(int OO = 1; OO <= 6; OO++){
		nico.clear();
		int rt = rand() % n + 1;
		dfs(rt, 0);
		ans = nico.size();
		nowans = rt;
		DFS(rt, 0);
	}
	cout<<nowans<<endl;
}

int main(){
	solve(0);
	return 0;
}