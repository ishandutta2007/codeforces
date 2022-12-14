#include<bits/stdc++.h>
using namespace std;
#define py puts("Yes\n")
#define pn puts("No\n")
#define N 100005
int T,n,i,j,x,k,a,b,v[N],now,cc;
int main(){
	cin>>a>>b;
	x=a+b;
	for(i=1;1ll*i*(i+1)/2<=x;++i);
	now=i-1;
	for(i=now;i;--i){
		if(a>=i)v[i]=1,a-=i,++cc;
	}
	cout<<cc<<"\n";
	for(i=1;i<=now;++i)if(v[i])cout<<i<<" ";cout<<"\n";
	cout<<now-cc<<"\n";
	for(i=1;i<=now;++i)if(!v[i])cout<<i<<" ";cout<<"\n";
}