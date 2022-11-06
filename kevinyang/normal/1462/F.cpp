#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>bit(500001);
void update(int x, int val, int size){
	for(int a = x; a<=size; a+=a&-a){
		bit[a]+=val;
	}
}
int query(int x){
	int sum = 0;
	for(int a = x; a>0; a-=a&-a){
		sum+=bit[a];
	}
	return sum;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>sorted; sorted.push_back(-1);
		vector<pair<int,int>>arr(n);
		for(int i = 0; i<n; i++){
			int x,y;
			cin >> x >> y;
			arr[i] = {x,y};
			sorted.push_back(x); sorted.push_back(y);
		}
		sort(sorted.begin(),sorted.end());
		for(int i = 0; i<n; i++){
			arr[i].first = lower_bound(sorted.begin(),sorted.end(),arr[i].first)-sorted.begin();
			arr[i].second = lower_bound(sorted.begin(),sorted.end(),arr[i].second)-sorted.begin();
		}
		sort(arr.begin(),arr.end());
		vector<int>ans(n);
		for(int i = 0; i<n; i++){
			ans[i]+=query(arr[i].first);
			update(arr[i].first,1,2*n);
			update(arr[i].second+1,-1,2*n);
		}
		for(int i = 0; i<n; i++){
			update(arr[i].first,-1,2*n);
			update(arr[i].second+1,1,2*n);
		}
		for(int i = n-1; i>=0; i--){
			ans[i]+=query(arr[i].second)-query(arr[i].first-1);
			update(arr[i].first,1,2*n);
		}
		for(int i = n-1; i>=0; i--){
			update(arr[i].first,-1,2*n);
		}
		int mx = 0;
		for(int i = 0; i<n; i++){
			mx = max(mx,ans[i]);
		}
		cout << n-mx-1 << "\n";
	}
	return 0;
}