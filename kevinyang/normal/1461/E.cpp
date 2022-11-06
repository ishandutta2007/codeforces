#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int k,l,r,t,x,y;
	cin >> k >> l >> r >> t >> x >> y;
	if(y>=x){
		vector<int>vis(x+1);
		int cnt = 0;
		int cur = k;
		while(true){
			if(cur>=l&&cur<l+x){
				vis[cur-l] = true;
				cur+=y;
				if(cur>r)break;
				if(cur>=l&&cur<l+x)break;
			}
			int v = (cur-l)/x;
			cnt+=v;
			cur-=v*x;
			//cerr << cur << "\n";
			if(vis[cur-l]){
				cout << "Yes\n";
				return 0;
			}
			//cerr << v << "\n";
		}
		//cout << cnt << "\n";
		if(cnt>=t){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	else{
		int cnt = 0;
		int cur = k;
		if(cur+y>r){
			cur-=x;
			if(cur>=l)cnt++;
		}
		int rem = x-y;
		if(cur>=l){
			cnt+=(cur-l)/rem;
		}
		if(cnt>=t){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}