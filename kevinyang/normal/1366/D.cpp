#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<int>factor(10000005);
	for(int i = 2; i<=10000000; i++){
		if(factor[i]==0)factor[i] = i;
		for(int j = i*i; j<=10000000; j+=i){
			if(factor[j]==0)factor[j] = i;
		}
	}
	vector<pair<int,int>>ans(n+1);
	for(int i = 1; i<=n; i++){
		int k = arr[i];
		set<int>s;
		while(k!=1){
			s.insert(factor[k]);
			k/=factor[k];
		}
		if(s.size()<=1){
			ans[i] = {-1,-1};
			continue;
		}
		ans[i].first = *s.begin();
		s.erase(s.begin());
		int cur = 1;
		for(int nxt: s)cur*=nxt;
		ans[i].second = cur;
	}
	for(int i = 1; i<=n; i++){
		cout << ans[i].first << " ";
	}
	cout << "\n";
	for(int i = 1; i<=n; i++){
		cout << ans[i].second << " ";
	}
	cout << "\n";
	return 0;
}