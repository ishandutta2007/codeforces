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
		int L = 1e9 + 10, R = 0;
		const int INF = 1e9;
		int min_L = INF, min_R = INF;
		int minCost = 2 * INF;
		for(int i = 0; i < n; i++){
			int l, r, c; cin >> l >> r >> c;
			if(l < L){
				L = l;
				min_L = c;
				minCost = min_L + min_R;
			} else if(l == L){
				min_L = min(min_L, c);
				minCost = min(minCost, min_L + min_R);
			}

			if(r > R){
				R = r;
				min_R = c;
				minCost = min_L + min_R;
			} else if(r == R){
				min_R = min(min_R, c);
				minCost = min(minCost, min_L + min_R);
			}
			
			if(l == L && r == R) minCost = min(minCost, c);
			cout << minCost << endl;
		}
	}
}