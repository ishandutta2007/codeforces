#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)1e9 + 7;
const LL NS = (LL)54;
LL T, N;
LL a[NS];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while(T--){
		cin >> N;
		LL sum = 0;
		for(LL i = 1; i <= N; ++i){
			cin >> a[i];
		}
		for(LL i = 1; i <= N; ++i){
			LL val = 1;
			while(val * 2 <= a[i]){
				val *= 2;
			}
			cout << val << ' ';
		}
		cout << '\n';
	}
	return 0;
}