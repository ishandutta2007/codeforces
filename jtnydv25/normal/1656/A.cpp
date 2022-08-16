#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n' // remove in interactive
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n), perm(n);
		for(int&x: a) cin >> x;
		iota(all(perm), 0);
		sort(all(perm), [&](int i, int j){return a[i] < a[j];});
		cout << perm[0] + 1 << " " << perm[n - 1] + 1 << endl;
	}
}