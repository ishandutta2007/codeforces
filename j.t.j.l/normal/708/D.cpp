#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;
const ll inf = 1e9 + 7;
const ll _in = 1e8;

class Network {
public:
	typedef long long VAL;    //  
	static const int SIZE = 1005;       //  
	static const int INF = 1000000007;  //  
	typedef struct ARC { int t, c; VAL w; ARC* o; }*PTR;
	ARC arc[200005];    //  
	PTR now[SIZE], e[SIZE];      // cnt[]l[] 
	int cnt[SIZE], l[SIZE], r[SIZE], edge; // now[]e[] 
	VAL sum;   // sum 
	void clear(){ memset(e, edge = sum = 0, sizeof(e)); }           //  
	ARC& REV(PTR x){ return arc[(x - arc) ^ 1]; }                 //  
	// STspfa_johnson 
	int flow(int S, int T){ return spfa_johnson(S, T, INF); }
	// xycw 
	PTR add_edge(int x, int y, int c, VAL w = 0){
	//	cout<<"QAQ:   "<<x<<' '<<y<<' '<<c<<' '<<w<<endl;
		e[x] = &(arc[edge++] = (ARC){ y, c, +w, e[x] });
		e[y] = &(arc[edge++] = (ARC){ x, 0, -w, e[y] });
		return e[x];
	}
	// xyc0 
	PTR add_edge_simple(int x, int y, int c){
		e[x] = &(arc[edge++] = (ARC){ y, c, 0, e[x] });
		e[y] = &(arc[edge++] = (ARC){ x, c, 0, e[y] });
		return e[x];
	}
	// xylohiw 
	// SIZE-2SIZE-1 
	PTR add_edge_bounded(int x, int y, int lo, int hi, VAL w = 0){
		add_edge(SIZE - 2, y, lo, w);
		add_edge(x, SIZE - 1, lo, 0);
		return add_edge(x, y, hi - lo, w);
	}
	// STnow[] 
	int aug(int S, int T, int& can){
		int x, z = T, use = can;
		for (x = S; x != T; x = now[x]->t) if (use>now[x]->c) use = now[z = x]->c;
		for (x = S; x != T; x = now[x]->t){
			now[x]->c -= use;
			REV(now[x]).c += use;
			sum += use*now[x]->w;
		}
		can -= use;
		return z;
	}
	//  
	int improved_sap(int S, int T, int can){ // can 
		if (S == T) return can;
		int in = can, x, m;
		memcpy(now, e, sizeof(now));
		memset(cnt, 0, sizeof(cnt));
		fill_n(l, SIZE, int(SIZE));
		for (int i = m = l[r[0] = T] = 0; i <= m; i++){
			cnt[l[x = r[i]]]++;
			for (PTR u = e[x]; u; u = u->o)
				if (l[u->t] == SIZE && REV(u).c) l[r[++m] = u->t] = l[x] + 1;
		}
		for (x = r[S] = S; l[S] != SIZE; x = r[x]){
		JMP:for (PTR& u = now[x]; u; u = u->o) if (l[u->t]<l[x] && u->c){
			r[u->t] = x;
			x = u->t == T ? aug(S, T, can) : u->t;
			if (x == T) return in; else goto JMP;
		}
			if (!--cnt[l[x]]) break; else l[x] = SIZE;
			for (PTR u = e[x]; u; u = u->o)
				if (l[u->t] + 1<l[x] && u->c) now[x] = u, l[x] = l[u->t] + 1;
			if (l[x] != SIZE) cnt[l[x]]++;
		}
		return in - can;
	}
	//  
	int spfa_johnson(int S, int T, int can){ // can 
		if (S == T) return can;
		int in = can, x, m;
		VAL phi[SIZE], len[SIZE], MAXW = 1000000007; //  
		memset(l, 0, sizeof(l));
		fill_n(phi, SIZE, MAXW);
		phi[r[0] = T] = 0;
		for (int i = m = 0; i <= m; i++){ // SPFA 
			l[x = r[i%SIZE]] = 0;
			for (PTR u = e[x]; u; u = u->o){ // EPS 
				if (phi[x] + REV(u).w >= phi[u->t] || !REV(u).c) continue;
				phi[u->t] = phi[x] + REV(u).w;
				if (!l[u->t]) l[r[++m%SIZE] = u->t] = 1;
			}
		}
		do{
			typedef pair<VAL, int> TPL;
			priority_queue<TPL> q;
			fill_n(len, SIZE, MAXW);
			memset(l, 0, sizeof(l));
			q.push(TPL(len[T] = 0, T));
			while (q.size()){
				x = q.top().second; q.pop();
				if (!l[x]) l[x] = 1; else continue;
				for (PTR u = e[x]; u; u = u->o){
					if (!REV(u).c || l[u->t]) continue;
					VAL at = len[x] + phi[x] + REV(u).w - phi[u->t];
					if (at >= len[u->t]) continue; // EPS 
					len[u->t] = at;
					now[u->t] = &REV(u);
					q.push(TPL(-at, u->t));
				}
			}
			for (x = 0; x<SIZE; x++) phi[x] += len[x];
		} while (phi[S]<MAXW && aug(S, T, can) != T);
		// phi[S]<MAXWphi[S]<0 
		return in - can;
	}
	//  
	// (T,S)=MAXFS->Tc 
	bool feasible_bounded(){
		flow(SIZE - 2, SIZE - 1);
		for (PTR u = e[SIZE - 2]; u; u = u->o) if (u->c) return false;
		return true;
	}
	// /-1 
	int max_flow_bounded(int S, int T){
		add_edge(T, S, INF);
		bool ok = feasible_bounded();
		int ret = e[S]->c;
		edge -= 2, e[S] = e[S]->o, e[T] = e[T]->o;
		return ok ? ret + flow(S, T) : -1;
	}
	int min_flow_bounded(int S, int T){
		flow(SIZE - 2, SIZE - 1);
		add_edge(T, S, INF);
		bool ok = feasible_bounded();
		int ret = e[S]->c;
		edge -= 2, e[S] = e[S]->o, e[T] = e[T]->o;
		return ok ? ret : -1;
	}
	//  
	void merge_bounded(){
		for (PTR u = e[SIZE - 1]; u; u = u->o) u->c = REV(u).c = 0;
		for (PTR u = e[SIZE - 2]; u; u = u->o){
			(u + 4)->c += u->c;
			(u + 5)->c += REV(u).c;
			u->c = REV(u).c = 0;
		}
	}
} Nico;

