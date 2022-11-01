#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
using namespace std;
const int N=1e6+5;
int T,n,a[N];
int bz[N],ds;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>T;T--;){
		cin>>n;
		fo(i,1,n)cin>>a[i],bz[i]=0;
		bz[1]=1;ds=1;
		for(int x=1;;){
			x-=a[x];
			if(bz[x]){
				ds=bz[x];break;
			}
			bz[x]=++ds;
		}
		int m=0;
		fo(i,1,n)m+=bz[i]>=ds;
		printf("%d\n",m);
		fo(i,1,n)if(bz[i]>=ds)printf("%d ",i);
		printf("\n");
	}
}