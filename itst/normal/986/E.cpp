//CF986E
#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();}
	return a;
}

#define st first
#define nd second
const int __ = 1e7 + 7 , _ = 1e5 + 7 , MOD = 1e9 + 7;
int lst[__] , prm[_ * 10] , cnt; bool nprm[__];

void init(){
	for(int i = 2 ; i <= 1e7 ; ++i){
		if(!nprm[i]){prm[++cnt] = i; lst[i] = cnt;}
		for(int j = 1 ; prm[j] * i <= 1e7 ; ++j){
			nprm[prm[j] * i] = 1; lst[prm[j] * i] = j;
			if(i % prm[j] == 0) break;
		}
	}
}

#define PII pair < int , int >
vector < PII > in[_ * 10] , qry[_ * 10];
struct Edge{int end , upEd;}Ed[_ << 1]; int head[_] , N , Q , cntEd;
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}

int dfn[_] , sz[_] , jump[_][20] , dep[_] , ts;
void dfs(int x , int p){
	dfn[x] = ++ts; sz[x] = 1; jump[x][0] = p; dep[x] = dep[p] + 1;
	for(int i = 1 ; jump[x][i - 1] ; ++i) jump[x][i] = jump[jump[x][i - 1]][i - 1];
	for(int i = head[x] ; i ; i = Ed[i].upEd) if(Ed[i].end != p){dfs(Ed[i].end , x); sz[x] += sz[Ed[i].end];}
}

struct BIT{
#define lowbit(x) ((x) & -(x))
	int arr[_];
	void add(int x , int num){while(x <= N){arr[x] += num; x += lowbit(x);}}
	int sum(int x){int sum = 0; while(x){sum += arr[x]; x -= lowbit(x);} return sum;}
}BIT1 , BIT2;
int ans[_] , x[_] , y[_];

int poww(long long a , int b){
	int times = 1;
	while(b){
		if(b & 1) times = times * a % MOD;
		a = a * a % MOD; b >>= 1;
	}
	return times;
}

int LCA(int p , int q){
	if(dep[p] < dep[q]) swap(p , q);
	for(int i = 18 ; i >= 0 ; --i)
		if(dep[p] - (1 << i) >= dep[q]) p = jump[p][i];
	if(p == q) return p;
	for(int i = 18 ; i >= 0 ; --i)
		if(jump[p][i] != jump[q][i]){p = jump[p][i]; q = jump[q][i];}
	return jump[p][0];
}

int query(BIT &now , int p , int q){
	int t = LCA(p , q); return now.sum(dfn[p]) + now.sum(dfn[q]) - now.sum(dfn[t]) - now.sum(dfn[jump[t][0]]);
}

void add(BIT &now , int plc , int val){
	now.add(dfn[plc] + sz[plc] , -val); now.add(dfn[plc] , val);
}

int main(){
	init(); N = read();
	for(int i = 1 ; i < N ; ++i){int p = read() , q = read(); addEd(p , q); addEd(q , p);}
	for(int i = 1 ; i <= N ; ++i){
		int val = read() , pre = 0 , cnt = 0;
		while(val != 1){
			int num = lst[val];
			if(pre != num){if(pre) in[pre].push_back(PII(cnt , i)); cnt = 0;}
			pre = num; ++cnt; val /= prm[num];
		}
		if(pre) in[pre].push_back(PII(cnt , i));
	}
	dfs(1 , 0); Q = read();
	for(int i = 1 ; i <= Q ; ++i){
		x[i] = read(); y[i] = read(); int val = read() , pre = 0 , cnt = 0;
		while(val != 1){
			int num = lst[val];
			if(pre != num){if(pre) qry[pre].push_back(PII(cnt , i)); cnt = 0;}
			pre = num; ++cnt; val /= prm[num];
		}
		if(pre) qry[pre].push_back(PII(cnt , i));
		ans[i] = 1;
	}
	for(int i = 1 ; i <= cnt ; ++i){
		if(qry[i].empty() || in[i].empty()) continue;
		sort(qry[i].begin() , qry[i].end()); sort(in[i].begin() , in[i].end());
		int pos = 0; qry[i].push_back(PII(1e9 , 0));
		for(auto t : in[i]) add(BIT2 , t.nd , 1);
		for(auto t : qry[i]){
			while(pos < in[i].size() && in[i][pos].st <= t.st){
				add(BIT1 , in[i][pos].nd , in[i][pos].st);
				add(BIT2 , in[i][pos].nd , -1); ++pos;
			}
			ans[t.nd] = 1ll * ans[t.nd] * poww(prm[i] , query(BIT1 , x[t.nd] , y[t.nd]) + query(BIT2 , x[t.nd] , y[t.nd]) * t.st) % MOD;
		}
		for(auto t : in[i]) add(BIT1 , t.nd , -t.st);
	}
	for(int i = 1 ; i <= Q ; ++i) printf("%d\n" , ans[i]);
	return 0;
}