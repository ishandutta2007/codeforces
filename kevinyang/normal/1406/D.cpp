#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>bit(100001);
void update(int x, int val){
	for(int a = x; a<=100000; a+=a&-a){
		bit[a]+=val;
	}
}
int query(int x){//get value at x
	int sum = 0;
	for(int a = x; a>0; a-=a&-a){
		sum+=bit[a];
	}
	return sum;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0; i<n; i++){
		cin >> arr[i];
		update(i+1,arr[i]);
		update(i+2,-1*arr[i]);
	}
	int start = arr[0];//a+b=start
	int sub = 0;
	int add = 0;
	for(int i = 1; i<n; i++){
		int num = arr[i]-arr[i-1];
		if(num<0)sub-=num;
		else add+=num;
	}
	int a = (start-add)/2;
	int b = start-a;
	int mx = max(b,a+add);
	cout << mx << "\n";
	int q;
	cin >> q;
	while(q--){
		int l,r,x;
		cin >> l >> r >> x;
		int oldl = query(l);
		int oldr = query(r);
		update(l,x);
		update(r+1,-1*x);
		if(x>0){
			if(l>1)add+=min({max(query(l)-query(l-1),0LL),query(l)-oldl});
			if(r<n)add-=min({max(query(r+1)-oldr,0LL),query(r)-oldr});
		}
		else{
			if(l>1)add-=min({max(oldl-query(l-1),0LL),oldl-query(l)});
			if(r<n){
				add+=min({max(query(r+1)-query(r),0LL),oldr-query(r)});
				//cout << query(r+1) << " : " << query(r) << "\n";
			}
		}
		if(l==1)start+=x;
		a = (start-add)/2;
		b = start-a;
		mx = max(b,a+add);
		cout << mx << "\n";
		//cout << start << " " << add << "\n";
	}
	
	return 0;
}