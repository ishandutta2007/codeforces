// Hydro submission #62c6cee68672efa577c017f2@1657196263191
#include<bits/stdc++.h>
//#define int long long
const int MOD = 998244353;
const int nmax = 200001;
using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n), f(nmax, 0);
	for(int &x : a) {
		cin >> x;
		f[x]++;
	}
	vector<int> L(nmax, -1), R(nmax, -1);
	for(int i = 0; i < n; ++i) {
		if(L[a[i]] == -1) {
			L[a[i]] = i;
		}
		R[a[i]] = i;
	}
	vector<int> upTo(n, 0);
	for(int i = 0; i < n; ++i) {
		upTo[i] = R[a[i]];
	}
	int low, high = 0, answer = 0, fq = 0, mxFq = 0; 
	for(low = 0; low < n; ++low) {
		high = max(high, upTo[low]);
		if(L[a[low]] == low) {
			fq += f[a[low]];
			mxFq = max(mxFq, f[a[low]]);
		}
		if(low == high) {
			answer += fq - mxFq;
			fq = 0;
			mxFq = 0;
		}
	}
	cout << answer << endl;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}