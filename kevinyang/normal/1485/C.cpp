#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x,y;
		cin >> x >> y;
		int ans = 0;
		for(int i = 1; i*i<x; i++){
			ans+=min(x,i*(y+1))/i - min(min(x,i*(y+1)),i*i+i)/i;
		}
		cout << ans << "\n";
	}
	return 0;
}