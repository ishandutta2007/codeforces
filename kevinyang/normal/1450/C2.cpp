#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<char>>mp(n+1,vector<char>(n+1));
		int k = 0;
		for(int i = 0; i<n; i++){
			string s;
			cin >> s;
			for(int j = 0; j<n; j++){
				mp[i][j] = s[j];
				if(mp[i][j]!='.')k++;
			}
		}
		for(int a = 0; a<3; a++){
			for(int b = 0; b<3; b++){
				if(a==b)continue;
				int cnt = 0;
				for(int i = 0; i<n; i++){
					for(int j = 0; j<n; j++){
						if(mp[i][j]=='O'&&(i+j)%3==a)cnt++;
						if(mp[i][j]=='X'&&(i+j)%3==b)cnt++;
					}
				}
				if(cnt<=k/3){
					for(int i = 0; i<n; i++){
						for(int j = 0; j<n; j++){
							if(mp[i][j]=='O'&&(i+j)%3==a)cout << "X";
							else if(mp[i][j]=='X'&&(i+j)%3==b)cout << "O";
							else cout << mp[i][j];
						}
						cout << "\n";
					}
					goto naenae;
				}
			}
		}
		cout << "-1\n";
		naenae:{

		}

	}
	return 0;
}