#include<bits/stdc++.h>
using namespace std;

#define PII pair < int , int >
#define st first
#define nd second
#define VI vector < int >
#define pb push_back
const int _ = 2e5 + 7;
struct tp3{int a , b , c;}qr[_];
string str[_][2]; int N , M , Q , ans[_] , id[_][2] , qrl[_][2];

struct ssam{
	int tr[_][26] , fa[_] , lst[_] , cnt , nl[_][26];
	int ext(int p , int c){
		int t = ++cnt; lst[t] = lst[p] + 1; while(p && !tr[p][c]){tr[p][c] = t; p = fa[p];}
		if(!p){fa[t] = 1; return t;} int q = tr[p][c]; if(lst[q] == lst[p] + 1){fa[t] = q; return t;}
		int k = ++cnt; lst[k] = lst[p] + 1; memcpy(tr[k] , tr[q] , sizeof(tr[k]));
		fa[k] = fa[q]; fa[q] = fa[t] = k; while(tr[p][c] == q){tr[p][c] = k; p = fa[p];} return t;
	}
	
	int ts , dfn[_] , top[_] , sz[_] , son[_]; VI ed[_];
	void dfs1(int x){
		sz[x] = 1;
		for(int i = 0 ; i < 26 ; ++i)
			if(!tr[x][i]){tr[x][i] = tr[fa[x]][i]; nl[x][i] = ~nl[fa[x]][i] ? nl[fa[x]][i] : lst[fa[x]] + 1;}
		for(auto t : ed[x]){dfs1(t); sz[x] += sz[t]; if(sz[son[x]] < sz[t]) son[x] = t;}
	}

	void dfs2(int x , int t){
		top[x] = t; dfn[x] = ++ts; if(!son[x]) return;
		dfs2(son[x] , t); for(auto t : ed[x]) if(t != son[x]) dfs2(t , t);
	}
	
	int ch[_][26] , id[_] , rt , cnd; ssam(){rt = cnd = cnt = 1;}
	int ins(string str){int t = rt; for(auto p : str){if(!ch[t][p -= 'a']) ch[t][p] = ++cnd; t = ch[t][p];} return t;}
	void build(){
		queue < int > q; q.push(1); id[1] = 1; memset(nl , -1 , sizeof(nl));
		while(!q.empty()){
			int t = q.front(); q.pop();
			for(int i = 0 ; i < 26 ; ++i) if(ch[t][i]){id[ch[t][i]] = ext(id[t] , i); q.push(ch[t][i]);}
		}
		for(int i = 2 ; i <= cnt ; ++i) ed[fa[i]].pb(i);
		for(int i = 0 ; i < 26 ; ++i) tr[0][i] = 1;
		lst[0] = -1; dfs1(1); dfs2(1 , 1);
	}

	PII qrge(int x){return PII(dfn[id[x]] , dfn[id[x]] + sz[id[x]]);}
	PII go(int x , int l , int c){return PII(tr[x][c] , ~nl[x][c] ? nl[x][c] : l + 1);}
	
	VI pot[_];
	void push(int x , int v){pot[top[x]].pb(v);} void pop(int x){pot[top[x]].pop_back();}
	int qry(int x){
		x = id[x]; int p = x;
		while(x){
			int t = top[x];
			if(pot[t].empty() || pot[t][0] > lst[x] || pot[t][0] == lst[p]) x = fa[t];
			else{auto c = --upper_bound(pot[t].begin() , pot[t].end() , lst[x]); return *c == lst[p] ? *--c : *c;}
		}
	}
}sam[2];

struct BIT{
#define lb(x) x & -x
	int arr[_];
	void add(int x , int v){while(x <= 2e5){arr[x] += v; x += lb(x);}}
	int qry(int x){int sum = 0; while(x){sum += arr[x]; x -= lb(x);} return sum;}
}tr[2] , fkmp;

namespace kmp{
	int nxt1[_] , nxt2[_]; VI ed1[_] , ed2[_] , q[_];

	void pre(string str , int* nxt , VI *ed){
		nxt[0] = -1; str.insert(str.begin() , 1); ed[0].clear();
		for(int i = 1 ; i < str.size() ; ++i){
			int t = nxt[i - 1]; while(~t && str[t + 1] != str[i]) t = nxt[t];
			ed[i].clear(); ed[nxt[i] = t + 1].pb(i);
		}
	}

	int dfn[_] , rdfn[_] , ts;
	void dfs1(int x){dfn[x] = rdfn[x] = ++ts; for(auto t : ed2[x]){dfs1(t); rdfn[x] = rdfn[t];}}
	void dfs2(int x , int l){
		fkmp.add(rdfn[l - x] + 1 , -1); fkmp.add(dfn[l - x] , 1);
		for(auto t : q[x]) ans[t] += fkmp.qry(dfn[qrl[t][1]]);
		for(auto t : ed1[x]) dfs2(t , l);
		q[x].clear(); fkmp.add(rdfn[l - x] + 1 , 1); fkmp.add(dfn[l - x] , -1);
	}
	
