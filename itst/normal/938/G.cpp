#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return a;
}

const int _ = 4e5 + 3;
struct BASE{
	int val[30];
	BASE(){memset(val , 0 , sizeof(val));}
	
	void insert(int x){
		for(int i = 29 ; i >= 0 ; --i)
			if(x >> i & 1)
				if(val[i]) x ^= val[i];
				else return (void)(val[i] = x);
	}

	int query(int x){
		for(int i = 29 ; i >= 0 ; --i)
			if(x >> i & 1) x ^= val[i];
		return x;
	}
};
struct edge{int s , t , w;};
#define PII pair < int , int >
#define st first
#define nd second
struct dsu{
	int fa[_] , val[_] , sz[_];
	void init(int x){
		for(int i = 1 ; i <= x ; ++i){
			fa[i] = i; val[i] = 0; sz[i] = 1;
		}
	}

	PII find(int x){
		if(x == fa[x]) return PII(x , 0);
		PII t = find(fa[x]);
		return PII(t.st , t.nd ^ val[x]);
	}
	
	int merge(int x , int y , int num){
		PII p = find(x) , q = find(y);
		if(p.st == q.st) return 0;
		if(sz[p.st] < sz[q.st]) swap(p , q);
		fa[q.st] = p.st; val[q.st] = num ^ q.nd ^ p.nd;
		sz[p.st] += sz[q.st]; return q.st;
	}
	
	void erase(int x){
		sz[fa[x]] -= sz[x]; fa[x] = x; val[x] = 0;
	}
}now;
map < PII , int > to; vector < edge > add[_ << 2];
int tms[_] , val[_] , que[_][2] , N , M , Q , cnt;

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
void addE(int x , int l , int r , int L , int R , edge now){
	if(l >= L && r <= R)
		return add[x].push_back(now);
	if(mid >= L) addE(lch , l , mid , L , R , now);
	if(mid < R) addE(rch , mid + 1 , r , L , R , now);
}

void solve(int x , int l , int r , BASE num){
	stack < int > del;
	for(auto t : add[x]){
		int tp = now.merge(t.s , t.t , t.w);
		if(tp) del.push(tp);
		else num.insert(t.w ^ now.find(t.s).nd ^ now.find(t.t).nd);
	}
	if(l == r){
		if(que[l][0]) printf("%d\n" , num.query(now.find(que[l][0]).nd ^ now.find(que[l][1]).nd));
	}
	else{solve(lch , l , mid , num); solve(rch , mid + 1 , r , num);}
	while(!del.empty()){now.erase(del.top()); del.pop();}
}

int main(){
	now.init(N = read()); M = read();
	int a , b; map < PII , int > :: iterator it;
	for(int i = 1 ; i <= M ; ++i){
		a = read(); b = read();
		val[to[PII(a , b)] = ++cnt] = read();
		tms[cnt] = 1;
	}
	Q = read();
	for(int i = 1 ; i <= Q ; ++i)
		switch(read()){
		case 1:
			a = read(); b = read();
			val[to[PII(a , b)] = ++cnt] = read();
			tms[cnt] = i; break;
		case 2:
			a = read(); b = read();
			it = to.find(PII(a , b));
			addE(1 , 1 , Q , tms[it->nd] , i , (edge){a , b , val[it->nd]});
			to.erase(it); break;
		case 3:
			que[i][0] = read(); que[i][1] = read();
		}
	for(auto t : to)
		addE(1 , 1 , Q , tms[t.nd] , Q , (edge){t.st.st , t.st.nd , val[t.nd]});
	solve(1 , 1 , Q , BASE());
	return 0;
}