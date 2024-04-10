#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,a[300500],sb[300500],pre[300500],r[300500],q[300500],it,res;

int main(){
	mt19937_64 rd(time(0));
	cin>>n;
	for(i=1;i<=n;i++)r[i]=rd(),sb[i]=(sb[i-1]^r[i]);
	for(i=1;i<=n;i++){
		cin>>a[i];pre[i]=(pre[i-1]^r[a[i]]);
		if(a[i]==1)q[++it]=i;
	}
	q[it+1]=n+1;
	for(t=1;t<=it;t++){
		for(k=0,j=q[t]-1;j>q[t-1];j--){
			k=max(k,a[j]);
			if(j+k-1>=q[t]&&j+k-1<q[t+1]&&sb[k]==(pre[j+k-1]^pre[j-1]))res++;
		}
		for(k=0,j=q[t]+1;j<q[t+1];j++){
			k=max(k,a[j]);
			if(j-k+1<=q[t]&&j-k+1>q[t-1]&&sb[k]==(pre[j]^pre[j-k]))res++;
		}
	}
	cout<<res+it;
}