#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll euclid(ll a, ll b, ll &x, ll &y){
	if(b){
		ll d = euclid(b, a % b, y, x);
		return y -= a / b * x, d;
	}
	return x = 1, y = 0, a;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	if(n == 1){
		cout << "1 " << n << "\n" << -a[0] << "\n";
		cout << "1 " << n << "\n" << 0 << "\n";
		cout << "1 " << n << "\n" << 0 << "\n";
	}
	else{
		long long x, y;
		euclid(n, n - 1, x, y);
		cout << "1 " << n << "\n";
		for(auto i = 0; i < n; ++ i){
			cout << x * n * -a[i] << " ";
		}
		cout << "\n";
		cout << "1 " << n - 1 << "\n";
		for(auto i = 0; i < n - 1; ++ i){
			cout << y * (n - 1) * -a[i] << " ";
		}
		cout << "\n";
		cout << "2 " << n << "\n";
		for(auto i = 1; i < n - 1; ++ i){
			cout << "0 ";
		}
		cout << y * (n - 1) * -a[n - 1] << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////