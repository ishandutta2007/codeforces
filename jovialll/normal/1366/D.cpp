#include<bits/stdc++.h>
using namespace std;
#define N 10000005
int p[N],is[N],j,d,i,cnt,e,a[500005],b[500005];
void pre(){
	for(i=2;i<N;++i){
		if(!is[i])p[++cnt]=i;
		for(j=1;j<=cnt&&(d=i*p[j])<N;++j){is[d]=1;if(i%p[j]==0)break;}
	}
}
int n,x;
int main(){
	pre();cin>>n;
	for(i=1;i<=n;++i){
		cin>>x;e=sqrt(x);cnt=0;
		if(!is[x]){a[i]=b[i]=-1;continue;}
		a[i]=1;
		for(j=1;p[j]<=e;++j)if(x%p[j]==0){while(x%p[j]==0)x/=p[j],a[i]*=p[j];break;}
		if(x==1){a[i]=b[i]=-1;}
		else b[i]=x;
	}
	for(i=1;i<=n;++i)cout<<a[i]<<" ";cout<<"\n";
	for(i=1;i<=n;++i)cout<<b[i]<<" ";
}