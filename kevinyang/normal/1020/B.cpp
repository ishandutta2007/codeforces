#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>adj(n+1);
	for(int i = 1; i<=n; i++){
		cin >> adj[i];
	}
	for(int i = 1; i<=n; i++){
		int start = i;
		vector<bool>vis(n+1);
		while(true){
			if(vis[start]){
				cout << start << " ";
				break;
			}
			vis[start] = true;
			start = adj[start];
		}
	}
	return 0;
}