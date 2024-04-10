#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,r,m,i,h[1000005],x,j,k,las,y,x_,y_,TO,a_,r_,ans=1e18;
int main(){
	cin>>n>>a>>r>>m;//x:r,y:a;
	for(i=1;i<=n;++i)cin>>h[i],x+=h[i];
	y=0;a_=min(a,m-r),r_=min(r,m-a);
	sort(h+1,h+n+1);
	las=0;
	for(i=1;i<=n;++i){
		if(h[i]!=h[i+1]){
			y_=y+(las)*(h[i]-h[las]);
			x_=x-(n-las)*(h[i]-h[las]);
			if((x>=y)^(x_>=y_)==0){
				x=x_;y=y_;
			}
			else{
				k=(x-y)/n-2+h[las];
				for(j=max(k,h[las]);j<=min(k+5,h[i]);++j){
					x_=x-(n-las)*(j-h[las]);
					y_=y+las*(j-h[las]);
					if(x_>=y_){
						ans=min(ans,r*x_+a_*y_);
					}
					if(x_<=y_){
						ans=min(ans,r_*x_+a*y_);
					}
				}
				y=y+(las)*(h[i]-h[las]);
				x=x-(n-las)*(h[i]-h[las]);
			}
			las=i;
			if(x>=y){
				ans=min(ans,r*x+a_*y);
			}
			if(x<=y){
				ans=min(ans,r_*x+a*y);
			}
		}
	}cout<<ans;
	 
}