#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
	}
	bool f = false;
	for(int i = 0; i<n; i++){
		if(arr[i]==s)f = true;
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			if(arr[i][1]==s[0]&&arr[j][0]==s[1])f = true;
		}
	}
	if(f)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}