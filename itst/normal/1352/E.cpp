#include<bits/stdc++.h>
using namespace std;

int T , N , pot[8003] , arr[8003];

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
		memset(pot , 0 , sizeof(pot)); int ans = 0;
		for(int j = 1 ; j <= N ; ++j){
			int sum = 0;
			for(int k = j ; k <= N ; ++k){
				if((sum += arr[k]) > N) break;
				if(j != k) pot[sum] = 1;
			}
		}
		for(int j = 1 ; j <= N ; ++j) ans += (bool)pot[arr[j]];
		cout << ans << endl;
	}
}