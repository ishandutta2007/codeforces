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
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<vector<int>> a(n, vector<int>(5));
		int cur = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 5; j++) cin >> a[i][j];
			if(i){
				int num = 0;
				for(int k = 0; k < 5; k++) num += a[i][k] < a[cur][k];
				if(num >= 3) cur = i;
			}
		}
		bool ok = true;
		for(int i = 0; i < n; i++) if(cur != i){
			int num = 0;
			for(int k = 0; k < 5; k++) num += a[i][k] < a[cur][k];
			if(num >= 3) ok = false;
		}
		cout << (ok ? (cur + 1) : -1) << endl;
	}
}