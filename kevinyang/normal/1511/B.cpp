#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		vector<int>primes = {0,3,11,101,1009,25391,103387,1000039,10000303,100000007,1000000007};
		vector<int>primes2 ={0,5,13,103,1013,10009,100003,1000003,10000019,100000049,1000000009};
		cout << primes[a-c+1];
		for(int i = 0; i<c-1; i++){
			cout << 0;
		}
		cout << " ";
		cout << primes2[b-c+1];
		for(int i = 0; i<c-1; i++){
			cout << 0;
		}
		cout << "\n";
	}
	return 0;
}