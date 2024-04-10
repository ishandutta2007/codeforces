#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,a[1005000],p[1005000];
void chk(int x){
	int i,k,l1,r1,l2,r2=0,mx=0,mn=1e9;
	if(1ll*x*x<a[1])mx=a[1]-1ll*x*x;
	for(i=x;;i++){
		l1=r2+1;r1=l1+i;
		l2=r1+1;r2=l2+i-1;
		if(l1>2000000){
			if(mx>mn)return;
			cout<<1ll*x*x+mx-a[1];exit(0);
		}
		k=lower_bound(p+1,p+n+2,l2)-p;
		if(p[k]>=l2&&p[k]<=r2)mx=max(mx,r2+1-p[k]);
		if(p[k-1]>=l1&&p[k-1]<=r1)mn=min(mn,r1-p[k-1]);
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++){
    	cin>>a[i];
    	p[i]=a[i]-a[1]+1;
	}
	p[n+1]=1e9;
	for(i=1;;i++)chk(i);
}