#include<bits/stdc++.h>
using namespace std;

int num[1003] , N , A[1003] , B[1003];

int main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		char c = getchar(); while(!isdigit(c)) c = getchar();
		num[i] = c - '0';
	}
	for(int i = 1 ; i <= N ; ++i) cin >> A[i] >> B[i];
	int ans = 0; for(int i = 1 ; i <= N ; ++i) ans += num[i];
	for(int i = 1 ; i <= 250 ; ++i){
		for(int j = 1 ; j <= N ; ++j)
			if(i >= B[j] && (i - B[j]) % A[j] == 0)
				num[j] ^= 1;
		int sum = 0; for(int j = 1 ; j <= N ; ++j) sum += num[j];
		ans = max(ans , sum);
	}
	cout << ans; return 0;
}