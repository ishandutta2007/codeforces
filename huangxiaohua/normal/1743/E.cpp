#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll d1,d2,t1,t2,hp,def,f[5050],g[5050],h[5050],t3,d3,res=1e18;

int main(){
	ios::sync_with_stdio(0);
	cin>>d1>>t1>>d2>>t2>>hp>>def;
	for(i=0;i<=5000;i++)f[i]=g[i]=h[i]=1e18;
	for(i=1;i<=5000;i++){
		for(j=1;j<=5000;j++){
			t3=max(t1*i,t2*j);
			d3=d1*(t3/t1)+d2*(t3/t2)-(t3/t1+t3/t2-1)*def;
			d3=min(d3,5000ll);
			f[d3]=min(f[d3],t3);
		}
	}
	for(i=0;i<=5000;i++){
		for(j=0;j<=5000;j++){
			t3=max(t1*i,t2*j);
			d3=d1*(t3/t1)+d2*(t3/t2)-(t3/t1+t3/t2)*def;
			d3=min(d3,5000ll);
			h[d3]=min(h[d3],t3);
		}
	}
	for(i=4999;i>=1;i--)h[i]=min(h[i],h[i+1]);
	g[0]=0;
	for(i=1;i<=5000;i++)for(j=0;j<=5000;j++)g[min(5000,j+i)]=min(g[min(5000,j+i)],g[j]+f[i]);
	for(i=0;i<hp;i++)res=min(res,g[i]+h[hp-i]);
	for(i=hp;i<=5000;i++)res=min(res,g[i]);
	cout<<res;
}