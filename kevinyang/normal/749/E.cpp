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
	bit.init(n);
	int cntans = 0; //sum of number of inversions in all subarrays
	for(int i = 1; i<=n; i++){
		cntans+=bit.query(arr[i])*(n-i+1);
		bit.update(arr[i],i);
	}
	//cout << cntans << "\n";
	double valans = (double)cntans/(n*(n+1)/2);
	double cntavg = 0;
	for(int i = 1; i<=n; i++){
		cntavg+=(double)(n-i+1)*i*(i-1)/4;
	}
	//cout << cntavg << "\n";
	cntavg/=n*(n+1)/2;
	BIT bit2;
	bit2.init(n);
	int inv = 0;
	for(int i = 1; i<=n; i++){
		inv+=bit2.query(arr[i]);
		bit2.update(arr[i],1);
	}
	cout << fixed << setprecision(12);
	//cout << inv << " " << cntavg << " " << valans << "\n";
	cout << n*(n-1)/2-inv+valans-cntavg << "\n";
	return 0;
}