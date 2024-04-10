#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
vector<pair<int,int> >v;
ll res,l,r;
int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;v.push_back({k,i});
	}
	set<int> s={0,n+1};
	sort(v.begin(),v.end());
	for(auto [x,y]:v){
		auto it=s.upper_bound(y);
		r=(*it-y);it--;l=(y-*it);
		res-=l*r*x;
		s.insert(y);
	}
	reverse(v.begin(),v.end());
	s={0,n+1};
	for(auto [x,y]:v){
		auto it=s.upper_bound(y);
		r=(*it-y);it--;l=(y-*it);
		res+=l*r*x;
		s.insert(y);
	}
	cout<<res;
}