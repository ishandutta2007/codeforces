#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int mod = 1e9 + 7;
const int MAXN = 7005;


lint n, k;
lint dp[10005][52][52];
lint inv[55];

lint ipow(lint x, lint p){
	lint ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}

vector<pi> advance(vector<pi> v, lint kk, int c){
	vector<pi> w;
	for(auto &i : v){
		lint gob = 1;
		for(int j=0; j<=c; j++){
			w.emplace_back(i.first * gob, i.second * dp[k][c][j] % mod);
			gob *= kk;
		}
	}
	return w;
}

int main(){
	cin >> n >> k;
	for(int i=0; i<=51; i++){
		dp[0][i][i] = 1;
		inv[i] = ipow(i, mod - 2);
	}
	for(int i=0; i<k; i++){
		for(int j=0; j<=50; j++){
			for(int k=0; k<=j; k++){
				dp[i+1][j][k] += dp[i][j][k] * inv[k + 1] % mod;
			}
		}
		for(int j=0; j<=50; j++){
			for(int k=49; k>=0; k--){
				dp[i+1][j][k] += dp[i+1][j][k+1];
				dp[i+1][j][k] %= mod;
			}
		}
	}
	vector<pi> prob;
	prob.emplace_back(1, 1);
	for(int i=2; i<=33333333; i++){
		int cnt = 0;
		while(n % i == 0){
			n /= i;
			cnt++;
		}
		if(cnt){
			prob = advance(prob, i, cnt);
		}
	}
	if(n > 1) prob = advance(prob, n, 1);
	lint ret = 0;
	for(auto &i : prob){
		ret += (i.first % mod) * i.second % mod;
		ret %= mod;
	}
	cout << ret << endl;
}

/*
int n, q;
bitset<MAXN> yaksu[MAXN];
bitset<MAXN> besu[MAXN];
bitset<MAXN> a[100005];
int moe[MAXN];

int main(){
	scanf("%d %d",&n,&q);
	moe[1] = 1;
	for(int i=1; i<MAXN; i++){
		for(int j=2*i; j<MAXN; j+=i){
			moe[j] -= moe[i];
		}
	}
	for(int i=1; i<MAXN; i++){
		for(int j=i; j<MAXN; j+=i){
			if(moe[j / i]){
				yaksu[j].set(i);
				besu[i].set(j);
			}
		}
	}
	for(int i=0; i<q; i++){
		int t; scanf("%d",&t);
		if(t == 1){
			int x, v; scanf("%d %d",&x,&v);
			a[x] = yaksu[v];
		}
		if(t == 2){
			int x, y, z;
			scanf("%d %d %d",&x,&y,&z);
			a[x] = a[y] ^ a[z];
		}
		if(t == 3){
			int x, y, z;
			scanf("%d %d %d",&x,&y,&z);
			a[x] = a[y] & a[z];
		}
		if(t == 4){
			int x, v; scanf("%d %d",&x,&v);
			printf("%d", (besu[v] & a[x]).count() % 2);
		}
	}
}*/