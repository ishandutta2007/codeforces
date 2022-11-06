#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<vector<char>>a(n+1,vector<char>(m+1));
		for(int i = 1; i<=n; i++){
			string s;
			cin >> s;
			for(int j = 1; j<=m; j++){
				a[i][j] = s[j-1];
			}
		}
		for(int i = n; i>=1; i--){
			for(int j = 1; j<=m; j++){
				int x = i;
				if(a[i][j]!='.')continue;
				while(x>0&&a[x][j]=='.'){
					x--;
				}
				if(x==0||a[x][j]=='o')continue;
				swap(a[x][j],a[i][j]);
			}
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				cout << a[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}