#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()
const int _ = 3e5 + 7; const ll P = 1019260817 , sd = 233 , inv = 78741179;
struct Edge{int end , upEd;}Ed[_ << 1];
int dfn[_] , id[_] , sz[_] , son[_] , top[_] , fa[_] , dep[_] , head[_] , cntEd , N , M;
char str[_]; ll hsh[_][2] , bse[_] , iv[_];
void addEd(int a , int b){Ed[++cntEd] = (Edge){b , head[a]}; head[a] = cntEd;}

void dfs1(int x , int p){
	sz[x] = 1; fa[x] = p; dep[x] = dep[p] + 1;
	hsh[x][0] = (str[x] + hsh[p][0] * sd) % P;
	hsh[x][1] = (hsh[p][1] + str[x] * bse[dep[x] - 1]) % P;
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			dfs1(Ed[i].end , x); sz[x] += sz[Ed[i].end];
			if(sz[Ed[i].end] > sz[son[x]]) son[x] = Ed[i].end;
		}
}

void dfs2(int x , int t){
	static int ts; top[x] = t; dfn[x] = ++ts; id[ts] = x; if(!son[x]) return;
	dfs2(son[x] , t);
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != fa[x] && Ed[i].end != son[x]) dfs2(Ed[i].end , Ed[i].end);
}

#define PII pair < int , int >
#define VII vector < PII >
#define st first
#define nd second
#define pb push_back
VII pl , pr;
VII split(int x , int y){
	pl.clear(); pr.clear();
	while(top[x] != top[y])
		if(dep[top[x]] > dep[top[y]]){pl.pb(PII(x , top[x])); x = fa[top[x]];}
		else{pr.pb(PII(top[y] , y)); y = fa[top[y]];}
	pl.pb(PII(x , y)); reverse(pr.begin() , pr.end()); pl.insert(pl.end() , pr.begin() , pr.end()); return pl;
}

ll qry(int x , int fx , int dst){
	return fx == 1 ? (hsh[x][1] - hsh[fa[id[dfn[x] - dst + 1]]][1] + P) * iv[dep[x] - dst] % P :
		(hsh[id[dfn[x] + dst - 1]][0] - hsh[fa[x]][0] * bse[dst] % P + P) % P;
}

int val(int x , int fx , int y , int fy , int lim){
	if(qry(x , fx , lim) == qry(y , fy , lim)) return lim;
	int L = 0 , R = lim - 1;
	while(L < R){int mid = (L + R + 1) >> 1; qry(x , fx , mid) == qry(y , fy , mid) ? L = mid : R = mid - 1;}
	return L;
}

int main(){
	scanf("%d %s" , &N , str + 1); bse[0] = 1; bse[1] = sd; iv[0] = 1; iv[1] = inv;
	for(int i = 2 ; i <= N ; ++i){bse[i] = bse[i - 1] * sd % P; iv[i] = iv[i - 1] * inv % P;}
	for(int x , y , i = 1 ; i < N ; ++i){scanf("%d %d" , &x , &y); addEd(x , y); addEd(y , x);}
	dfs1(1 , 0); dfs2(1 , 1);
	for(scanf("%d" , &M) ; M ; --M){
		int a , b , c , d; scanf("%d %d %d %d" , &a , &b , &c , &d);
		VII l = split(a , b) , r = split(c , d); int pl = 0 , pr = 0 , ans = 0;
#define sgn(x) (x < 0 ? -1 : 1)
		while(pl < sz(l) && pr < sz(r)){
			int v1 = dep[l[pl].st] - dep[l[pl].nd] , v2 = dep[r[pr].st] - dep[r[pr].nd];
			int l1 = abs(v1) , l2 = abs(v2) , dst = min(l1 , l2) + 1 , f1 = sgn(v1) , f2 = sgn(v2);
			int v = val(l[pl].st , f1 , r[pr].st , f2 , dst); ans += v; if(dst != v) break;
			if(l1 + 1 == dst) ++pl; else l[pl].st = id[dfn[l[pl].st] - f1 * dst];
			if(l2 + 1 == dst) ++pr; else r[pr].st = id[dfn[r[pr].st] - f2 * dst];
		}
		printf("%d\n" , ans);
	}
	return 0;
}