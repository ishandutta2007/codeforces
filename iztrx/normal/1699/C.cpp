#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define mod 1000000007
int mex,T,x,n,ans,m,i,l,r,len,j,a[N],c[N],pos[N];
int MEX(){
	while(mex<n){
		if(c[mex])++mex;
		else break;
	}
	return mex;
}
int main(){
//	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		mex=0;ans=1;
		for(i=1;i<=n;++i)cin>>a[i],c[i]=0,pos[a[i]]=i;
		if(n==1){
			cout<<"1\n";continue;
		}
		l=pos[0];r=pos[1];
		if(l>r)swap(l,r);len=r-l+1;x=2;
		int fl=0;
		while(1){
			if(l==1&&r==n)fl=1;
//			cout<<l<<" "<<r<<"\n";
			for(j=l;j<=r;++j){
				c[a[j]]=1;
			}
			MEX();
			for(j=x;j<mex;++j){
				ans=1ll*ans*(len-j)%mod;
			} 
			if(fl)break;
			if(r<=pos[mex])r=pos[mex];
			else l=pos[mex];
			len=r-l+1;
			x=mex+1;
		}
		cout<<ans<<"\n";
	}
}