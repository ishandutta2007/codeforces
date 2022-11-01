#include<bits/stdc++.h>
using namespace std;
bitset < 2003 > rc[1 << 16]; int N , K , val[16] , b[16];
int main(){
	cin >> N >> K; rc[0].set(0); for(int i = 0 ; i < N ; ++i) cin >> val[i];
	for(int i = 1 ; i < 1 << N ; ++i){
		for(int j = 0 ; j < N ; ++j) if(i >> j & 1) rc[i] |= rc[i ^ (1 << j)] << val[j];
		for(int j = 2000 / K ; j ; --j) rc[i][j] = rc[i][j] | rc[i][j * K];
	}
	if(!rc[(1 << N) - 1][1]){puts("NO"); return 0;}
	puts("YES"); int cur = (1 << N) - 1 , vl = 1;
	while(cur)
		if(vl * K <= 2000 && rc[cur][vl * K]){
			for(int i = 0 ; i < N ; ++i) if(cur >> i & 1) ++b[i];
			vl *= K;
		}
		else
			for(int i = 0 ; i < N ; ++i)
				if((cur >> i & 1) && vl - val[i] >= 0 && rc[cur ^ (1 << i)][vl - val[i]]){
					cur ^= 1 << i; vl -= val[i]; break;
				}
	priority_queue < pair < int , int > > q;
	for(int i = 0 ; i < N ; ++i) q.push(make_pair(b[i] , i));
	for(int i = 1 ; i < N ; ++i){
		int x = q.top().second; q.pop(); int y = q.top().second; q.pop();
		cout << val[x] << ' ' << val[y] << endl;
		val[x] += val[y]; while(val[x] % K == 0){--b[x]; val[x] /= K;}
		q.push(make_pair(b[x] , x));
	}
	return 0;
}