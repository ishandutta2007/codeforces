#include<bits/stdc++.h>
using namespace std;

const int _ = 4e5 + 7;
set < pair < int , int > > Edge; int N , M , S[_] , T[_] , W[_];

int ch[_][2] , fa[_] , sz[_] , nsz[_] , lsz[_] , mx[_] , mxid[_] , val[_]; bool mrk[_];
void upd(int x){
	sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + nsz[x] + lsz[x];
	mx[x] = max(max(mx[ch[x][0]] , mx[ch[x][1]]) , val[x]);
	mxid[x] = (val[x] == mx[x] ? x : (mx[ch[x][0]] == mx[x] ? mxid[ch[x][0]] : mxid[ch[x][1]]));
}
void mark(int x){swap(ch[x][0] , ch[x][1]); mrk[x] ^= 1;}
void down(int x){if(mrk[x]){mark(ch[x][0]); mark(ch[x][1]); mrk[x] = 0;}}

bool nrt(int x){return ch[fa[x]][0] == x || ch[fa[x]][1] == x;}
bool son(int x){return ch[fa[x]][1] == x;}
void rot(int x){
	bool f = son(x); int y = fa[x] , z = fa[y] , w = ch[x][f ^ 1];
	fa[x] = z; if(nrt(y)) ch[z][son(y)] = x;
	fa[y] = x; ch[x][f ^ 1] = y; ch[y][f] = w; if(w) fa[w] = y;
	upd(y);
}

void dall(int x){if(nrt(x)) dall(fa[x]); down(x);}
void splay(int x){dall(x); while(nrt(x)){if(nrt(fa[x])) rot(son(fa[x]) == son(x) ? fa[x] : x); rot(x);} upd(x);}
void access(int x){for(int y = 0 ; x ; y = x , x = fa[x]){splay(x); lsz[x] += sz[ch[x][1]] - sz[y]; ch[x][1] = y; upd(x);}}
int fdrt(int x){access(x); splay(x); while(ch[x][0]) down(x = ch[x][0]); splay(x); return x;}
void mkrt(int x){access(x); splay(x); mark(x);}
void link(int x , int y){mkrt(x); access(y); splay(y); fa[x] = y; lsz[y] += sz[x]; upd(y);}
void split(int x , int y){mkrt(x); access(y); splay(y);}
void cut(int x , int y){split(x , y); ch[y][0] = fa[x] = 0; upd(y);}
int getsz(int x){access(x); splay(x); return sz[x];}

int main(){
	ios::sync_with_stdio(0); cin >> N >> M; int cnt = N; for(int i = 1 ; i <= N ; ++i) nsz[i] = sz[i] = 1;
	for(int i = 1 ; i <= M ; ++i){
		int u , v , w; cin >> u >> v >> w; S[i] = u; T[i] = v;
		mxid[N + i] = N + i; val[N + i] = W[i] = w;
		if(fdrt(u) != fdrt(v)){
			int p = getsz(u) , q = getsz(v); cnt -= (p & 1) + (q & 1) - ((p + q) & 1);
			link(u , N + i); link(v , N + i); Edge.insert(make_pair(w , i));
		}else{
			split(u , v);
			if(mx[ch[v][0]] > w){
				int t = mxid[ch[v][0]] - N; cut(S[t] , t + N); cut(T[t] , t + N); link(u , N + i); link(v , N + i);
				Edge.erase(make_pair(W[t] , t)); Edge.insert(make_pair(w , i));
			}
		}
		if(cnt) cout << "-1\n";
		else{
			while(!Edge.empty()){
				int t = (--Edge.end())->second;
				split(S[t] , T[t]); if(sz[S[t]] & 1) break;
				cut(S[t] , N + t); cut(T[t] , N + t); Edge.erase(--Edge.end());
			}
			cout << (--Edge.end())->first << '\n';
		}
	}
	return 0;
}