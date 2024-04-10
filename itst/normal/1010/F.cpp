#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<sstream>
//STL
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
//C++11 needed
#include<unordered_map>
#include<unordered_set>
#include<random>
using namespace std;

long long read(){
	long long a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define sz(x) (int)x.size()
#define VI vector < int > 
#define REP(i,j,k) for(int i = j ; i <= k ; ++i)
const int P = 998244353 , G = 3 , _ = 1 << 18 | 1;
int upd(int x){return x + (x >> 31 & P);}
int poww(long long a , int b){int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;}

int dir[_] , w[_] , need , invnd;
void init(int l){
	need = 1; while(need < l) need <<= 1;
	REP(i , 1 , need - 1) dir[i] = (dir[i >> 1]) >> 1 | (i & 1 ? need >> 1 : 0);
	static int L = 1; invnd = poww(need , P - 2);
	for(int &i = L ; i < need ; i <<= 1){
		w[i] = 1; int wn = poww(G , P / i / 2);
		for(int j = 1 ; j < i ; ++j) w[i + j] = 1ll * w[i + j - 1] * wn % P;
	}
}

void DFT(VI &arr , int tp){
	arr.resize(need); REP(i , 1 , need - 1) if(i < dir[i]) swap(arr[i] , arr[dir[i]]);
	for(int i = 1 ; i < need ; i <<= 1)
		for(int j = 0 ; j < need ; j += i << 1)
			REP(k , 0 , i - 1){
				int x = arr[j + k] , y = 1ll * arr[i + j + k] * w[i + k] % P;
				arr[j + k] = upd(x + y - P); arr[i + j + k] = upd(x - y);
			}
	if(tp == -1){
		reverse(arr.begin() + 1 , arr.end()); REP(i , 0 , need - 1) arr[i] = 1ll * arr[i] * invnd % P;
		while(sz(arr) && !arr.back()) arr.pop_back();
	}
}

VI nxt[_]; long long X; int N; void addEd(int a , int b){nxt[a].push_back(b);}

int son[_] , top[_] , sz[_] , fa[_];
void dfs1(int x , int p){
	fa[x] = p; sz[x] = 1; for(auto t : nxt[x]) if(t != p){dfs1(t , x); sz[x] += sz[t]; son[x] = sz[son[x]] < sz[t] ? t : son[x];}
}

#define st first
#define nd second
VI pol[_];

pair < VI , VI > solve(vector < VI > pot){
	if(sz(pot) == 1) return make_pair(pot[0] , pot[0]);
	int mid = sz(pot) >> 1; vector < VI > L , R; for(int i = 0 ; i < sz(pot) ; ++i) (i < mid ? L : R).push_back(pot[i]);
	pair < VI , VI > p = solve(L) , q = solve(R); init(sz(p.st) + sz(q.st));
	DFT(p.st , 1); DFT(p.nd , 1); DFT(q.st , 1);
	for(int i = 0 ; i < need ; ++i){p.st[i] = 1ll * p.st[i] * q.st[i] % P; p.nd[i] = 1ll * p.nd[i] * q.st[i] % P;}
	DFT(p.st , -1); DFT(p.nd , -1); for(int i = 0 ; i < sz(q.nd) ; ++i) p.nd[i] = upd(p.nd[i] + q.nd[i] - P);
	return p;
}

void solve_chain(int x){
	vector < VI > cur; int t = x;
	while(x){pol[x].insert(pol[x].begin() , 0); cur.push_back(pol[x]); x = son[x];}
	reverse(cur.begin() , cur.end()); pol[t] = solve(cur).nd; ++pol[t][0];
}

void dfs2(int x , int t){
	pol[x] = {1};
	if(son[x]){dfs2(son[x] , t); for(auto t : nxt[x]) if(t != fa[x] && t != son[x]){dfs2(t , t); pol[x] = pol[t];}}
	if(x == t) solve_chain(x);
}

int main(){
	N = read(); X = read() % P;
	for(int i = 1 ; i < N ; ++i){int x = read() , y = read(); addEd(x , y); addEd(y , x);}
	dfs1(1 , 0); dfs2(1 , 1); int ans = 0;
	for(int i = 1 , p = 1 ; i < sz(pol[1]) ; p = 1ll * p * (X + i) % P * poww(i , P - 2) % P , ++i)
		ans = (ans + 1ll * p * pol[1][i]) % P;
	printf("%d\n" , ans); return 0;
}