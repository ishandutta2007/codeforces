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
		int a, b, p;
		string road;
		cin>>a>>b>>p>>road;
		int len = road.length();
		int prev_i = len - 2;
		// cout << len - 1 << endl;
		bool br = 0;
		for (int j = len-2; j >= 0; j--){
			// cout << road[j] << endl;
			if (road[j] == road[prev_i])
				continue;
			else if ((road[j] == 'A' && (p -= b) < 0) ||
					(road[j] == 'B' && (p -= a) < 0)){
				br = 1;
				// cout << "ye" << endl;
				break;
			} else {
				// cout << "mod:" << j << endl;
				prev_i = j;
			}
			// cout << p << endl;
		}
		if (br ||
			(road[0] == 'A' && (p -= a) < 0) ||
			(road[0] == 'B' && (p -= b) < 0)){
			cout << prev_i + 1 + (len - 1 != prev_i) << endl;
			// cout << "ye" << endl;			
		}
		else
			cout << 1 << endl;
	}
}