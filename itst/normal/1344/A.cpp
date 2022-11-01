#include<bits/stdc++.h>
using namespace std;

int N , A[200003] , T;

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 0 ; i < N ; ++i) cin >> A[i];
		bool vis[200003]; memset(vis , 0 , sizeof(bool) * N);
		bool flg = 0; for(int i = 0 ; i < N ; ++i){int val = ((A[i] + i) % N + N) % N; flg |= vis[val]; vis[val] = 1;}
		puts(flg ? "NO" : "YES");
	}
	return 0;
}