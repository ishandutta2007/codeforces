#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,a,b;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		int cnt = 1;
		for(int i = 0; i<s.length()-1; i++){
			if(s[i+1]!=s[i])cnt++;
		}
		cnt = cnt/2+1;
		cout << a*n + max(n*b,cnt*b) << "\n";
	}
	return 0;
}