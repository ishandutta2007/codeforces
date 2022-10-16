#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define IOS ios::sync_with_stdio(0)
#define py cout<<"YES"
#define pn cout<<"NO"
#define n k
int T,i,j,k,x,a[N],ans,s[N],dp[N],c[N],fl;
ll sum,f[N];
map<int,int>p;
int solve_(int pos){
//	cout<<c[n]<<" "<<pos<<"\n";
	if(c[n]==f[pos+1]-((pos+1)&1)){
//		cout<<c[1]<<" "<<c[2]<<"\n";
		int i,j=n-1;
		for(i=pos-1;i>0;i-=2){
			if(c[j]<f[i])return 0;
			c[j]-=f[i];
			if(!c[j])--j;
			else {
		x=j;
		while(c[x]<c[x-1])swap(c[x],c[x-1]),--x;
			}
		}
		return 1;
	}
	return 0;
}
int solve(int pos){
	if(pos<=1)return 1;
//	cout<<"hiferiug\n";
//	for(int i=1;i<=n;++i)cout<<c[i]<<" ";cout<<"\n";
	if(c[n-1]>=f[pos]){
		c[n-1]-=f[pos];
		x=n-1;
		while(c[x]<c[x-1])swap(c[x],c[x-1]),--x;
		int fl=solve_(pos-1);
		c[x]+=f[pos];c[n]-=f[pos];
		sort(c+1,c+n+1);
		fl|=solve_(pos-1);
		return fl;
	}
	else if(c[n]>=f[pos]){
		if(c[n]>f[pos+1])return 0;
		else if(c[n]==f[pos+1])return solve_(pos);
		c[n]-=f[pos];
		x=n;
		while(c[x]<c[x-1])swap(c[x],c[x-1]),--x;
		return solve(pos-1); 
	}
	else return 0;
}
int main(){
	IOS;
	cin>>T;
	for(i=3,f[1]=f[2]=1;i<=60;++i)f[i]=f[i-1]+f[i-2];
	while(T--){
		cin>>k;sum=0;
		for(i=1;i<=k;++i)cin>>c[i],sum+=c[i];
		for(fl=-1,i=1;i<=60;++i)if(f[i]-1==sum){fl=i-2;}
		sort(c+1,c+k+1);
		if(fl==-1){
			cout<<"NO\n";
		}
		else if(solve(fl)){
			cout<<"YES\n";
		}
		else cout<<"NO\n";
	}
	return 0;
}