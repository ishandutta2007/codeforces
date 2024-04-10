#include<bits/stdc++.h>
using namespace std;

long double dp[103][10003]; int arr[103] , N , X;

int main(){
	cin >> N >> X; dp[0][0] = 1;
	for(int i = 1 ; i <= N ; ++i){
		cin >> arr[i];
		for(int j = i ; j ; --j)
			for(int k = arr[i] ; k <= 1e4 ; ++k)
				dp[j][k] += dp[j - 1][k - arr[i]] * j / (N - j + 1);
	}
	long double sum = 0;
	for(int i = 1 ; i <= N ; ++i) for(int j = 1 ; j <= 1e4 ; ++j) sum += dp[i][j] * min((N + i) * X , j * 2) / i / 2;
	cout << fixed << setprecision(10) << sum; return 0;
}