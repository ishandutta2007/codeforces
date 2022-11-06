#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
struct BIT{
	vector<int>arr;
	int size;
	void init(int n){
		size = n;
		arr.resize(n+5);
	}
	void update(int x, int val){
		for(int a = x; a<=size; a+=a&-a){
			arr[a]+=val;
			arr[a]%=mod;
		}
	}
	int query(int x){
		int sum = 0;
		for(int a = x; a>0; a-=a&-a){
			sum+=arr[a];
			sum%=mod;
		}
		return sum;
	}
	void change(int x, int val){
		int v = query(x)-query(x-1);
		update(x,val-v);
	}
	int query(int x, int y){//inclusive
		int ret = query(y)-query(x-1);
		ret+=mod; ret%=mod;
		return ret;
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n+1);
	vector<int>arr2(n+1);
	vector<int>arr3(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i] >> arr2[i] >> arr3[i];
	}
	BIT bit;
	bit.init(n);
	int ans = 0;
	for(int i = 1; i<=n; i++){
		int idx = lower_bound(arr.begin(),arr.end(),arr2[i])-arr.begin();
		bit.update(i,bit.query(idx,i));
		bit.update(i,arr[i]-arr2[i]);
		if(arr3[i])ans+=bit.query(i,i);
		ans%=mod;
	}
	ans+=arr[n]; ans++;
	ans%=mod;
	cout << ans << "\n";
	return 0;
}