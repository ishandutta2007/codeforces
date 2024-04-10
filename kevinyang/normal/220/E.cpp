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
	int n,k;
	cin >> n >> k;
	vector<int>arr(n+1);
	vector<int>sorted; sorted.push_back(-1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		sorted.push_back(arr[i]);
	}
	sort(sorted.begin(),sorted.end());
	for(int i = 1; i<=n; i++){
		arr[i] = lower_bound(sorted.begin(),sorted.end(),arr[i])-sorted.begin();
		//cout << arr[i] << " ";
	}
	int r = 2;
	int ans = 0;
	if(true){
		BIT bit;
		bit.init(n);
		for(int i = n; i>=2; i--){
			ans+=bit.query(arr[i]-1);
			bit.update(arr[i],1);
		}
	}
	BIT bit;
	BIT bit2;
	bit.init(n);
	bit2.init(n);
	for(int i = 2; i<=n; i++){
		bit2.update(arr[i],1);
	}
	//cerr << "nae\n";
	int cnt = 0;
	for(int i = 1; i<n; i++){
		ans+=bit.query(arr[i]+1,n);
		ans+=bit2.query(arr[i]-1);
		bit.update(arr[i],1);
		while(ans>k&&r<=n){
			ans-=bit.query(arr[r]+1,n);
			ans-=bit2.query(arr[r]-1);
			bit2.update(arr[r],-1);
			r++;
		}
		cnt+=n+1-r;
		if(i+1==r){
			ans-=bit.query(arr[r]+1,n);
			ans-=bit2.query(arr[r]-1);
			bit2.update(arr[r],-1);
			r++;
		}
		//cerr << "nae\n";
	}
	cout << cnt << "\n";
	return 0;
}