#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using lint = long long;
const int MAXN = 100050;

int gcd(int x, int y){
	return y ? gcd(y, x%y) : x;
}

int main(){
	int n, k;
	cin >> n >> k;
	int rk = k;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		k = gcd(x, k);
	}
	cout << rk / k << endl;
	for(int i=0; i<rk; i+=k){
		cout << i << " ";
	}
}