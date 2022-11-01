#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define ll long long
#define pii pair < int , int >
const int _ = 3e5 + 7 , __ = _ * 19; vector < int > nxt[_]; int N , M , dep[_];
void qdep(int x , int p){dep[x] = dep[p] + 1; for(auto &t : nxt[x]) if(t != p) qdep(t , x);}

#define mid ((l + r) >> 1)
#define lch (ch[x][0])
#define rch (ch[x][1])
ll mrk[__] , mn[__]; int ch[__][2] , cnode;
void mark(int x , ll v){if(x){mrk[x] = min(mrk[x] + v , mn[0]); mn[x] = min(mn[x] + v , mn[0]);}}
void down(int x){if(x && mrk[x]){mark(lch , mrk[x]); mark(rch , mrk[x]); mrk[x] = 0;}}

void mdf(int &x , int l , int r , int t , ll v , bool type){
	if(!type && !x){x = ++cnode;} if(l == r){mn[x] = type ? v : min(mn[x] , v); return;}
	down(x); mid >= t ? mdf(lch , l , mid , t , v , type) : mdf(rch , mid + 1 , r , t , v , type); mn[x] = min(mn[lch] , mn[rch]);
}

int merge(int p , int q){
	if(!p || !q){return p + q;}
	mn[p] = min(mn[p] , mn[q]); down(p); down(q);
	ch[p][0] = merge(ch[p][0] , ch[q][0]); ch[p][1] = merge(ch[p][1] , ch[q][1]);  return p;
}

vector < pii > route[_];
int dfs(int x , int p){
	ll vlsum = 0; int rt = 0;
	for(auto t : nxt[x])
		if(t != p){
			int R = dfs(t , x);
			mdf(R , 1 , N , dep[x] + 1 , mn[0] , 1);
			ll v = mn[R]; mark(rt , v); mark(R , vlsum);
			vlsum = min(mn[0] , vlsum + v); rt = merge(rt , R);
		}
	for(auto t : route[x]) mdf(rt , 1 , N , t.first , vlsum + t.second , 0);
	if(x == 1) cout << (vlsum <= 1e16 ? vlsum : -1);
	return rt;
}

int main(){
	N = read(); M = read(); for(int i = 1 ; i < N ; ++i){int x = read() , y = read(); nxt[x].push_back(y); nxt[y].push_back(x);}
	qdep(1 , 0); for(int i = 1 ; i <= M ; ++i){int x = read() , y = read() , w = read(); route[x].push_back(pii(dep[y] , w));}
	memset(mn , 0x3f , sizeof(mn)); dfs(1 , 0); return 0;
}