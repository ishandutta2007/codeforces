#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
int i,j,k,t,n,m,lst;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> s;  
map<int,vector<int> >mp;
ll res,sb;
#define su (sb+sb*sb)/2
int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>j>>k;
		mp[-k].push_back(j);
	}
	for(auto &[id,v]:mp){
		sort(v.begin(),v.end());
		for(auto i:v)s.insert(i);
		v.push_back(1e9);
		sb=s.size();res+=su;lst=-1e9;
		for(auto i:v){
			sb=s.order_of_key(i)-s.order_of_key(lst+1);
			res-=su;lst=i;
		}
	}
	cout<<res;
}