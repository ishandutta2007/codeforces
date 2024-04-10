#include <bits/stdc++.h>
using namespace std;
#define int long long
struct BIT{
	vector<int>arr;
	int size;
	void init(int n){
		size = n+5;
		arr.resize(n+10);
	}
	void update(int x, int val){
		for(int a = x; a<=size; a+=a&-a){
			arr[a]+=val;
		}
	}
	int query(int x){
		int sum = 0;
		for(int a = x; a>0; a-=a&-a){
			sum+=arr[a];
		}
		return sum;
	}
	void change(int x, int val){
		int v = query(x)-query(x-1);
		update(x,val-v);
	}
	int query(int x, int y){//inclusive
		return query(y)-query(x-1);
	}
};
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
		vector<int>sorted; sorted.push_back(-(int)1e18);
		for(int i = 1; i<=n; i++){
			sorted.push_back(arr[i]);
		}
		sort(sorted.begin(),sorted.end());
		for(int i = 1; i<=n; i++){
			arr[i] = lower_bound(sorted.begin(),sorted.end(),arr[i])-sorted.begin();
		}
		BIT bit;
		bit.init(n);
		int ans = 0;
		for(int i = 1; i<=n; i++){
			int v = min(bit.query(arr[i]+1,n+2),bit.query(1,arr[i]-1));
			ans+=v;
			bit.update(arr[i],1);
		}
		cout << ans << "\n";
	}
	return 0;
}