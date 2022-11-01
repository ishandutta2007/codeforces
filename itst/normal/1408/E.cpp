#include<bits/stdc++.h>
using namespace std;

int read(){
	int a = 0; char c = getchar(); bool f = 0; while(!isdigit(c)){f = c == '-'; c = getchar();}
	while(isdigit(c)){a = a * 10 + c - 48; c = getchar();} return f ? -a : a;
}

int M , N , A[100003] , B[100003] , fa[200003];
struct Edge{int s , t , w;}; vector < Edge > pot;
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

int main(){
	M = read(); N = read(); for(int i = 1 ; i <= M ; ++i) A[i] = read();
	for(int j = 1 ; j <= N ; ++j) B[j] = read();
	long long ans = 0;
	for(int i = 1 ; i <= M ; ++i){
		int S = read();
		for(int j = 1 ; j <= S ; ++j){
			int t = read(); pot.push_back((Edge){i , M + t , A[i] + B[t]});
			ans += A[i] + B[t];
		}
	}
	for(int i = 1 ; i <= M + N ; ++i) fa[i] = i;
	sort(pot.begin() , pot.end() , [&](Edge p , Edge q){return p.w > q.w;});
	for(auto t : pot)
		if(find(t.s) != find(t.t)){fa[find(t.s)] = find(t.t); ans -= t.w;}
	cout << ans;
	return 0;
}