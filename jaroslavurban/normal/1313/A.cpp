#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define mod 1000000007
#define ll long long
#define MIN(a, b) ((a > b ? b : a))
#define MAX(a, b) ((a > b ? a : b))
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
		int a, b, c;
		cin>>a>>b>>c;
		int cnt = 0;
		if (a){
			a--;
			cnt++;
		}
		if (b){
			b--;
			cnt++;
		}
		if (c){
			c--;
			cnt++;
		}
		if (b > a)
			swap(b, a);
		if (c > a)
			swap(c, a);
		if (c > b)
			swap(b, c);
		if (a && b){
			a--; b--;
			cnt++;
		}
		if (a && c){
			a--; c--;
			cnt++;
		}
		if (c && b){
			c--; b--;
			cnt++;
		}
		if (a && b && c){
			a--; b--; c--;
			cnt++;
		}

		cout << cnt << endl;

	}
}