#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 4055, mod = 1e9 + 7;
vector<array<ll, 2>> a;
	vector<int> ord {0, 1};
void fix(int i) {	
	if(i < 2) return;
	array<ll, 2> O = a[ord[i-1]];
	array<ll, 2> A = a[ord[i-2]];
	array<ll, 2> B = a[ord[i]];
	A[0] -= O[0], B[0] -= O[0];
	A[1] -= O[1], B[1] -= O[1];
	ll dot = A[0]*B[0] + A[1]*B[1];
	if(dot <= 0) {
		swap(ord[i], ord[i-1]);
		fix(i-1);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i[0] >> i[1];
	for(int i = 2; i < n; i++) {
		ord.push_back(i);
		fix(i);
	}
	for(auto &i : ord) cout << i+1 << " "; cout << endl;
}