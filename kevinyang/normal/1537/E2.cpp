#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int curans = 1;
	int cur = 0;
	for(int i = 1; i<n; i++){
		if(s[i]==s[cur]){
			cur++;
			cur%=curans;
			continue;
		}
		if(s[i]>s[cur]){
			break;
		}
		else{
			cur = 0;
			curans = i+1;
		}
	}
	int i = 0;
	while(k--){
		cout << s[i];
		i++;
		i%=curans;
	}
	cout << "\n";
	return 0;
}