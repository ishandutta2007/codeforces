#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;
const int mod = 1e9 + 7;

lint f(lint x){
	lint ans = 1;
	for(lint i=2; i*i<=x; i++){
		if(x % i == 0){
			ans *= i-1;
			x /= i;
			while(x % i == 0){
				x /= i;
				ans *= i;
			}
		}
	}
	if(x > 1) ans *= x-1;
	return ans;
}

lint f(lint n, lint k){
	if(k == 1) return f(n);
	if(n == 1) return 1;
	if(k % 2 == 1) return f(f(n), k-1);
	return f(n, k-1);
}

int main(){
	lint n, k;
	cin >> n >> k;
	cout << f(n, k) % mod;
}