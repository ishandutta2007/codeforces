#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

#define int long long
#define INF 1e15
inline int read(){
	int a = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}

const int MAXN = 1e5 + 7;

int N , K , W[MAXN] , g[MAXN];
int pre[MAXN] , suf[MAXN] , nxt[MAXN];
int stk[MAXN] , top;

namespace Tree{
#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
	int minP[MAXN << 2] , maxS[MAXN << 2] , ans[MAXN << 2];
	int mrk[MAXN << 2];

	void mark(int x , int cnt){
		mrk[x] += cnt;
		maxS[x] += cnt;
		ans[x] += cnt;
	}
	
	void pushdown(int x){
		mark(lch , mrk[x]); mark(rch , mrk[x]);
		mrk[x] = 0;
	}
	
	int calc(int x , int l , int r , int st){
		if(l == r) return minP[x] + st;
		pushdown(x);
		if(maxS[lch] >= st)
			return min(ans[x] , calc(lch , l , mid , st));
		return min(st + minP[lch] , calc(rch , mid + 1 , r , st));
	}
	
	void pushup(int x , int l , int r){
		maxS[x] = max(maxS[lch] , maxS[rch]);
		ans[x] = calc(rch , mid + 1 , r , maxS[lch]);
	}
	
	void build(int x , int l , int r){
		if(l != r){
			build(lch , l , mid);
			build(rch , mid + 1 , r);
			minP[x] = min(minP[lch] , minP[rch]);
			maxS[x] = max(maxS[lch] , maxS[rch]);
		}
		else{
			maxS[x] = suf[l];
			minP[x] = -suf[l];
		}
	}

	void modify(int x , int l , int r , int L , int R , int add){
		if(L > R) return;
		if(l >= L && r <= R){
			mark(x , add);
			return;
		}
		pushdown(x);
		if(mid >= L) modify(lch , l , mid , L , R , add);
		if(mid < R) modify(rch , mid + 1 , r , L , R , add);
		pushup(x , l , r);
	}
	
	int query2(int x , int l , int r , int st){
		if(l == r)
			return minP[x] + st > K ? 0 : l;
		pushdown(x);
		if(minP[rch] + st <= K) return query2(rch , mid + 1 , r , st);
		return query2(lch , l , mid , st);
	}
	
	int query1(int x , int l , int r , int st){
		if(l == r)
			return minP[x] + st > K ? 0 : l;
		pushdown(x);
		if(maxS[lch] <= st)
			return max(query2(lch , l , mid , st) , query1(rch , mid + 1 , r , st));
		else
			if(ans[x] <= K)
				return query1(rch , mid + 1 , r , maxS[lch]);
			else
				return query1(lch , l , mid , st);
		return 0;
	}
}

vector < int > ch[MAXN];
int ans = 1;
void dfs(int x){
	stk[++top] = x;
	if(x != N + 1){
		Tree::modify(1 , 1 , N , 1 , x - 1 , -INF);
		int l = 1 , r = top;
		while(l < r)
			pre[x - 1] - pre[stk[mid] - 1] <= K ? r = mid : l = mid + 1;
		Tree::modify(1 , 1 , N , stk[l - 1] - 1 , N , INF);
		Tree::modify(1 , 1 , N , nxt[x] - 1 , N , pre[x - 1] - pre[nxt[x] - 1]);
		ans = max(ans , Tree::query1(1 , 1 , N , -INF) - x + 1);
		Tree::modify(1 , 1 , N , stk[l - 1] - 1 , N , -INF);
		Tree::modify(1 , 1 , N , 1 , x - 1 , INF);
	}
	for(auto t : ch[x]) dfs(t);
	if(x != N + 1)
		Tree::modify(1 , 1 , N , nxt[x] - 1 , N , -(pre[x - 1] - pre[nxt[x] - 1]));
	--top;
}

signed main(){
	N = read(); K = read();
	stk[0] = N + 1;
	for(int i = 1 ; i < N ; ++i) W[i] = read();
	for(int i = 1 ; i <= N ; ++i) g[i] = read();
	for(int i = 1 ; i <= N ; ++i){
		pre[i] = pre[i - 1] + g[i] - W[i];
		suf[i] = suf[i - 1] + g[i] - W[i - 1];
	}
	for(int i = N ; i ; --i){
		while(top && pre[stk[top] - 1] >= pre[i - 1])
			--top;
		nxt[i] = stk[top];
		ch[nxt[i]].push_back(i);
		stk[++top] = i;
	}
	Tree::build(1 , 1 , N);
	top = 0;
	dfs(N + 1);
	cout << ans;
	return 0;
}