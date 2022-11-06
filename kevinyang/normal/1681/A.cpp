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
		int a = 0;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			a = max(a,x);
		}
		int m;
		cin >> m;
		int b = 0;
		for(int i = 0; i<m; i++){
			int x;
			cin >> x;
			b = max(b,x);
		}
		if(a>b)cout << "Alice\nAlice\n";
		else if(a==b)cout << "Alice\nBob\n";
		else cout << "Bob\nBob\n";
	}
	return 0;
}