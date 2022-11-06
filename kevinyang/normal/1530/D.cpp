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
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		vector<int>ans(n+1);
		set<int>s;
		for(int i = 1; i<=n; i++){
			s.insert(i);
		}
		vector<int>idx;
		for(int i = 1; i<=n; i++){
			if(s.find(arr[i])!=s.end()){
				ans[i] = arr[i];
				s.erase(arr[i]);
			}
			else{
				idx.push_back(i);
			}
		}
		vector<int>val(idx.size());
		for(int i = 0; i<idx.size(); i++){
			if(s.find(idx[i])!=s.end()){
				val[i] = idx[i];
				s.erase(idx[i]);
			}
		}
		for(int i = 0; i<idx.size(); i++){
			if(val[i]==0){
				val[i] = *s.begin();
				s.erase(s.begin());
			}
		}
		for(int i = 0; i<idx.size(); i++){
			ans[idx[i]] = val[(i+1)%(int)idx.size()];
		}
		int bad = 0;
		for(int i = 1; i<=n; i++){
			if(ans[i]==i)bad++;
		}
		if(bad==0){
			int cnt = 0;
			for(int i = 1; i<=n; i++){
				cnt+=(arr[i]==ans[i]);
			}
			cout << cnt << "\n";
			for(int i = 1; i<=n; i++){
				cout << ans[i] << " ";
			}
			cout << "\n";
		}
		else if(bad==1){
			//cout << "NAE\n";
			int badidx = 0;
			for(int i = 1; i<=n; i++){
				if(ans[i]==i){
					badidx = i;
					break;
				}
			}
			//cout << badidx << "\n";
			for(int i = 1; i<=n; i++){
				if(arr[i]==arr[badidx]){
					swap(ans[i],ans[badidx]);
				}
			}
			int cnt = 0;
			for(int i = 1; i<=n; i++){
				cnt+=(arr[i]==ans[i]);
			}
			cout << cnt << "\n";
			for(int i = 1; i<=n; i++){
				cout << ans[i] << " ";
			}
			cout << "\n";
		}
		else{
			assert(false);
		}
	}
	return 0;
}