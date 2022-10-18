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

using namespace std;

main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int b[n];
	b[n - 1] = a[n - 1];
	for (int i = n-2; i >= 0; i--){
		b[i] = a[i] + a[i + 1];
	}
	for (int i = 0; i < n; i++){
		cout << b[i] << ' ';
	}
}