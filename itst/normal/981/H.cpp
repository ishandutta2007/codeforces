#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353 , G = 3 , _ = 1 << 18;
int upd(int x){return x + (x >> 31 & MOD);}
int poww(long long a , int b){
	int tms = 1;
	while(b){
		if(b & 1) tms = tms * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return tms;
}

int dir[_] , need , invnd , w[_];
void init(int len){
	need = 1; while(need < len) need <<= 1;
	invnd = poww(need , MOD - 2);
	for(int i = 1 ; i < need ; ++i) dir[i] = (dir[i >> 1] >> 1) | (i & 1 ? need >> 1 : 0);
	static int L = 1;
	for(int &i = L ; i < need ; i <<= 1){
		w[i] = 1; int wn = poww(G , MOD / i / 2);
		for(int j = 1 ; j < i ; ++j) w[i + j] = 1ll * w[i + j - 1] * wn % MOD;
	}
}

void DFT(vector < int > &arr , int tp){
	arr.resize(need);
	for(int i = 1 ; i < need ; ++i)
		if(i < dir[i]) swap(arr[i] , arr[dir[i]]);
	for(int i = 1 ; i < need ; i <<= 1)
		for(int j = 0 ; j < need ; j += i << 1)
			for(int k = 0 ; k < i ; ++k){
				int x = arr[j + k] , y = 1ll * arr[i + j + k] * w[i + k] % MOD;
				arr[j + k] = upd(x + y - MOD); arr[i + j + k] = upd(x - y);
			}
	if(tp == -1){
		reverse(arr.begin() + 1 , arr.end());
		for(int i = 0 ; i < need ; ++i) arr[i] = 1ll * arr[i] * invnd % MOD;
	}
}

vector < int > divide(vector < int > &pot , int l , int r){
	if(l == r) return {1 , pot[l]};
	int mid = (l + r) >> 1; vector < int > L = divide(pot , l , mid) , R = divide(pot , mid + 1 , r);
	init(L.size() + R.size() - 1); DFT(L , 1); DFT(R , 1);
	for(int i = 0 ; i < need ; ++i) L[i] = 1ll * L[i] * R[i] % MOD;
	DFT(L , -1); return L;
}

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

struct Edge{int end , upEd;}Ed[_ << 1];
int head[_] , cntEd , N , K , fac[_] , ifac[_] , ans;
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}

int sz[_] , val[_];
void dfs(int x , int p){
	sz[x] = 1; vector < int > ch , pol;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			dfs(Ed[i].end , x); sz[x] += sz[Ed[i].end]; ch.push_back(sz[Ed[i].end]);
			ans = (ans + 1ll * val[Ed[i].end] * val[x]) % MOD; val[x] = upd(val[x] + val[Ed[i].end] - MOD);
		}
	if(ch.empty()) pol.push_back(1); else pol = divide(ch , 0 , ch.size() - 1);
	for(int i = 0 ; i < pol.size() && i <= K ; ++i)
		val[x] = (val[x] + 1ll * fac[K] * ifac[K - i] % MOD * pol[i]) % MOD;
	sort(ch.begin() , ch.end()); ch.resize(unique(ch.begin() , ch.end()) - ch.begin());
	pol.resize(pol.size() + 1); for(int i = pol.size() - 1 ; i ; --i) pol[i] = (pol[i] + 1ll * pol[i - 1] * (N - sz[x])) % MOD;
	for(auto t : ch){
		vector < int > tp; tp.resize(pol.size() - 1); tp[0] = 1;
		for(int i = 1 ; i < tp.size() ; ++i) tp[i] = upd(pol[i] - 1ll * t * tp[i - 1] % MOD);
		int sum = 0;
		for(int i = 0 ; i < tp.size() && i <= K ; ++i)
			sum = (sum + 1ll * fac[K] * ifac[K - i] % MOD * tp[i]) % MOD;
		for(int i = head[x] ; i ; i = Ed[i].upEd)
			if(Ed[i].end != p && sz[Ed[i].end] == t)
				ans = (ans + 1ll * val[Ed[i].end] * sum) % MOD;
	}
}

int main(){
	N = read(); K = read(); for(int i = 1 ; i < N ; ++i){int x = read() , y = read(); addEd(x , y); addEd(y , x);}
	if(K == 1){cout << N * (N - 1ll) / 2 % MOD; return 0;}
	fac[0] = 1; for(int i = 1 ; i <= K ; ++i) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[K] = poww(fac[K] , MOD - 2); for(int i = K - 1 ; ~i ; --i) ifac[i] = ifac[i + 1] * (i + 1ll) % MOD;
	dfs(1 , 0); cout << ans; return 0;
}