#include<bits/stdc++.h>
using namespace std;

const int _ = 1e6 + 7; int N , Q , A[_] , lst[_] , prm[_] , cprm , fa[_] , id[_];
bool nprm[_]; unordered_set < int > pot[_ / 8];
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}
void sieve(){
	for(int i = 2 ; i <= 1e6 + 1 ; ++i){
		if(!nprm[i]){prm[++cprm] = i; lst[i] = i; fa[i] = i;}
		for(int j = 1 ; prm[j] * i <= 1e6 + 1 ; ++j){lst[prm[j] * i] = prm[j]; nprm[prm[j] * i] = 1; if(i % prm[j] == 0) break;}
	}
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> Q; sieve();
	for(int i = 1 ; i <= N ; ++i){
		cin >> A[i]; int p = A[i] , pre = 0;
		while(p != 1){int x = lst[p]; p /= x; if(pre){fa[find(x)] = find(pre);} pre = x;}
	}
	for(int i = 1 , cid = 0 ; i <= 1e6 + 1 ; ++i) if(fa[i] == i) id[i] = ++cid;
	for(int i = 1 ; i <= N ; ++i){
		int p = id[find(lst[A[i]])] , r = A[i] + 1; vector < int > pot; pot.push_back(p);
		while(r != 1){int x = lst[r]; r /= x; pot.push_back(id[find(x)]);}
		for(auto x : pot) for(auto y : pot) ::pot[x].insert(y);
	}
	while(Q--){
		int x , y; cin >> x >> y; x = id[find(lst[A[x]])]; y = id[find(lst[A[y]])];
		cout << (x == y ? 0 : (pot[x].find(y) == pot[x].end() ? 2 : 1)) << '\n';
	}
	return 0;
}