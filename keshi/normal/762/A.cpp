#include <bits/stdc++.h>
using namespace std;
long long n, k, m, l;
bool f;
int main(){
	cin >> n >> k;
	for(long long i = 1; i * i <= n; i++){
		if(n % i == 0){
			m++;
			if(m == k){
				cout << i;
				return 0;
			}
			if(i * i == n){
				f = 1;
			}
		}
	}
	m = 2 * m + 1 - f;
	for(long long i = 1; i * i <= n; i++){
		if(n % i == 0){
			m--;
			if(m == k){
				cout << n / i;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}