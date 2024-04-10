#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}

#define pii pair < int , int >
const int _ = 5e5 + 7; int N , M , Q , K , S[_] , T[_] , I[_] , C[_] , curS[_] , curT[_] , suf[_]; vector < int > node[53] , id[53]; int cnode;
int sz[_ << 1] , fa[_ << 1] , vl[_ << 1]; void init(){for(int i = 1 ; i <= cnode ; ++i) sz[fa[i] = i] = 1;}
pii find(int x){int val = 0; while(x != fa[x]){val ^= vl[x]; x = fa[x];} return make_pair(x , val);}

vector < int > history;
void merge(int p , int q){
	pii l = find(p) , r = find(q); if(l.first == r.first) return;
	if(sz[l.first] < sz[r.first]){swap(l , r);} fa[r.first] = l.first; sz[l.first] += sz[r.first];
	history.push_back(r.first); vl[r.first] = l.second ^ r.second ^ 1;
}

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
vector < pii > edge[_ << 2];
void push(int x , int l , int r , int L , int R , pii v){
	if(L > R) return;
	if(l >= L && r <= R) return edge[x].push_back(v);
	if(mid >= L) push(lch , l , mid , L , R , v);
	if(mid < R) push(rch , mid + 1 , r , L , R , v);
}

void divide(int x , int l , int r){
	for(auto t : edge[x]) merge(t.first , t.second);
	vector < int > pt = history; history.clear();
	if(l == r){
		int p = id[C[l]][lower_bound(node[C[l]].begin() , node[C[l]].end() , S[I[l]]) - node[C[l]].begin()] ,
			q = id[C[l]][lower_bound(node[C[l]].begin() , node[C[l]].end() , T[I[l]]) - node[C[l]].begin()];
		pii x = find(p) , y = find(q);
		if(x != y){puts("YES"); push(1 , 1 , Q , l + 1 , suf[l] , pii(curS[I[l]] = p , curT[I[l]] = q));}
		else{puts("NO"); if(curS[I[l]]) push(1 , 1 , Q , l + 1 , suf[l] , pii(curS[I[l]] , curT[I[l]]));}
	}else{divide(lch , l , mid); divide(rch , mid + 1 , r);}
	reverse(pt.begin() , pt.end()); for(auto x : pt){sz[fa[x]] -= sz[x]; fa[x] = x;}
}

int main(){
	N = read(); M = read(); K = read(); Q = read(); for(int i = 1 ; i <= M ; ++i){S[i] = read(); T[i] = read();}
	for(int i = 1 ; i <= Q ; ++i){I[i] = read(); C[i] = read(); node[C[i]].push_back(S[I[i]]); node[C[i]].push_back(T[I[i]]);}

	static int to[_]; for(int i = 1 ; i <= M ; ++i){to[i] = Q + 1;} for(int i = Q ; i ; --i){suf[i] = to[I[i]]; to[I[i]] = i;}
	for(int i = 1 ; i <= K ; ++i){
		sort(node[i].begin() , node[i].end()); node[i].resize(unique(node[i].begin() , node[i].end()) - node[i].begin());
		for(int j = 0 ; j < node[i].size() ; ++j) id[i].push_back(++cnode);
	}init(); divide(1 , 1 , Q); return 0;
}