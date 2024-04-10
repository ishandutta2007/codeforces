#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	ll D = round(sqrt(8 * n + 8 * k + 9));
	ll x1 = (2 * n + 3 + D) >> 1, x2 = (2 * n + 3 - D) >> 1;
	if(0 <= x1 && x1 <= n){
		cout << x1;
	}
	else{
		cout << x2;
	}
	return 0;
}