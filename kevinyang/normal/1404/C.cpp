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
bool comp(pair<int,int>a, pair<int,int>b){
	return a.second < b.second;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	vector<pair<int,int>>queries(q);
	vector<pair<int,int>>old(q);
	map<pair<int,int>,int>hm;
	for(int i = 0; i<q; i++){
		int x,y;
		cin >> x >> y;
		y = n-y;
		x++;
		queries[i] = {x,y};
		old[i] = {x,y};
	}

	BIT bit;
	bit.init(n);
	sort(queries.begin(),queries.end(),comp);
	int cur = 0;
	for(int i = 1; i<=n; i++){
		int dif = i-arr[i];
		if(bit.query(1)>=dif&&dif>=0){
			int low = 0; int high = i+1; int mid = (low+high)/2;
			while(low+1<high){
				if(bit.query(mid)>=dif)low = mid;
				else high = mid;
				mid = (low+high)/2;
			}
			bit.update(1,1); bit.update(low+1,-1);
		}
		while(cur<q&&queries[cur].second==i){
			hm[queries[cur]] = bit.query(queries[cur].first);
			cur++;
		}
	}
	for(int i = 0; i<q; i++){
		cout << hm[old[i]] << "\n";
	}
	return 0;
}