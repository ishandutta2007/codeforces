#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>bit(2000005);
void update(int x, int val){
	for(int a = x; a<2000000; a+=a&-a){
		bit[a]+=val;
	}
}
int query(int x){
	int sum = 0;
	for(int a = x; a>0; a-=a&-a){
		sum+=bit[a];
	}
	return sum;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	int cur = (int)1e6;
	vector<set<int>>ind(51);
	for(int i = 1; i<=n; i++){
		int x;
		cin >> x;
		ind[x].insert(cur+i);
	}
	while(q--){
		int x;
		cin >> x;
		int v = *ind[x].begin();
		cout << v-cur-query(v) << " ";
		cur--;
		update(v,1);
		ind[x].insert(cur+1);
	}
	return 0;
}