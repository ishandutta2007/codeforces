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
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int & x : a) cin >> x;
		vector<int> v = {1, 2, 1, 1, 2, 1};
		cout << (n / 2) * v.size() << endl;
		for(int i = 0; i < n; i += 2){
			int j = i + 1;
			for(int x : v) cout << x << " " << i + 1<< " " << j + 1<< endl;
		}
	}
}