int n, m;

int fa[MAXN];
int vis[MAXN];

int getfather(int x){
	if (fa[x] == x) return x;
	else return fa[x] = getfather(fa[x]);
}

void read(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		fa[i] = 0;
	Nico.clear();
	ll ans = 0;
	for(int i = 1; i <= m; i++){
		int x, y, _c, _f;
		scanf("%d%d%d%d", &x, &y, &_c, &_f);
		if (_f <= _c){
			fa[x] += _f, fa[y] -= _f;
			Nico.add_edge(y, x, _f, 1);
		//	ans += _f;
			Nico.add_edge(x, y, _c - _f, 1);
			Nico.add_edge(x, y, _in, 2);
		}
		else{
			fa[x] += _f, fa[y] -= _f;
			ans += _f - _c;
			Nico.add_edge(y, x, _c, 1);
			Nico.add_edge(y, x, _f - _c, 0);
			Nico.add_edge(x, y, _in, 2);
		}
	}
	for(int i = 1; i <= n; i++)
		if (fa[i] < 0)
			Nico.add_edge(n+1, i, -fa[i], 0);
		else
			Nico.add_edge(i, n+2, fa[i], 0);
	Nico.add_edge(n, 1, _in, 0);
	Nico.flow(n + 1, n + 2);
//	cout<<ans<<' '<<Nico.sum<<endl;
	cout <<ans + Nico.sum<<endl;
}

void solve(){

}

void printans(){

}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}