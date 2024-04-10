#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define mod 1000000007
#define ll long long
// fast modulo exponentiation
ll FME(ll a, ll b){
	ll res = 1;
	while (b){
		if (b&1)
			res *= a % mod;
		a *= a % mod;
		b >>= 1;
	}
	return res;
}

int main(){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n, x, y;
		cin>>n>>x>>y;
		int sum = x + y;
		int best = max(sum - n + 1, 1);
		int worst = min(sum - 1, n);
		if (x == n && y == n)
			best = n;
		cout << best << " " << worst << endl;
	}
}