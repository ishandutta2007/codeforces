#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q, a, b, n, S;
	cin >> q;
	while(q--) {
		cin >> a >> b >> n >> S;
		cout << ((a * n + b >= S) && (S % n <= b) ? "YES" : "NO") << endl;
	}
	return 0;
}