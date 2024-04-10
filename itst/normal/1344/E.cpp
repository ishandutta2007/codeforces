#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7; 
struct Edge{int end , upEd , w;}Ed[_ << 1]; int head[_] , cntEd;
long long dep[_]; vector < pair < long long , long long > > val;
void addEd(int a , int b , int c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}

void dfs(int x , int p){
	for(int i = head[x] ; i ; i = Ed[i].upEd){
		dep[Ed[i].end] = dep[x] + Ed[i].w;
		dfs(Ed[i].end , x);
	}
}

int ch[_][2] , fa[_] , lst[_] , mrk[_];
bool son(int x){return ch[fa[x]][1] == x;}
bool nroot(int x){return ch[fa[x]][0] == x || ch[fa[x]][1] == x;}
void down(int x){if(mrk[x]){lst[ch[x][0]] = lst[ch[x][1]] = mrk[ch[x][0]] = mrk[ch[x][1]] = mrk[x]; mrk[x] = 0;}}
void down_all(int x){if(nroot(x)) down_all(fa[x]); down(x);}

void rot(int x){
	bool f = son(x); int y = fa[x] , z = fa[y] , w = ch[x][f ^ 1];
	fa[x] = z; if(nroot(y)) ch[z][son(y)] = x;
	fa[y] = x; ch[x][f ^ 1] = y; ch[y][f] = w; if(w) fa[w] = y;
}

void splay(int x){
	down_all(x);
	while(nroot(x)){
		if(nroot(fa[x])) rot(son(x) == son(fa[x]) ? fa[x] : x);
		rot(x);
	}
}

void access(int x , long long tms){
	splay(x); int y , pre = x;
	for(y = ch[x][1] ; x ; y = x , x = fa[x]){
		ch[x][1] = y;
		if(fa[x]){splay(fa[x]); val.push_back(make_pair(lst[fa[x]] ? lst[fa[x]] + dep[fa[x]] + 1 : 1 , tms + dep[fa[x]]));}
	}
	splay(pre); lst[ch[pre][0]] = mrk[ch[pre][0]] = tms;
}

int main(){
	int N , M; cin >> N >> M;
	for(int i = 1 ; i < N ; ++i){
		int p , q , w; cin >> p >> q >> w; addEd(p , q , w);
		fa[q] = p; ch[p][1] = q;
	}
	dfs(1 , 0); for(int i = 1 ; i <= M ; ++i){int s , t; cin >> s >> t; access(s , t);}
	sort(val.begin() , val.end()); int sum = 0 , pos = 0; long long tms = 0;
	priority_queue < long long , vector < long long > , greater < long long > > q;
	priority_queue < long long > pot2;
	while(pos < val.size() || !q.empty()){
		if(q.empty()) tms = val[pos].first; else ++tms;
		while(pos < val.size() && val[pos].first == tms) q.push(val[pos++].second);
		if(q.top() < tms){
			while(pot2.size() && pot2.top() >= tms - 1){--sum; pot2.pop();}
			cout << tms - 1 << ' ' << sum << endl; return 0;
		}
		pot2.push(q.top()); q.pop(); ++sum;
	}
	cout << -1 << ' ' << sum << endl;
	return 0;
}