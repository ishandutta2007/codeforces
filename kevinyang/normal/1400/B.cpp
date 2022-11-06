#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int p,f;
		cin >> p >> f;
		int cnt1,cnt2;
		cin >> cnt1 >> cnt2;
		int s,w;
		cin >> s >> w;
		if(w<s){
			int temp = cnt2;
			cnt2 = cnt1; cnt1 = temp;
			temp = s;
			s = w; w = temp;
		}
		int ans1 = 0; int ans2 = 0;
		int ans = 0;
		for(int i = 0; i<=cnt2; i++){
			int take = i;
			int p1 = p-i*w; int p2 = f;
			if(p1<0)continue;
			take+=min(cnt1,p1/s);
			int cnt11= cnt1-min(cnt1,p1/s);
			take+=min(cnt11,p2/s);
			p2-=min(cnt11,p2/s)*s;
			take+=min(cnt2-i,p2/w);
			ans = max(ans,take);
		}
		cout << ans << "\n";
	}
	return 0;
}