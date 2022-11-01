#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

long long n , b;

long long solve(long long N , long long B){
	if(N == 0)
		return 0;
	return N / B + solve(N / B , B);
}

int main(){
	cin >> n >> b;
	long long ans = 3e18;
	for(long long i = 2 ; i * i <= b ; ++i)
		if(b % i == 0){
			int cnt = 0;
			while(b % i == 0){
				++cnt;
				b /= i;
			}
			ans = min(ans , solve(n , i) / cnt);
		}
	if(b - 1)
		ans = min(ans , solve(n , b));
	cout << ans;
	return 0;
}