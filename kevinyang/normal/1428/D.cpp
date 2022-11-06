#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	set<int>ones;
	set<int>twos;
	set<int>threes;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		if(arr[i]==1)ones.insert(i);
		if(arr[i]==2)twos.insert(i);
		if(arr[i]==3)threes.insert(i);
	}
	int prev = 0;
	int cur = 1;
	vector<pair<int,int>>ans;
	vector<int>row(n+1);
	vector<int>col(n+1);
	bool f = true;
	bool three = false;
	int right = 0; int old = 1;
	bool two = false;
	if(threes.size()>0){
		int val = *threes.begin();
		ans.push_back({cur,val});
		three = true;
		right = val;
		threes.erase(val);
	}
	while(threes.size()>0){
		int val = *threes.begin();
		ans.push_back({cur,val});
		cur++;
		ans.push_back({cur,val});
		threes.erase(val);
		right = max(right,val);
		old = max(old,cur);
	}
	if(three)cur++;
	while(twos.size()>0){
		int val = *twos.begin();
		if(three&&twos.lower_bound(right)!=twos.end()){
			int val2 = *twos.lower_bound(right);
			ans.push_back({old,val2});
			ans.push_back({cur,val2});
			three = false;
			val = val2;
		}
		else{
			ans.push_back({cur,val});
		}
		twos.erase(val);
		auto it = ones.lower_bound(val);
		if(it==ones.end()){
			f = false;
			break;
		}
		ans.push_back({cur,*it});
		cur++;
		ones.erase(*it);
	}
	while(ones.size()>0){
		int val = *ones.begin();
		if(three&&ones.lower_bound(right)!=ones.end()){
			int val2 = *ones.lower_bound(right);
			ans.push_back({old,val2});
			ans.push_back({cur,val2});
			three = false;
			val = val2;
		}
		else{
			ans.push_back({cur,val});
		}
		cur++;
		ones.erase(val);
	}
	if(three){
		cout << "-1\n";
		return 0;
	}
	if(!f){
		cout << "-1\n";
		return 0;
	}
	cout << ans.size() << "\n";
	for(pair<int,int>nxt: ans){
		cout << nxt.first << " " << nxt.second << "\n";
	}
	return 0;
}