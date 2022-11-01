// luogu-judger-enable-o2
#include<bits/stdc++.h>
//this code is written by Itst
using namespace std;

const int _ = 5e5 + 3;
namespace segTree{
	int Mx[_ << 3];

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
	
	void modify(int x , int l , int r , int tar , int val){
		Mx[x] = max(Mx[x] , val);
		if(l == r) return;
		mid >= tar ? modify(lch , l , mid , tar , val) : modify(rch , mid + 1 , r , tar , val);
	}

	int qry(int x , int l , int r , int L , int R){
		if(l >= L && r <= R) return Mx[x];
		int mx = 0;
		if(mid >= L) mx = qry(lch , l , mid , L , R);
		if(mid < R) mx = max(mx , qry(rch , mid + 1 , r , L , R));
		return mx;
	}
}
using segTree::qry;

namespace SAM{
	int id[_ << 1] , trs[_ << 1][26] , fa[_ << 1] , Lst[_ << 1] , cnt = 1 , lst = 1;

	void extend(int l , int c){
		int p = lst , t = ++cnt; lst = id[l] = t; Lst[t] = l;
		while(trs[p][c] == 0){trs[p][c] = t; p = fa[p];}
		if(!p){fa[t] = 1; return;}
		int q = trs[p][c];
		if(Lst[q] == Lst[p] + 1){fa[t] = q; return;}
		int k = ++cnt; Lst[k] = Lst[p] + 1; memcpy(trs[k] , trs[q] , sizeof(trs[k]));
		fa[k] = fa[q]; fa[q] = fa[t] = k;
		while(trs[p][c] == q){trs[p][c] = k; p = fa[p];}
	}

	vector < int > ch[_ << 1]; int dfn[_ << 1] , sz[_ << 1] , jump[_ << 1][22] , ts;
	
	void dfs(int x){
		dfn[x] = ++ts; sz[x] = 1;
		for(int i = 1 ; jump[x][i - 1] ; ++i)
			jump[x][i] = jump[jump[x][i - 1]][i - 1];
		for(auto t : ch[x]){
			jump[t][0] = x; dfs(t); sz[x] += sz[t];
		}
	}
	
	void init(){
		for(int i = 2 ; i <= cnt ; ++i) ch[fa[i]].push_back(i);
		dfs(1);
	}

	int qnode(int x , int len){
		for(int i = 20 ; i >= 0 ; --i)
			if(Lst[jump[x][i]] >= len) x = jump[x][i];
		return x;
	}
}
using SAM::dfn; using SAM::sz; using SAM::id; using SAM::qnode; using SAM::cnt;
int N , dp[_]; char S[_];

bool check(int pos){
	if(dp[pos] == 1) return 1;
	int p = qnode(id[pos] , dp[pos] - 1) , q = qnode(id[pos - 1] , dp[pos] - 1);
	return max(qry(1 , 1 , cnt , dfn[p] , dfn[p] + sz[p] - 1) , qry(1 , 1 , cnt , dfn[q] , dfn[q] + sz[q] - 1)) >= dp[pos] - 1;
}

int main(){
	scanf("%d %s" , &N , S + 1); reverse(S + 1 , S + N + 1);
	for(int i = 1 ; i <= N ; ++i) SAM::extend(i , S[i] - 'a');
	SAM::init(); int Mx = 0;
	for(int i = 1 ; i <= N ; ++i){
		dp[i] = dp[i - 1] + 1;
		while(!check(i)){
			--dp[i];
			segTree::modify(1 , 1 , cnt , dfn[id[i - dp[i]]] , dp[i - dp[i]]);
		}
		Mx = max(Mx , dp[i]);
	}
	cout << Mx;
	return 0;
}