#include <bits/stdc++.h>

#define int long double
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

using namespace std;

main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vc<int> kk(n);
	cout << "? 1 " << 1 + 1 << endl;
	int tek, tek1, tek2;
	cin >> tek;
	cout << "? 1 " << 2 + 1 << endl;
	cin >> tek1;
	kk[1] = tek;
	cout << "? 2 " << 2 + 1 << endl;
	cin >> tek2;
	tek = ((tek + tek1) - tek2) / 2;
	kk[0] = tek;
	kk[1] -= tek;
	kk[2] = tek1 - tek;
	for (int i = 3; i < n; i++){
		cout << "? 1 " << i + 1 << endl;
		cin >> kk[i];
		kk[i] -= tek;
	}
	cout << "! ";
	for (auto v : kk){
		cout << v << ' ';
	} 
}