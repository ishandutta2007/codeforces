#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,l,r;
		cin >> n >> l >> r;
		multiset<int>left;
		for(int i = 0; i<l; i++){
			int x;
			cin >> x;
			left.insert(x);
		}
		multiset<int>right;
		for(int i = 0; i<r; i++){
			int x;
			cin >> x;
			right.insert(x);
		}
		vector<int>rem;
		int ans = 0;
		for(int nxt: left){
			if(right.size()&&right.find(nxt)!=right.end()){
				rem.push_back(nxt);
				right.erase(right.lower_bound(nxt));
				l--; r--;
			}
		}
		for(int nxt: rem){
			left.erase(left.lower_bound(nxt));
		}
		ans+=min(l,r);
		if(r-l>0){
			vector<int>freq(n+1);
			for(int nxt: right){
				freq[nxt]++;
			}
			int cnt = 0;
			for(int i = 1; i<=n; i++){
				while(freq[i]>=2){
					freq[i]-=2;
					cnt++;
					ans++;
					if(l+cnt*2==r)break;
				}
				if(l+cnt*2==r)break;
			}
			int rem = r-cnt*2-l;
			ans+=rem;
		}
		else if(l-r>0){
			vector<int>freq(n+1);
			for(int nxt: left){
				freq[nxt]++;
			}
			int cnt = 0;
			for(int i = 1; i<=n; i++){
				while(freq[i]>=2){
					freq[i]-=2;
					cnt++;
					ans++;
					if(r+cnt*2==l)break;
				}
				if(r+cnt*2==l)break;
			}
			int rem = l-cnt*2-r;
			ans+=rem;
		}
		cout << ans << "\n";
	}
	return 0;
}