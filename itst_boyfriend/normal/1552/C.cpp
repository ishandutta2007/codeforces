#include<bits/stdc++.h>
using namespace std;

int N , K , L[103] , R[103] , sum[203];

int main(){
	int T;
	for(cin >> T ; T ; --T){
		cin >> N >> K; for(int i = 1 ; i <= 2 * N ; ++i) sum[i] = 1;
		for(int i = 1 ; i <= K ; ++i){cin >> L[i] >> R[i]; sum[L[i]] = sum[R[i]] = 0; if(L[i] > R[i]) swap(L[i] , R[i]);}
		for(int i = 1 ; i <= 2 * N ; ++i) sum[i] += sum[i - 1];
		int ans = (N - K) * (N - K - 1) / 2;
		for(int i = 1 ; i <= K ; ++i){
			for(int j = 1 ; j <= K ; ++j)
				ans += L[i] < L[j] && L[j] < R[i] && R[i] < R[j];
			ans += min(sum[R[i]] - sum[L[i]] , sum[L[i]] + sum[2 * N] - sum[R[i]]);
		}
		cout << ans << endl;
	}
	return 0;
}