#include <bits/stdc++.h>
using namespace std;
#define int long long
int sumlr(int l, int r){
	int len = r-l+1;
	return len*(r+l)/2;
}
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
	vector<int>ind(n+1);
	for(int i = 1; i<=n; i++){
		ind[arr[i]] = i;
	}
	BIT bit;
	BIT val;
	bit.init(n);
	val.init(n);
	int inv = 0;
	for(int i = 1; i<=n; i++){
		inv+=bit.query(n)-bit.query(ind[i]);
		bit.update(ind[i],1);
		val.update(ind[i],ind[i]);
		int low = 0; int high = n; int mid = (low+high)/2;
		while(low+1<high){
			if(bit.query(mid)<=i/2)low = mid;
			else high = mid;
			mid = (low+high)/2;
		}
		int v = sumlr(low-i/2+1,low)-val.query(low)+val.query(n)-val.query(low)-sumlr(low+1,low+(i+1)/2);
		cout << inv+v << " ";
	}
	cout << "\n";
	return 0;
}