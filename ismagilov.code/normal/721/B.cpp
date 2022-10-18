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
	int n, k;
	cin >> n >> k;
	string a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	string s;
	cin >> s;
	int mm = 0;
	int ravn = 0;
	for (int i = 0; i < n; i++){
		mm += a[i].size() < s.size();
		ravn += a[i].size() == s.size();
	}
	cout << mm + 1 + (mm / k) * 5 << ' ' << mm + ravn + (mm + ravn - 1) / k * 5;
}