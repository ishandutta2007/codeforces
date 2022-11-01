#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){
		a = a * 10 + c - 48; c = getchar();
	}
	return f ? -a : a;
}

const int _ = 3e5 + 7;
int cnt , N , M , arr[_] , lsh[_] , id[_] , L[_] , R[_] , ans[_]; vector < int > Q[_] , pos[_];

namespace segt{
	int mn[_ << 2];

#define mid ((l + r) >> 1)
#define lch (x << 1)
#define rch (x << 1 | 1)
	
	void clear(){memset(mn , 0x3f , sizeof(mn));}
	
	void modify(int x , int l , int r , int tar , int val){
		mn[x] = min(mn[x] , val); if(l == r) return;
		mid >= tar ? modify(lch , l , mid , tar , val) : modify(rch , mid + 1 , r , tar , val);
	}
	
	int qry(int x , int l , int r , int L , int R){
		if(l >= L && r <= R) return mn[x];
		int mn = 1e9;
		if(mid >= L) mn = qry(lch , l , mid , L , R);
		if(mid < R) mn = min(mn , qry(rch , mid + 1 , r , L , R));
		return mn;
	}
}using namespace segt;

int main(){
	N = read(); segt::clear(); for(int i = 1 ; i <= N ; ++i) arr[i] = lsh[i] = read();
	M = read(); for(int i = 1 ; i <= M ; ++i){L[i] = read(); R[i] = read(); Q[R[i]].push_back(i);}
	sort(lsh + 1 , lsh + N + 1); cnt = unique(lsh + 1 , lsh + N + 1) - lsh - 1;
	for(int i = 1 ; i <= N ; ++i) id[i] = lower_bound(lsh + 1 , lsh + cnt + 1 , arr[i]) - lsh;
	for(int i = N , cur , t ; i ; --i){
		cur = cnt;
		while((t = segt::qry(1 , 1 , cnt , id[i] , cur)) <= N){
			pos[t].push_back(i); if(id[t] == id[i]) break;
			cur = upper_bound(lsh + 1 , lsh + cnt + 1 , (arr[i] + arr[t]) / 2) - lsh - 1;
		}
		cur = 1;
		while((t = segt::qry(1 , 1 , cnt , cur , id[i])) <= N){
			pos[t].push_back(i); if(id[t] == id[i]) break;
			cur = lower_bound(lsh + 1 , lsh + cnt + 1 , (arr[i] + arr[t] + 1) / 2) - lsh;
		}
		segt::modify(1 , 1 , cnt , id[i] , i);
	}
	segt::clear();
	for(int i = 1 ; i <= N ; ++i){
		for(auto t : pos[i]) segt::modify(1 , 1 , N , t , abs(arr[i] - arr[t]));
		for(auto t : Q[i]) ans[t] = segt::qry(1 , 1 , N , L[t] , i);
	}
	for(int i = 1 ; i <= M ; ++i) printf("%d\n" , ans[i]);
	return 0;
}