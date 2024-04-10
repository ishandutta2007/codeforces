#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int M=1e6+9;
const int B=709;
int n,q;
ll a[M],vis[M];
map<ll,int>mp[1009];
int id(int i){
	return (i-1)/B+1;
}
int L(int i){
	return (i-1)*B+1;
}
int R(int i){
	return min(i*B,n);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mp[id(i)][a[i]]++;
	}
	for(int t=1;t<=q;++t){
		int o;
		cin>>o;
		if(o==1){
			int l,r,x;
			cin>>l>>r>>x;
			for(int i=id(l);i<=id(r);++i)vis[i]+=x;
			for(int i=L(id(l));i<l;++i){
				ll z=--mp[id(l)][a[i]];
				if(z==0)mp[id(l)].erase(a[i]);
				a[i]-=x;
				mp[id(l)][a[i]]++;
			}
			for(int i=r+1;i<=R(id(r));++i){
				ll z=--mp[id(r)][a[i]];
				if(z==0)mp[id(r)].erase(a[i]);
				a[i]-=x;
				mp[id(r)][a[i]]++;
			}
		}
		else{
			int y;
			cin>>y;
			int u=0,v=0;
			for(int i=id(1);i<=id(n);++i){
				if(mp[i].count(y-vis[i])){
					int l=L(i),r=R(i);
					for(int j=l;j<=r;++j){
						if(a[j]==y-vis[i]){
							u=j;
							break;
						}
					}
					if(u)break;
				}
			}
			for(int i=id(n);i>=id(1);--i){
				if(mp[i].count(y-vis[i])){
					int l=L(i),r=R(i);
					for(int j=r;j>=l;--j){
						if(a[j]==y-vis[i]){
							v=j;
							break;
						}
					}
					if(v)break;
				}
			}
			if(u==0)cout<<"-1\n";
			else cout<<v-u<<"\n";
		}
	}
	return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
1
5 6

*/