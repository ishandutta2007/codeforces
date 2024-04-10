#include<bits/stdc++.h>
using namespace std;

int N , K , Q , val[100053][13] , id[100053][13]; bitset < 4096 > arr[100053];

int main(){
	ios::sync_with_stdio(0); cin >> N >> K >> Q; int tk = K;
	for(int i = 1 ; i <= K ; ++i) for(int j = 1 ; j <= N ; ++j){cin >> val[j][i]; id[j][i] = i;}
	
	for(int i = 1 ; i <= N ; ++i) sort(id[i] + 1 , id[i] + K + 1 , [&](int p , int q){return val[i][p] < val[i][q];});
	for(int j = 1 ; j <= K ; ++j) for(int i = 0 ; i < 1 << K ; ++i) arr[j][i] = i >> (j - 1) & 1;
	for(int i = 1 ; i <= Q ; ++i){
		int op , x , y; cin >> op >> x >> y;
		if(op == 3){
			int now = (1 << tk) - 1;
			for(int p = 1 ; p <= tk ; ++p){now ^= 1 << (id[y][p] - 1); if(!arr[x][now]){printf("%d\n" , val[y][id[y][p]]); break;}}
		}else arr[++K] = op == 1 ? arr[x] | arr[y] : arr[x] & arr[y];
	}
	
	return 0;
}