	void work(string s1 , string s2 , VI qry){
		pre(s1 , nxt1 , ed1); pre(s2 , nxt2 , ed2);
		for(auto t : qry) q[qrl[t][0]].pb(t);
		ts = 0; dfs1(0); dfs2(0 , s1.size());
	}
}

namespace tree{
	vector < PII > ed[_];
	void input(){
		int x , y; char c; for(int i = 1 ; i < N ; ++i){cin >> x >> y >> c; c -= 'a'; ed[x].pb(PII(y , c)); ed[y].pb(PII(x , c));}
	}

	int nsz , mn , mnid; bool vis[_];
	void getsz(int x){++nsz; vis[x] = 1; for(auto t : ed[x]) if(!vis[t.st]) getsz(t.st); vis[x] = 0;}
	int getrt(int x){
		int sz = 1 , mx = 0; vis[x] = 1;
		for(auto t : ed[x]) if(!vis[t.st]){int v = getrt(t.st); sz += v; mx = max(mx , v);}
		mx = max(mx , nsz - sz); if(mn > mx){mn = mx; mnid = x;} vis[x] = 0; return sz;
	}

	int bel[_]; VI pot[_]; vector < PII > q[_];
	void rbel(int x , int v){bel[x] = v; vis[x] = 1; for(auto t : ed[x]) if(!vis[t.st]) rbel(t.st , v); vis[x] = 0;}

	void dfs(int x , int u0 , int u1 , int l0 , int l1 , bool f0 , bool f1){
		int p0 = sam[0].dfn[sam[0].lst[u0] == l0 ? u0 : sam[0].fa[u0]] ,
			p1 = sam[1].dfn[sam[1].lst[u1] == l1 ? u1 : sam[1].fa[u1]];
		vis[x] = 1; tr[0].add(p0 , 1); tr[1].add(p1 , 1); if(f0) sam[0].push(u0 , l0); if(f1) sam[1].push(u1 , l1);
		
		for(auto t : q[x]){
			int x = t.st , f = t.nd; PII p = sam[f].qrge(id[qr[x].c][f]);
			ans[x] += tr[f].qry(p.nd - 1) - tr[f].qry(p.st - 1); qrl[x][f ^ 1] = sam[f].qry(id[qr[x].c][f]);
		}
		q[x].clear();
		for(auto t : ed[x])
			if(!vis[t.st]){
				PII p = sam[0].go(u0 , l0 , t.nd) , q = sam[1].go(u1 , l1 , t.nd);
				dfs(t.st , p.st , q.st , p.nd , q.nd , f0 & (p.nd == l0 + 1) , f1 & (q.nd == l1 + 1));
			}
		vis[x] = 0; tr[0].add(p0 , -1); tr[1].add(p1 , -1); if(f0) sam[0].pop(u0); if(f1) sam[1].pop(u1);
	}

	void divide(int x){
		VI qry = pot[x]; nsz = 0; mn = 1e9; pot[x].clear(); getsz(x); getrt(x);
		x = mnid; vis[x] = 1; bel[x] = 0; for(auto t : ed[x]) if(!vis[t.st]) rbel(t.st , t.st);
		for(auto t : qry)
			if(bel[qr[t].a] == bel[qr[t].b]) pot[bel[qr[t].a]].pb(t);
			else{q[qr[t].a].pb(PII(t , 1)); q[qr[t].b].pb(PII(t , 0));}
		dfs(x , 1 , 1 , 0 , 0 , 1 , 1); vis[x] = 1;
		for(auto t : ed[x]) if(!vis[t.st]) divide(t.st);
	}
}

int main(){
	cin >> N >> M >> Q; tree::input();
	for(int i = 1 ; i <= M ; ++i){
		cin >> str[i][0]; str[i][1] = str[i][0]; reverse(str[i][1].begin() , str[i][1].end());
		id[i][0] = sam[0].ins(str[i][0]); id[i][1] = sam[1].ins(str[i][1]);
	}
	sam[0].build(); sam[1].build(); VI &qry = tree::pot[1]; static VI pot[_];
	for(int i = 1 ; i <= Q ; ++i){cin >> qr[i].a >> qr[i].b >> qr[i].c; qry.pb(i); pot[qr[i].c].pb(i);}
	tree::divide(1); for(int i = 1 ; i <= M ; ++i) kmp::work(str[i][0] , str[i][1] , pot[i]);
	for(int i = 1 ; i <= Q ; ++i) printf("%d\n" , ans[i]);
	return 0;
}