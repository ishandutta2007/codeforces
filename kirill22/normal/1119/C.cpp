#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n,m;
	cin >> n >> m;
	int a[n][m];
	int b[n][m];
	for(int i=0;i<n;i++){
		for(int u=0;u<m;u++){
			cin >> a[i][u];
		}
	}
	for(int i=0;i<n;i++){
		for(int u=0;u<m;u++){
			cin >> b[i][u];
		}
	}
	if (n == 1 || m == 1){
		for(int i=0;i<n;i++){
		for(int u=0;u<m;u++){
			if (a[i][u]!=b[i][u]){
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
	}
	vector<int> str(n,0);
	vector<int> st(m,0);
	for(int i=0;i<n;i++){
		for(int u=0;u<m;u++){
			if (a[i][u]!=b[i][u]){
				str[i]++;
				st[u]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		if (str[i]%2==1){
			cout << "No";
				return 0;
		}
	}
	for(int i=0;i<m;i++){
		if (st[i]%2==1){
			cout << "No";
				return 0;
		}
	}
	
	cout << "Yes";
}