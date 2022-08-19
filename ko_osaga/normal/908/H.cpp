#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int MAXN = 300005;
const int mod = 1e9 + 696969;

int adj[25];

using base = int;

void fft(vector<base> &a, bool inv){
	int n = a.size(), j = 0;
	vector<base> roots(n/2);
	for(int i=1; i<n; i++){
		int bit = (n >> 1);
		while(j >= bit){
			j -= bit;
			bit >>= 1;
		}
		j += bit;
		if(i < j) swap(a[i], a[j]);
	}
	for(int i=2; i<=n; i<<=1){
		int step = n / i;
		for(int j=0; j<n; j+=i){
			for(int k=0; k<i/2; k++){
				base u = a[j+k], v = a[j+k+i/2];
				if (!inv) {
					a[j + k] = (u + v) % mod;
					a[j + k + i/2] = u;
				} else {
					a[j + k] = v;
					a[j + k + i/2] = (u - v + mod) % mod;
				}
			}
		}
	}
}

vector<int> pwr[5];

int chrome(vector<pi> edg, int n){
	if(n == 0) return 0;
	for(auto &i : edg){
		adj[i.first] |= (1<<i.second);
		adj[i.second] |= (1<<i.first);
	}
	vector<int> chk(1<<n);
	for(int i=0; i<(1<<n); i++){
		int adjv = 0;
		for(int j=0; j<n; j++){
			if((i >> j) & 1){
				adjv |= adj[j];
			}
		}
		if(adjv & i) continue;
		chk[i] = 1;
	}
	fft(chk, 0);
	pwr[0] = chk;
	for(int i=1; i<5; i++){
		pwr[i].resize(1<<n);
		for(int j=0; j<(1<<n); j++){
			pwr[i][j] = 1ll * pwr[i-1][j] * pwr[i-1][j] % mod;
		}
	}
	vector<int> ans(1<<n);
	ans[0] = 1;
	fft(ans, 0);
	int ret = 0;
	for(int i=4; i>=0; i--){
		vector<int> nxt(1<<n);
		for(int j=0; j<(1<<n); j++){
			nxt[j] = 1ll * ans[j] * pwr[i][j] % mod;
		}
		auto tmp = nxt;
		fft(tmp, 1);
		if(tmp.back() == 0){
			ret += (1<<i);
			ans = nxt;
		}
	}
	return ret + 1;
}

struct disj{
	int pa[50], sz[50];
	void init(int n){
		iota(pa, pa + n + 1, 0);
		fill(sz, sz + n + 1, 1);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; 
		sz[p] += sz[q];
		return 1;
	}
	int getsz(int x){ return sz[find(x)]; }
}disj;

char str[50][50];
int L[50], S[50];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%s", str[i]);
	}
	disj.init(n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(str[i][j] == 'A'){
				disj.uni(i, j);
			}
		}
	}
	int cnt = 0;
	vector<int> imp;
	for(int i=0; i<n; i++){
		if(disj.find(i) == i){
			L[i] = cnt;
			S[cnt] = disj.getsz(i);
			if(S[cnt] >= 2){
				imp.push_back(cnt);
			}
			cnt++;
		}
	}
	vector<pi> drog;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(str[i][j] == 'X'){
				int x = L[disj.find(i)];
				int y = L[disj.find(j)];
				if(x == y){
					puts("-1");
					return 0;
				}
				if(S[x] >= 2 && S[y] >= 2){
					x = lower_bound(imp.begin(), imp.end(), x) - imp.begin();
					y = lower_bound(imp.begin(), imp.end(), y) - imp.begin();
					if(x > y) swap(x, y);
					drog.emplace_back(x, y);
				}
			}
		}
	}
	sort(drog.begin(), drog.end());
	drog.resize(unique(drog.begin(), drog.end()) - drog.begin());
	cout << n - 1 + chrome(drog, imp.size()) << endl; 
}