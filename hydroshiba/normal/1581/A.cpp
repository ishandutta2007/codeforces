#include "bits/stdc++.h"
using namespace std;

const long long mod = 1e9 + 7;

long long fact(long long n){
	long long res = 1;
	for(int i = 3; i <= n; ++i){
		res = (res * (i % mod)) % mod;
	}
	return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << fact(n * 2) << '\n';
    }
}