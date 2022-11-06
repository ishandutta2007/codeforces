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
		vector<vector<char>>mat(n+1,vector<char>(n+1));
		for(int i = 1; i<=n; i++){
			string s;
			cin >> s;
			for(int j = 1; j<=n; j++){
				mat[i][j] = s[j-1];
			}
		}
		if(m%2==0){
			bool f = false;
			pair<int,int>ans = {0,0};
			for(int i = 1; i<=n; i++){
				for(int j = i+1; j<=n; j++){
					if(mat[i][j]==mat[j][i]){
						f = true;
						ans = {i,j};
					}
				}
			}
			if(f){
				cout << "YES\n";
				for(int i = 0; i<=m; i++){
					if(i%2==0)cout << ans.first << " ";
					else cout << ans.second << " ";
				}
				cout << "\n";
				continue;
			}
			for(int i = 1; i<=n; i++){
				int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
				for(int j = 1; j<=n; j++){
					if(mat[j][i]=='a')a1 = j;
					if(mat[j][i]=='b')b1 = j;
					if(mat[i][j]=='a')a2 = j;
					if(mat[i][j]=='b')b2 = j;
				}
				if(a1&&a2){
					f = true;
					cout << "YES\n";
					if(m%4==0){
						cout << i << " ";
						for(int j = 0; j<m/2; j++){
							if(j%2==0)cout << a1 << " ";
							else cout << i << " ";
						}
						for(int j = 0; j<m/2; j++){
							if(j%2==0)cout << a2 << " ";
							else cout << i << " ";
						}
					}
					else{
						cout << a1 << " ";
						for(int j = 0; j<m/2; j++){
							if(j%2==0)cout << i << " ";
							else cout << a1 << " ";
						}
						for(int j = 0; j<m/2; j++){
							if(j%2==0)cout << a2 << " ";
							else cout << i << " ";
						}
					}
					cout << "\n";
					break;
				}
				if(b1&&b2){
					f = true;
					cout << "YES\n";
					if(m%4==0){
						cout << i << " ";
						for(int j = 0; j<m/2; j++){
							if(j%2==0)cout << b1 << " ";
							else cout << i << " ";
						}
						for(int j = 0; j<m/2; j++){
							if(j%2==0)cout << b2 << " ";
							else cout << i << " ";
						}
					}
					else{
						cout << a1 << " ";
						for(int j = 0; j<m/2; j++){
							if(j%2==0)cout << i << " ";
							else cout << b1 << " ";
						}
						for(int j = 0; j<m/2; j++){
							if(j%2==0)cout << b2 << " ";
							else cout << i << " ";
						}
					}
					cout << "\n";
					break;
				}
			}
			if(!f){
				cout << "NO\n";
			}
		}
		else{
			cout << "YES\n";
			for(int i = 0; i<=m; i++){
				cout << i%2+1 << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}