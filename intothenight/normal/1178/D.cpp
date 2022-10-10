#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 998244353;
bool isprime(int x){
	for(int k = 2; k * k <= x; k ++){
		if(x % k == 0){
			return false;
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = n; ; i ++){
		if(isprime(i)){
			cout << i << "\n";
			int k = 2 * (i - n), l = n - k;
			if(k == 2){
				cout << "1 3\n1 " << n << "\n";
				for(int i = 1; i < n; i ++){
					cout << i << " " << i + 1 << "\n";
				}
			}
			else{
				for(int i = 1; i < k; i ++){
					cout << i << " " << i + 1 << "\n";
					if(i <= k / 2){
						cout << i << " " << i + k / 2 << "\n";
					}
				}
				if(k){
					cout  << k << " " << k + l << "\n";
					for(int i = k + 1; i < k + l; i ++){
						cout << i << " " << i + 1 << "\n";
					}
					cout << 1 << " " << k + 1;
				}
				else{
					for(int i = 1; i < l; i ++){
						cout << i << " " << i + 1 << "\n";
					}
					cout << 1 << " " << l;
				}
			}
			return 0;
		}
	}
	return 0;
}