#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i<b;i+=2)
#define ll long long
ll ans,t,x,y,z,xx,yy,zz,a[3];
int main(){
	cin>>t;
	f(i,0,t){
		ans=0;
		cin>>a[2]>>a[1]>>a[0];
		sort(a,a+3);
		xx=a[2],yy=a[1],zz=a[0];
		//cout<<xx<<" "<<yy<<" "<<zz<<endl;
		if(zz+yy<=xx) cout<<zz+yy<<endl;
		else{
			ans+=min(zz,(zz+yy-xx)/2);
			zz-=min(zz,zz+yy-xx);
			yy-=min(zz,zz+yy-xx);
			ans+=xx;
			cout<<ans<<endl;
		}
	}
}