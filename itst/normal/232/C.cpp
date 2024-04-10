#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair < int , int >
int N , T , fib[103] , dis[103]; PII dis1[2][103];

PII solve1(int floor , int p , int id){
	//first:1->p second:D(floor)->p
	if(floor <= 2) return PII(p != 1 , p != fib[floor]);
	if(dis1[id][floor].first != -1) return dis1[id][floor];
	PII all;
	if(p <= fib[floor - 1]){
		PII ans = solve1(floor - 1 , p , id);
		all = PII(min(ans.first , ans.second + 2) , min(ans.first , ans.second) + dis[floor - 2] + 1);
	}
	else{all = solve1(floor - 2 , p - fib[floor - 1] , id); ++all.first;}
	return dis1[id][floor] = all;
}

int solve(int floor , int p , int q){
	if(floor <= 2) return p != q;
	if(p > fib[floor - 1] && q > fib[floor - 1])
		return solve(floor - 2 , p - fib[floor - 1] , q - fib[floor - 1]);
	if(p <= fib[floor - 1] && q <= fib[floor - 1]){
		PII x = solve1(floor - 1 , p , 0) , y = solve1(floor - 1 , q , 1);
		return min(solve(floor - 1 , p , q) , min(x.first + y.second , x.second + y.first) + 2);
	}
	PII P = solve1(floor - 1 , p , 0) , Q = solve1(floor - 2 , q - fib[floor - 1] , 1);
	return min(P.first , P.second) + Q.first + 1;
}

signed main(){
	ios::sync_with_stdio(0); cin >> T >> N; fib[1] = 2; fib[2] = 3;
	for(int i = 3 ; fib[i - 1] <= 3e16 && i <= N ; ++i) fib[i] = fib[i - 1] + fib[i - 2];
	while(N > 100 || !fib[N]) --N;
	dis[1] = dis[2] = 1; for(int i = 3 ; i <= N ; ++i) dis[i] = dis[i - 2] + 1;
	for(int i = 1 ; i <= T ; ++i){
		for(int j = 1 ; j <= N ; ++j) dis1[0][j] = dis1[1][j] = PII(-1 , -1);
		int p , q; cin >> p >> q; cout << solve(N , min(p , q) , max(p , q)) << endl;
	}
	return 0;
}