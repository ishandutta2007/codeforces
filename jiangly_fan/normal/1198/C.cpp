//Author: HeXun
//Date: 07-30-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 360000;
bool vis[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int T;
	for(cin >> T; T; T -= 1){
		int n, m;
		cin >> n >> m;
		fill(vis, vis + 3 * n + 1, false);
		vector<int> ans;
		for(int i = 1, u, v; i <= m; i += 1){
			cin >> u >> v;
			if(not vis[u] and not vis[v]){
				ans.push_back(i);
				vis[u] = vis[v] = true;
			}
		}
		if((int)ans.size() >= n){
			cout << "Matching\n";
			for(int i = 0; i < n; i += 1) cout << ans[i] << " ";
			cout << "\n";
		}
		else{
			cout << "IndSet\n";
			int c = 0;
			for(int i = 1; i <= 3 * n; i += 1){
				if(not vis[i]){
					cout << i << " ";
					c += 1;
					if(c == n) break;
				}
			}
			assert(c == n);
			cout << "\n";

		}
	}
	return 0;
}