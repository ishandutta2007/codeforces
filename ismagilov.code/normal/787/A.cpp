#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd "\n"; return 0;

using namespace std;

int gcd(int a, int b){
	if (a < b){
		swap(a, b);
	}
	if (b == 0){
		return 1;
	}	
	return gcd(a % b, b);
}

main() {
	ios_base::sync_with_stdio(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int dd = gcd(a, c);
	if (dd > 1){
		if (b % dd != d % dd){
			cout << -1;
			return 0;
		}
	}
	for (int i = b; i < 100000000; i += a){
		if (i >= d && i % c == d % c){
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}