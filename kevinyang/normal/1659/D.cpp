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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int>arr(n+1);
		for(int i = 1; i<=n; i++){
			cin >> arr[i];
		}
		int sum = 0;
		for(int i = 1; i<=n; i++){
			sum+=arr[i];
		}
		sum/=n;
		int cur = sum;
		BIT bit;
		bit.init(n+5);
		for(int i = n; i>=2; i--){
			int low = i-1; int high = n+1; int mid = (low+high)/2;
			while(low+1<high){
				int rq = mid-i+1;
				int sum = bit.query(mid)+cur;
				if(sum>=rq){
					low = mid;
				}
				else{
					high = mid;
				}
				mid = (low+high)/2;
			}
			if(low-i+1!=arr[i]){
				cur--;
				bit.update(i,1);
			}
		}
		if(cur==1){
			bit.update(1,1);
		}
		for(int i = 1; i<=n; i++){
			cout << bit.query(i,i) << " ";
		}
		cout << "\n";
	}
	return 0;
}