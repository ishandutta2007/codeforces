#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long
using namespace std;
const int M=1e5+9;
int n,s0,s1;
int x[M];
set<int>s;
bool check(int t){
	s.clear();
	s.insert(s1);
	for(int i=1;i<=n;++i){
		if(abs(x[i]-x[i-1])<=t)s.insert(x[i-1]);
		for(auto it=s.upper_bound(x[i]+t);it!=s.end();it=s.erase(it));
		if(s.size()==0)return 0;
		for(auto it=s.begin();it!=s.end()&&*it<x[i]-t;it=s.erase(it));
		if(s.size()==0)return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s0>>s1;
	for(int i=1;i<=n;++i)cin>>x[i];
	x[0]=s0;
	int l=abs(s0-s1),r=1e9;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<"\n";
	return 0;
}