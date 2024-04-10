#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<random>
#include<iomanip>
#include<cmath>
#include<cassert>
//This code is written by Itst
using namespace std;

#define int long long

int read(){
	int a = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return a;
}

const int _ = 5e5 + 3;
int num[_] , ans[_] , N , M , Q;

namespace segTree{
	int sum[_ << 2];

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)

	void insert(int x , int l , int r , int tar){
		++sum[x];
		if(l == r) return;
		if(mid >= tar) insert(lch , l , mid , tar);
		else insert(rch , mid + 1 , r , tar);
	}

	int query(int x , int l , int r , int sz){
		if(l == r) return l;
		if(sum[lch] >= sz) return query(lch , l , mid , sz);
		else return query(rch , mid + 1 , r , sz - sum[lch]);
	}
}
using namespace segTree;

signed main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
	#endif
	#define PII pair < int , int >
	#define st first
	#define nd second
	ios::sync_with_stdio(0);
	N = read(); M = read(); Q = read();
	vector < PII > que , city; priority_queue < PII > q;
	for(int i = 1 ; i <= N ; ++i){int a = read(); ++num[a];}
	for(int i = 1 ; i <= M ; ++i)
		city.push_back(PII(num[i] , i));
	sort(city.begin() , city.end());
	for(int i = 1 ; i <= Q ; ++i){
		int k = read(); que.push_back(PII(k - N , i));
	}
	sort(que.begin() , que.end());
	int cnt = 1 , all = 0 , cur = city[0].st;
	for(int i = 1 ; i < M ; ++i) q.push(PII(-city[i].st , city[i].nd));
	q.push(PII(-2e18 , 0));
	segTree::insert(1 , 1 , M , city[0].nd);
	for(auto t : que){
		while(q.size() && (long double)1.0 * (-q.top().st - cur) * cnt + all < t.st){
			all += (-q.top().st - cur) * cnt; ++cnt; cur = -q.top().st;
			segTree::insert(1 , 1 , M , q.top().nd); q.pop();
		}
		ans[t.nd] = segTree::query(1 , 1 , M , (t.st - all + cnt - 1) % cnt + 1);
	}
	for(int i = 1 ; i <= Q ; ++i) 
		printf("%I64d\n" , ans[i]);
	return 0;
}