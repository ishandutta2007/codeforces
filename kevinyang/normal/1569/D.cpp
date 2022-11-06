#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		cin >> n >> m >> k;
		set<int>s;
		set<int>s2;
		for(int i = 0; i<n; i++){
			int x;
			cin >> x;
			s.insert(x);
		}
		for(int i = 0; i<m; i++){
			int x;
			cin >> x;
			s2.insert(x);
		}
		map<int,vector<int>>hm;
		map<int,vector<int>>hm2;
		set<int>xs;
		set<int>ys;
		vector<int>arr;
		vector<int>arr2;
		for(int i = 0; i<k; i++){
			bool samex = false; bool samey = false;
			int x,y;
			cin >> x >> y;
			if(s.find(x)!=s.end())samex = true;
			if(s2.find(y)!=s2.end())samey = true;
			if(samex&&samey)continue;
			else if(samex)arr.push_back(y);
			else if(samey)arr2.push_back(x);
			hm[x].push_back(y);
			hm2[y].push_back(x);
			xs.insert(x);
			ys.insert(y);
		}
		sort(arr.begin(),arr.end());
		sort(arr2.begin(),arr2.end());
		int ans = 0;
		for(int i = 0; i+1<arr.size(); i++){
			auto it = lower_bound(arr.begin(),arr.end(),*s2.lower_bound(arr[i]));
			int idx = it-arr.begin();
			int v = idx-i-1;
			v = max(v,0LL);
			ans+=v;
		}
		//cout << ans << "\n";
		for(int i = 0; i+1<arr2.size(); i++){
			auto it = lower_bound(arr2.begin(),arr2.end(),*s.lower_bound(arr2[i]));
			int idx = it-arr2.begin();
			int v = idx-i-1;
			v = max(v,0LL);
			ans+=v;
		}
		//cout << ans << "\n";
		for(int nxt: xs){
			sort(hm[nxt].begin(),hm[nxt].end());
			for(int i = 0; i+1<hm[nxt].size(); i++){
				auto it = lower_bound(hm[nxt].begin(),hm[nxt].end(),*s2.lower_bound(hm[nxt][i]));
				int idx = it-hm[nxt].begin();
				int v = idx-i-1;
				v = max(v,0LL);
				ans-=v;
			}
		}
		for(int nxt: ys){
			sort(hm2[nxt].begin(),hm2[nxt].end());
			for(int i = 0; i+1<hm2[nxt].size(); i++){
				auto it = lower_bound(hm2[nxt].begin(),hm2[nxt].end(),*s.lower_bound(hm2[nxt][i]));
				int idx = it-hm2[nxt].begin();
				int v = idx-i-1;
				v = max(v,0LL);
				ans-=v;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}