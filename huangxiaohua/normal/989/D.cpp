#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,n1,n2,m,w;
ll res,f1[100500],f2[100500],x,y,t;

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m>>w;
	for(i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		if(y==1)f1[++n1]=x;
		else f2[++n2]=x;
	}
	if(n1)sort(f1+1,f1+n1+1);
	if(n2)sort(f2+1,f2+n2+1);
	
	j=1;
	for(i=1;i<=n1;i++){
		while(f1[i]-f1[j]>=m)j++;
		//printf("NMSL%d %d\n",i,j);
		if(f1[i]<0||w>1)res+=i-j;
	}
	
	j=n2;
	for(i=n2;i>=1;i--){
		while(f2[j]-f2[i]>=m)j--;
		//printf("NMSL%d %d\n",i,j);
		if(f2[i]+m>0||w>1)res+=j-i;
	}
	
	for(i=1;i<=n1;i++){
		ll l,r,md,ans=0;
		ll x1,y1,x2,y2;
		if(f1[i]<0){
			l=1;r=n2;ans=0;
			
			while(l<=r){
				md=(l+r)/2;
				if(f2[md]+m>0){
					r=md-1;
				}
				else{
					x1=-(f2[md]+m);
					y1=w-1;
					
					if(!y1){
						ans=max(ans,md);l=md+1;continue;
					}
					if((w-1)*f1[i]+(w+1)*x1>=0){
						ans=max(ans,md);l=md+1;continue;
					}
					r=md-1;
				}
			}
			
			res+=n2-ans;
		}
		else{
			l=1;r=n2;ans=0;
			if(w==1)continue;
			
			while(l<=r){
				md=(l+r)/2;
				if(f2[md]+m<=f1[i]){
					ans=max(ans,md);l=md+1;continue;
				}
				if( (f2[md]+m)*(w-1)-f1[i]*(w+1) <=0){
					ans=max(ans,md);l=md+1;continue;
				}
				r=md-1;
			}
			
			res+=n2-ans;
		}
	}
	
	cout<<res;
}