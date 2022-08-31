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
	int t; cin>> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> p(n);
		vector<int> f(n);
		for(int i = 0; i < n; i++){
			cin >> p[i];
			p[i]--;
			f[(i - p[i] + n) % n]++;
		}
		vector<int> v;
		for(int k = 0; k < n; k++){
			if(f[k] < n / 3) continue;
			vector<int> q(n);
			for(int j = 0; j < n; j++) q[j] = p[(j + k) % n];
			// # of cycles in q;
			vector<int> vis(n);
			int c = 0;
			for(int i = 0; i < n; i++) if(!vis[i]){
				while(!vis[i]){
					vis[i] = true;
					i = q[i];
				}
				c++;
			}
			if(c >= n - m) v.push_back(k);
		}
		cout << v.size() << endl;
		for(auto k : v) cout << k << " ";
		cout << endl;
	}
}