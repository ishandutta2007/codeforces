#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,x,y,a[200500],b[200500],c[200500],d[200500];
ll res;

int main(){
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		res=0;
		for(i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			x=max(0ll,a[i]-m);
			y=b[i]-max(0ll,m-a[i]);
			c[i]=min(a[i],m);d[i]=m-c[i];
			res+=x-y;
		}
		for(i=1;i<=n;i++){
			x=-res/2;
			if(x<=0)continue;
			x=min({-res/2,b[i]+c[i]-m,c[i]});
			res+=x*2;
			c[i]-=x;d[i]+=x;
		}
		cout<<llabs(res)<<'\n';
		for(i=1;i<=n;i++)cout<<c[i]<<' '<<d[i]<<'\n';
	}
}