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
		set<int>row; set<int>col;
		vector<vector<char>>arr(n+1,vector<char>(n+1));
		for(int i = 1; i<=n; i++){
			string s;
			cin >> s;
			for(int j = 1; j<=n; j++){
				arr[i][j] = s[j-1];
				if(arr[i][j]=='*'){
					row.insert(i); col.insert(j);
				}
			}
		}
		if(row.size()==1){
			if(*row.begin()==1)row.insert(2);
			else row.insert(1);
		}
		if(col.size()==1){
			if(*col.begin()==1)col.insert(2);
			else col.insert(2);
		}
		arr[*row.begin()][*col.begin()] = '*';
		arr[*++row.begin()][*col.begin()] = '*';
		arr[*row.begin()][*++col.begin()] = '*';
		arr[*++row.begin()][*++col.begin()] = '*';
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}