#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int MAXN = 1600;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for(auto &i : a) cin >> i;
		for(auto &i : b) cin >> i;	
		sort(all(a));
		sort(all(b));
		int ret = 0;
		for(int i = 0; i < n; i++){
			if(b[i] >= a[i] && b[i] <= a[i] + 1) ret++;
		}
		cout << (ret == n ? "YES\n" : "NO\n");
	}

}