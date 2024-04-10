#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int _ = 2e5 + 7;
struct SAM{
	int trs[_][26] , len[_] , fa[_] , end[_] , cnt , lst; bool isend[_];
	SAM(){cnt = lst = 1; isend[1] = 1; len[0] = -1;}
	
	void extend(int l , int c){
		int p = lst , t = ++cnt; len[t] = l; lst = end[l] = t; isend[t] = 1;
		while(p && !trs[p][c]){trs[p][c] = t; p = fa[p];}
		if(!p){fa[t] = 1; return;}
		int q = trs[p][c]; if(len[q] == len[p] + 1){fa[t] = q; return;}
		int x = ++cnt; memcpy(trs[x] , trs[q] , sizeof(trs[x]));
		len[x] = len[p] + 1; fa[x] = fa[q]; fa[q] = fa[t] = x;
		while(trs[p][c] == q){trs[p][c] = x; p = fa[p];}
	}
	int val(int x){return len[x] - len[fa[x]];}
	
	vector < int > ch[_];
	void init(){for(int i = 2 ; i <= cnt ; ++i) ch[fa[i]].push_back(i);}
	void build(char* str){for(int i = 1 ; str[i] ; ++i) extend(i , str[i] - 'a'); init();}
};

struct SAM1:SAM{
	int dfn[_] , up[_][20] , dep[_] , ts;
	
	void dfs(int x){
		dfn[x] = ++ts; for(int i = 1 ; up[x][i - 1] ; ++i) up[x][i] = up[up[x][i - 1]][i - 1];
		for(auto t : ch[x]){up[t][0] = x; dep[t] = dep[x] + 1; dfs(t);}
	}

	int LCA(int x , int y){
		if(dep[x] < dep[y]) swap(x , y);
		for(int i = 19 ; ~i ; --i) if(dep[x] - (1 << i) >= dep[y]) x = up[x][i];
		if(x == y) return len[x];
		for(int i = 19 ; ~i ; --i) if(up[x][i] != up[y][i]){x = up[x][i]; y = up[y][i];}
		return len[up[x][0]];
	}
}S2;

struct cmp{bool operator ()(int x , int y){return S2.dfn[x] < S2.dfn[y];}};
struct data{
	set < int , cmp > now; ll val;
	int size(){return now.size();}
	void swap(data &x){now.swap(x.now); std::swap(val , x.val);}
	void ins(int x){
		int mx = 0; now.insert(x); auto t = now.find(x);
		if(t != now.begin()) mx = S2.LCA(x , *((--t)++));
		if(++t != now.end()) mx = max(mx , S2.LCA(x , *t));
		val += S2.len[x] - mx;
	}
};
ll ans;
struct SAM2:SAM{
	void merge(data &a , data &b){
		if(a.size() < b.size()) a.swap(b);
		for(auto t : b.now) a.ins(t);
	}

	data now[_];
	void dfs(int x){
		if(isend[x] && len[x] <= len[lst] - 2) now[x].ins(S2.end[len[lst] - len[x] - 1]);
		for(auto t : ch[x]){dfs(t); merge(now[x] , now[t]);}
		ans += now[x].val * val(x);
	}
}S1;
char str[_];

int main(){
	scanf("%s" , str + 1); int L = strlen(str + 1);
	S1.build(str); reverse(str + 1 , str + L + 1); S2.build(str); S2.dfs(1);
	for(int i = 1 ; i <= S1.cnt ; ++i) ans += S1.val(i);
	for(int i = 1 ; i <= S1.cnt ; ++i) if(i != S1.lst) ans += S1.val(i);
	S1.dfs(1); cout << ans; return 0;
}