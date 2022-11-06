#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		int ans = (int)1e9;
		if(b>1){
			int n = a;
			int cnt = 0;
			while(n>0){
				n/=b;
				cnt++;
			}
			ans = cnt;
		}
		for(int i = max(b,2LL); i*i<=(int)1e9+(int)1e7; i++){
			int cnt = 0;
			int n = a;
			while(n>0){
				n/=i;
				cnt++;
			}
			ans = min(ans,cnt+i-b);
		}
		cout << ans << "\n";
	}
	return 0;
}