#include <bits/stdc++.h>
using namespace std;
#define int long long
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
	int n;
	cin >> n;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	BIT bit;
	bit.init(600000);
	BIT bit2;
	bit2.init(600000);
	int ans = 0;
	int sum = 0;
	for(int i = 1; i<=n; i++){
		ans+=sum;
		ans+=arr[i]*(i-1);
		ans-=bit.query(arr[i]);
		for(int j = arr[i]; j<=600000; j+=arr[i]){
			bit.update(j,arr[i]);
			ans-=(bit2.query(j-1)-bit2.query(j-arr[i]-1))*((j-1)/arr[i]*arr[i]);
		}
		bit2.update(arr[i],1);
		sum+=arr[i];
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}