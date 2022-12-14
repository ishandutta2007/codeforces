#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define getc() p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
char buf[1<<21],*p1,*p2,ch;
ll ret;
inline ll re() {
	ret=0;
	ch=getc();
	while(!isdigit(ch)){
		ch=getc();
	}
	while(isdigit(ch)){
		ret=(ret<<1)+(ret<<3)+(ch^48);
		ch=getc();
	}
	return ret;
}
int a[N],i,m,j,n,x,y,pb[N],now,xx,yy,mid,b[N],g,vis[N],S[N],rf,f1[N],nt[N],L,R,f2[N],k,c1,c2,tot;
ll K,T,l,r,vv,Tm,ys,pos[N],ur,qwq;queue<int>q;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	n=re();m=re();K=re();g=gcd(n,m);
	for(i=0;i<n;++i)a[i]=re();
	for(i=0;i<m;++i)b[i]=re(),nt[i]=(i+n)%m;
	for(i=0;i<g;++i)vis[i]=1,q.push(i);
	while(q.size()){
		x=q.front();q.pop();
		if(!vis[nt[x]])pos[nt[x]]=pos[x]+n,q.push(nt[x]),vis[nt[x]]=1;
	}l=0;r=1e18;
	while(l<r){
		T=(l+r>>1);Tm=1ll*n*m/g;ys=(T+1)%Tm-1;qwq=(T+1)/Tm;vv=0;
		for(i=0;i<g;++i){
			c1=c2=0;
			for(x=i;x<n;x+=g)f1[++c1]=x;
			for(y=i;y<m;y+=g)f2[++c2]=y;
			for(j=1;j<=c2;++j)pb[b[f2[j]]]=f2[j]+1;
			for(j=1;j<=c1;++j){
				if(pb[a[f1[j]]]){
					xx=f1[j]%m;yy=pb[a[f1[j]]]-1;
					vv+=qwq;ur=pos[yy]-pos[xx];
					if(ur<0)ur+=Tm;
					if(ur+xx<=ys)++vv;
				}
			}
			for(j=1;j<=c2;++j)pb[b[f2[j]]]=0;
		}
		if(T+1-vv>=K)r=T;
		else l=T+1;
	}
	cout<<l+1;
}