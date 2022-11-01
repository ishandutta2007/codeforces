#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
	int a = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c) && c != EOF){
		if(c == '-')
			f = 1;
		c = getchar();
	}
	if(c == EOF)
		exit(0);
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return f ? -a : a;
}

const int MAXN = 2e5 + 9 , MOD = 1e9 + 7;
int mu[MAXN] , phi[MAXN] , prime[MAXN] , cnt;
bool nprime[MAXN];
struct Edge{
	int end , upEd;
}Ed[MAXN << 1];
int N , cntEd , ts , top , cntT , cntST , cur , ans1 , ans;
int head[MAXN] , val[MAXN] , ind[MAXN];
int dfn[MAXN] , dep[MAXN] , fir[MAXN] , ST[21][MAXN << 1] , logg2[MAXN << 1];
int st[MAXN] , tree[MAXN] , dp1[MAXN] , dp2[MAXN] , q[MAXN];
vector < int > ch[MAXN];

inline void addEd(int a , int b){
	Ed[++cntEd].end = b;
	Ed[cntEd].upEd = head[a];
	head[a] = cntEd;
}

void input(){
	N = read();
	for(int i = 1 ; i <= N ; ++i)
		ind[val[i] = read()] = i;
	for(int i = 1 ; i < N ; ++i){
		int a = read() , b = read();
		addEd(a , b);
		addEd(b , a);
	}
}

inline void init(){
	phi[1] = mu[1] = 1;
	for(int i = 2 ; i <= N ; ++i){
		if(!nprime[i]){
			prime[++cnt] = i;
			phi[i] = i - 1;
			mu[i] = -1;
		}
		for(int j = 1 ; j <= cnt && prime[j] * i <= N ; ++j){
			nprime[i * prime[j]] = 1;
			if(i % prime[j] == 0){
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			mu[i * prime[j]] = mu[i] * -1;
		}
	}
}

void init_dfs(int x , int p){
	dfn[x] = ++ts;
	ST[0][++cntST] = x;
	fir[x] = cntST;
	dep[x] = dep[p] + 1;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			init_dfs(Ed[i].end , x);
			ST[0][++cntST] = x;
		}
}

inline int cmp(int a , int b){
	return dep[a] < dep[b] ? a : b;
}

void init_ST(){
	for(int i = 2 ; i <= cntST ; ++i)
		logg2[i] = logg2[i >> 1] + 1;
	for(int i = 1 ; 1 << i <= cntST ; ++i)
		for(int j = 1 ; j + (1 << i) <= cntST + 1 ; ++j)
			ST[i][j] = cmp(ST[i - 1][j] , ST[i - 1][j + (1 << (i - 1))]);
}

inline int LCA(int x , int y){
	x = fir[x];
	y = fir[y];
	if(x > y)
		swap(x , y);
	int t = logg2[y - x + 1];
	return cmp(ST[t][x] , ST[t][y - (1 << t) + 1]);
}

inline int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1)
			times = times * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return times;
}

bool cmp1(int a , int b){
	return dfn[a] < dfn[b];
}

int dfs(int x){
	dp1[x] = dp2[x] = 0;
	int sum = 0;
	for(int i = 0 ; i < ch[x].size() ; ++i){
		sum = (sum + dfs(ch[x][i])) % MOD;
		sum = (sum + 1ll * dp1[x] * dp2[ch[x][i]] % MOD + 1ll * dp1[ch[x][i]] * dp2[x] % MOD - 2ll * dep[x] * dp1[x] % MOD * dp1[ch[x][i]] % MOD + MOD) % MOD;
		dp1[x] = (dp1[x] + dp1[ch[x][i]]) % MOD;
		dp2[x] = (dp2[x] + dp2[ch[x][i]]) % MOD;
	}
	if(val[x] % cur == 0){
		sum = (sum + 1ll * dp2[x] * phi[val[x]] % MOD - 1ll * dep[x] * dp1[x] % MOD * phi[val[x]] % MOD + MOD) % MOD;
		dp1[x] = (dp1[x] + phi[val[x]]) % MOD;
		dp2[x] = (dp2[x] + 1ll * phi[val[x]] * dep[x]) % MOD;
	}
	return sum;
}

inline void calc(int x){
	cntT = 0;
	for(int i = 1 ; x * i <= N ; ++i){
		ch[ind[x * i]].clear();
		tree[++cntT] = ind[x * i];
	}
	sort(tree + 1 , tree + cntT + 1 , cmp1);
	for(int i = 1 ; i <= cntT ; ++i){
		if(top){
			int t = LCA(st[top] , tree[i]);
			while(top - 1 && dep[st[top - 1]] >= dep[t]){
				ch[st[top - 1]].push_back(st[top]);
				--top;
			}
			if(t != st[top]){
				ch[t].clear();
				ch[t].push_back(st[top]);
				st[top] = t;
			}
		}
		st[++top] = tree[i];
	}
	int rt = st[1];
	while(top > 1){
		ch[st[top - 1]].push_back(st[top]);
		--top;
	}
	top = 0;
	ans = (ans + 1ll * q[x] * dfs(rt)) % MOD;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	input();
	init();
	init_dfs(1 , 0);
	init_ST();
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j * i <= N ; ++j)
			q[i * j] = (q[i * j] + 1ll * i * mu[j] * poww(phi[i] , MOD - 2) % MOD + MOD) % MOD;
	for(cur = 1 ; cur <= N / 2 ; ++cur)
		calc(cur);
	cout << 2ll * ans * poww(1ll * N * (N - 1) % MOD , MOD - 2) % MOD;
	return 0;
}