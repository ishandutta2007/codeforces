#include<bits/stdc++.h>
using namespace std;

int main(){
	static int arr[100003] , N , T;
	for(cin >> T ; T ; --T){
		long long pot[83] = {}; cin >> N;
		for(int i = 1 ; i <= N ; ++i){cin >> arr[i]; for(int j = 0 ; j <= 30 ; ++j) pot[j] += arr[i] >> j & 1;}
		long long sum = 0; for(int i = 0 ; i < 30 ; ++i) sum += (pot[i] << i) - ((pot[i] & 1) << (i + 1));
		if(!sum) puts("0\n");
		else{
			long long b = 0;
			for(int j = 0 ; sum ; ++j)
				if((sum < 0 ? -sum : sum) >> j & 1){
					if(!(pot[j] & 1)) sum -= 1ll << j; else sum += 3ll << j;
					b += 1ll << j;
				}
			printf("1\n%lld\n" , b);
		}
	}
	return 0;
}