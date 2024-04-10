#include <bits/stdc++.h>
using namespace std;
#define int long long
struct BIT{
	vector<int>M;
	vector<int>A;
	int size;
	void init(int n){
		size = n;
		M.resize(n+5);
		A.resize(n+5);
	}
	void update(int i, long long mul, long long add) {
    while (i < size) {
      M[i] += mul;
      A[i] += add;
      i |= (i + 1);
    }
  }
  void upd(int l, int r, long long x) {
  	r--;
    update(l, x, -x * (l - 1));
    update(r, -x, x * r);
  }
  long long query(int i) {
    long long mul = 0, add = 0;
    int st = i;
    while (i >= 0) {
      mul += M[i];
      add += A[i];
      i = (i & (i + 1)) - 1;
    }
    return (mul * st + add);
  }
  long long query(int l, int r) {
    return query(r) - query(l - 1);
  }
};
BIT bit;
void add(int x){
	int low = x-1; int high = 210000; int mid = (low+high)/2;
	while(low+1<high){
		if(bit.query(x,mid)==mid-x+1){
			low = mid;
		}
		else{
			high = mid;
		}
		mid = (low+high)/2;
	}
	if(high>x){
		bit.upd(x,high,-1);
	}
	bit.upd(high,high+1,1);
}
void rem(int x){
	int low = x-1; int high = 210000; int mid = (low+high)/2;
	while(low+1<high){
		if(bit.query(x,mid)==0){
			low = mid;
		}
		else{
			high = mid;
		}
		mid = (low+high)/2;
	}
	if(high>x){
		bit.upd(x,high,1);
	}
	bit.upd(high,high+1,-1);
}
int query(){
	int low = 0; int high = 209000; int mid = (low+high)/2;
	while(low+1<high){
		if(bit.query(mid,210000)>0){
			low = mid;
		}
		else{
			high = mid;
		}
		mid = (low+high)/2;
	}
	return low;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	vector<int>arr(n+1);
	bit.init(210005);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		add(arr[i]);
	}
	while(q--){
		int i,v;
		cin >> i >> v;
		rem(arr[i]);
		arr[i] = v;
		add(arr[i]);
		cout << query() << "\n";
	}
	return 0;
}