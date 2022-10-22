#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,N=1e5;
const ll inf=1e18;
ll f[18][maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool bj[maxn];
int len,p[maxn];
ll phi[maxn];
void pre(){
	phi[1]=1;
	for(int i=2;i<=N;i++){
		if(!bj[i])p[++len]=i,phi[i]=i-1;
		for(int j=1;1ll*i*p[j]<=N&&j<=len;j++){
			bj[i*p[j]]=1;
			if(i%p[j]==0){phi[i*p[j]]=phi[i]*p[j];break;}
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	for(int i=1;i<=N;i++)phi[i]+=phi[i-1];
	return ;
}
ll calc(int x,int y){
	ll res=0;
	for(int l=x,r;l<=y;l=r+1){
		r=y/(y/l);
		res+=1ll*(r-l+1)*phi[y/l];
	}
	return res;
}
void solve(int d,int l,int r,int x,int y){
	if(l>r)return ;
	int mid=l+((r-l)>>1);
	ll c=calc(x+1,mid),cur=inf,pos=0;
	for(int i=x;i<=y&&i<=mid;i++){
		if(cur>f[d-1][i]+c)cur=f[d-1][i]+c,pos=i;
		c-=phi[mid/(i+1)];
	}
	f[d][mid]=cur;
	solve(d,l,mid-1,x,pos),solve(d,mid+1,r,pos,y);
	return ;
}
int main(){
	int T;
	T=read();
	pre();
	for(int i=1;i<=N;i++)f[1][i]=1ll*i*(i+1)/2;
	for(int i=2;i<=17;i++)solve(i,1,N,1,N);
	while(T--){
		int n,k;
		n=read();k=read();
		if(k>17)printf("%d\n",n);
		else printf("%lld\n",f[k][n]);
	}
    return 0;
}