#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[666],b[666],res,cur,l;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++)cin>>b[i];
		
		multiset<pair<int,int> > s;
		
		for(i=1;i<=n;i++){
			s.insert({a[i],1});
			s.insert({a[i]-b[i]+1,-1});
		}
		
		cur=0;k=0;res=0;
		
		for(auto [i,j]:s){
			k+=j;
			if(k){
				if(!cur)cur=i;
			}
			else{
				cur=i-cur+1;
				res+=(cur*cur+cur)/2;
				cur=0;
			}
		}
		
		cout<<res<<'\n';
	}
}