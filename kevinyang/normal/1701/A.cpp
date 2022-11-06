#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		vector<int>a(4);
		int cnt = 0;
		for(int i = 0; i<4; i++){
			cin >> a[i];
			cnt+=a[i];
		}
		if(cnt==0)cout << "0\n";
		else if(cnt==4)cout << "2\n";
		else cout << "1\n";
	}
	return 0;
}