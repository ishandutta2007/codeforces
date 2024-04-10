#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=2e5+9;
int n,m;
int ans[M],pr[M],ne[M],t[M<<1];
ll a[M],b[M],v[M];
void push(int x,int y){
	for(t[x+=n-1]=y;x;x>>=1)t[x>>1]=v[t[x]]<v[t[x^1]]?t[x^1]:t[x];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),ne[i]=i+1;
	for(int i=m;i>=1;--i)scanf("%lld",&b[i]);
	for(int i=1;i< n;++i)v[i]=a[i],push(i,i),a[i]+=a[i-1];
	int ma=0;
	for(int i=1;i<=m;++i){
		while(v[t[1]]>b[i]){
			int x=t[1],y=ne[x],z=ne[y];
			push(x,0);
			push(y,0);
			ma=max(ma,z-x-1);
			ne[x]=z;
			if(z)v[x]=(a[z-1]-a[x-1]-1)/(z-x)+1,push(x,x);
		}
		ans[i]=ma;
	}
	for(int i=m;i>=1;--i)printf("%d ",ans[i]);
	return 0;
}