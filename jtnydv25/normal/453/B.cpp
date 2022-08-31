#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int A[N];
bool isprime(int n){
	for(int i = 2; i * i <= n; i++) if(n % i == 0) return 0;
	return n > 1;
}

vector<int> primes;

int dp[N][1 << 16];
int lst[N][1 << 16];
int mask[N];
const int MAX = 58;

const int INF = 1e9;
int main(){
	int n;
	cin >> n;
	for(int i = 2; i <= 58; i++) if(isprime(i)) primes.push_back(i);

	int M = primes.size();

	for(int i = 1; i < N; i++){
		for(int j = 0; j < M; j++)
			if(i % primes[j] == 0) mask[i] |= (1 << j);
	}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < (1 << 16); j++)
			dp[i][j] = INF;
	dp[0][0] = 0;
	int sz = (1 << M);
	for(int i = 1; i <= n; i++){
		cin >> A[i];
		for(int prevmask = 0; prevmask < sz; prevmask++){
			for(int num = 1; num <= 58; num++){
				if((mask[num] & prevmask) == 0){
					int newmask = prevmask | mask[num];
					if(dp[i][newmask] > dp[i - 1][prevmask] + abs(num - A[i])){
						dp[i][newmask] = dp[i - 1][prevmask] + abs(num - A[i]);
						lst[i][newmask] = num;
					}
				}
			}
		}
	}
	int mn = INF, msk = 0;
	for(int i = 0; i < sz; i++){
		if(dp[n][i] < mn){
			mn = dp[n][i];
			msk = i;
		}
	}
	for(int i = n; i >= 1; i--){
		A[i] = lst[i][msk];
		msk &= (~mask[A[i]]);
	}

	for(int i = 1; i <= n; i++) printf("%d ", A[i]);
	printf("\n");
}