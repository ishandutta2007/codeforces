#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(n);
		vector<int> c(m);
		vector<priority_queue<int>> cdif(n);
		priority_queue<int> all;
		int last = -1;
		for(int i = 0; i < n; ++i){
			cin >> a[i]; --a[i];
		}
		for(int i = 0; i < n; ++i){
			cin >> b[i]; --b[i];
			if(b[i] != a[i]){
				cdif[b[i]].push(i);
				all.push(i);
			}
		}
		for(int i = 0; i < m; ++i){
			cin >> c[i]; --c[i];
		}
		for(int i = 0; i < n; ++i){
			if(b[i] == c[m - 1]){
				last = i;
			}
		}
		if(last == -1){
			cout << "NO\n";
			continue;
		}
		vector<int> ans(m);
		for(int i = 0; i < m; ++i){
			if((int)cdif[c[i]].size()){
				int p = cdif[c[i]].top(); cdif[c[i]].pop();
				ans[i] = p;
				a[p] = c[i];
				continue;
			}
			while((int)all.size() && a[all.top()] == b[all.top()]){
				all.pop();
			}
			if((int)all.size()){
				int p = all.top();
				ans[i] = p;
				a[p] = c[i];
			}
			else{
				int p = last;
				ans[i] = p;
				a[p] = c[i];
				all.push(p), cdif[b[p]].push(p);
			}
		}
		int f = 1;
		for(int i = 0; i < n; ++i){
			if(a[i] != b[i]){
				f = 0;
				break;
			}
		}
		if(!f){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
			for(int i = 0; i < m; ++i){
				cout << ans[i] + 1 << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}