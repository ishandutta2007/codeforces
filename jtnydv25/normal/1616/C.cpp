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
		vector<int> a(n);
		for(int& x: a) cin >> x;
		int ans = 1;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				int c = 2;
				for(int r = j + 1; r < n; r++){
					if(a[r] * (j - i) == a[i] * (j - i) + (a[j] - a[i]) * (r - i)) c++;
				}
				ans = max(ans, c);
			}
		}
		cout << n - ans << endl;
	}
}