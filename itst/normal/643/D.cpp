#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll read(){
	ll a = 0; char c = getchar(); while(!isdigit(c)) c = getchar();
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return a;
}
const int _ = 1e5 + 7; int N , Q , deg[_] , to[_]; ll T[_] , sufsum[_] , mrk[_]; multiset < ll > val[_] , all;
ll calc(int x){return T[x] - T[x] / (deg[x] + 2) * (deg[x] + 1) + sufsum[x] + T[to[x]] / (deg[to[x]] + 2);}
void addall(int x){if(val[x].size()){all.insert(*val[x].begin() + mrk[x]); all.insert(*val[x].rbegin() + mrk[x]);}}
void delall(int x){if(val[x].size()){all.erase(all.find(*val[x].begin() + mrk[x])); all.erase(all.find(*val[x].rbegin() + mrk[x]));}}
void add(int x){delall(to[x]); val[to[x]].insert(calc(x) - mrk[to[x]]); addall(to[x]);}
void del(int x){delall(to[x]); val[to[x]].erase(val[to[x]].find(calc(x) - mrk[to[x]])); addall(to[x]);}

int main(){
	N = read(); Q = read(); for(int i = 1 ; i <= N ; ++i) T[i] = read();
	for(int i = 1 ; i <= N ; ++i){to[i] = read(); ++deg[to[i]];}
	for(int i = 1 ; i <= N ; ++i) sufsum[to[i]] += T[i] / (deg[i] + 2);
	for(int i = 1 ; i <= N ; ++i) add(i);
	for(int i = 1 ; i <= Q ; ++i){
		int op = read() , x , y;
		if(op == 3) printf("%lld %lld\n" , *all.begin() , *all.rbegin());
		else if(op == 2) printf("%lld\n" , calc(read()));
		else{
			x = read(); y = read();
			del(x); del(to[x]); del(to[to[x]]); sufsum[to[x]] -= T[x] / (deg[x] + 2); delall(to[x]);
			mrk[to[x]] -= T[to[x]] / (deg[to[x]] + 2); sufsum[to[to[x]]] -= T[to[x]] / (deg[to[x]] + 2);
			--deg[to[x]]; mrk[to[x]] += T[to[x]] / (deg[to[x]] + 2); sufsum[to[to[x]]] += T[to[x]] / (deg[to[x]] + 2);
			addall(to[x]); add(to[x]); add(to[to[x]]);
			
			to[x] = y; del(to[x]); del(to[to[x]]); sufsum[to[x]] += T[x] / (deg[x] + 2); delall(to[x]);
			mrk[to[x]] -= T[to[x]] / (deg[to[x]] + 2); sufsum[to[to[x]]] -= T[to[x]] / (deg[to[x]] + 2);
			++deg[to[x]]; mrk[to[x]] += T[to[x]] / (deg[to[x]] + 2); sufsum[to[to[x]]] += T[to[x]] / (deg[to[x]] + 2);
			addall(to[x]); add(to[x]); add(to[to[x]]); add(x);
		}
	}
	return 0;
}