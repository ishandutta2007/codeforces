#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[500500],res,x,y,t1;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		tree<pair<int,int>,null_type,less< pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> t;
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>a[i];
			t.insert({a[i]*2,i});
		}
		if(m==n){
			cout<<1000000000<<'\n';continue;
		}
		res=0;
		for(i=2;i<=n;i++){
			t.erase({a[i-1]*2,i-1});
			t.erase({a[i]*2,i});
			t.insert({a[i-1],i-1});
			t.insert({a[i],i});
			
			auto [x,y]=*t.find_by_order(m);
			//printf("a%d %d\n",i,x);
			res=max(res,x);
			
			t.insert({a[i-1]*2,i-1});
			t.insert({a[i]*2,i});
			t.erase({a[i-1],i-1});
			t.erase({a[i],i});
		}
		res=min(res,1000000000);
		cout<<res<<'\n';
	}
}