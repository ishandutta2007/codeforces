#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long T;
	cin >> T;
	vector<long long> prime((long long)1e5 + 4);
	prime[1] = 1;
	for(long long i = 2; i < (long long)1e5 + 4; ++i){
		if(!prime[i]){
			for(long long j = i + i; j < (long long)1e5 + 4; j += i){
				prime[j] = 1;
			}
		}
	}
	while(T--){
		long long x; cin >> x;
		long long a = x + 1;
		while(prime[a]) ++a;
		long long b = a + x;
		while(prime[b]) ++b;
		cout << a * b << '\n';
	}
	return 0;
}