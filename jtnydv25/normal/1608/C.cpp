#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n), b(n), perm_a(n), perm_b(n), iperm_a(n), iperm_b(n);
		vector<int> A, B;
		for(int& x: a) cin >> x;
		for(int& x: b) cin >> x;
		iota(all(perm_a), 0);
		iota(all(perm_b), 0);
		A = a; B = b;
		sort(all(A)), sort(all(B));
		sort(all(perm_a), [&](int i, int j){return a[i] < a[j];});
		sort(all(perm_b), [&](int i, int j){return b[i] < b[j];});
		for(int i = 0; i < n; i++){
			iperm_a[perm_a[i]] = i;
			iperm_b[perm_b[i]] = i;
		}
		vector<int> prefA(n);
		int v = 0;
		for(int i = 0; i < n; i++){
			v = max(v, b[perm_a[i]]);
			prefA[i] = v;
		}
		vector<int> suffb(n + 1, 1 << 30);
		for(int i = n - 1; i >= 0; i--){
			suffb[i] = min(suffb[i + 1], b[perm_a[i]]);
		}
		// trace(suffb);
		int mx = -1;
		for(int i = 0; i + 1 < n; i++) if(prefA[i] < suffb[i + 1]){
			mx = i;
		}
		for(int i = 0; i < n; i++){
			int p = iperm_a[i];
			cout << (p > mx);
		}
		cout << endl;
	}
}