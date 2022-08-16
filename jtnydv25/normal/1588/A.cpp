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
		vector<int> a(n), b(n);
		vector<vector<int>> f(205);
		vector<int> g(205);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			f[a[i] + 100].push_back(i);
		}

		for(int& x: b){
			cin >> x;
			g[x + 100]++;
		}
		vector<int> done(n, 0);
		string ans = "YES";
		for(int i = 0; i <= 200; i++){
			if(sz(f[i]) < g[i]){
				ans = "NO";
				break;
			}
			if(sz(f[i]) == g[i]) continue;

			while(sz(f[i]) > g[i]){
				int j = -1;
				for(int r: f[i]) if(!done[r]){
					j = r; break;
				}
				if(j==-1) break;
				f[i].erase(find(all(f[i]), j));
				f[i + 1].push_back(j);
				done[j] = 1;
			}
			if(sz(f[i]) > g[i]){
				ans = "NO";
				break;
			}
		}
		cout << ans << endl;
	}
}