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
		int a, b, x, y;
		cin>>a>>b>>x>>y;
		int up = (x) * b;
		int down = (a - x - 1) * b;
		int right = (b - y - 1) * a;
		int left =  (y) * a;
		if (up < down)
			swap(up, down);
		if (up < right)
			swap(up, right);
		if (up < left)
			swap(up, left);
		cout << up << endl;
	}
}