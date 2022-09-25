//author: Hexun
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b){
	return b ? gcd(b, a % b) : a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<LL> v(n);
	LL d = 0;
	for(LL &x : v) cin >> x;
	for(LL &x : v) d = gcd(d, x - v[0]);
	for(int j = 1; j <= m; j += 1){
		LL p;
		cin >> p;
		if(d % p == 0){
			cout << "YES\n" << v[0] << " " << j;
			return 0;
		}
	}
	cout << "NO";
	return 0;
}