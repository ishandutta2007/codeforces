#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long T;
	cin >> T;
	while(T--){
		long long N, k;
		cin >> N >> k;
		vector<long long> a(N);
		for(long long i = 0; i < N; ++i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long val = a[1] - a[0];
		for(long long i = 2; i < N; ++i){
			val = __gcd(val, a[i] - a[i - 1]);
		}
		long long dif = abs(a[0] - k);
		if(dif % val == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}