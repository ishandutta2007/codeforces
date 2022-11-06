#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int am = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] >= a[k - 1] && a[i] > 0) ++am;
	}
	cout << am;
}