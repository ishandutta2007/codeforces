#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define eb emplace_back
using namespace std;
const int M=1<<18;
int n,q;
ll a[M],ls[M],rs[M],val[M];
int main(){
	cin>>n;
	for(int i=0;i<1<<n;++i)cin>>a[i],ls[i]=rs[i]=val[i]=max(a[i],0ll);
	for(int k=0;k<n;++k){
		for(int i=0;i<1<<n;++i){
			if(i>>k&1){
				int t=1<<k;
				ll lx=ls[i^t],ly=rs[i^t],rx=ls[i],ry=rs[i];
				ls[i^t]=max(lx,a[i^t]+rx);
				rs[i^t]=max(ry,a[i]+ly);
				ls[i]=max(rx,a[i]+lx);
				rs[i]=max(ly,a[i^t]+ry);
				ll x=val[i^t],y=val[i];
				val[i^t]=max({x,y,ly+rx});
				val[i]=max({x,y,ry+lx});
				ll s=a[i]+a[i^t];
				a[i]=a[i^t]=s;
			}
		}
	}
	int t=0;
	cin>>q;
	for(int i=1;i<=q;++i){
		int k;
		cin>>k;
		t^=1<<k;
		cout<<val[t]<<endl;
	}
	return 0;
}
/*
1
4
0 10 10 10
10 10 10 10
*/