#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,k;
int a[N],c[N],f[N],g[N];
void solve(int l,int r,int L,int R,int w){
	if(l>r)return;
	int mid=(l+r)>>1;
	int p=0,nr=min(mid,R);
	For(i,l,mid)w+=c[a[i]]++;
	For(i,L,nr){
		w-=--c[a[i]];
		if(g[mid]>f[i]+w)g[mid]=f[i]+w,p=i;
	}
	For(i,L,nr)w+=c[a[i]]++;
	For(i,l,mid)w-=--c[a[i]];
	solve(l,mid-1,L,p,w);
	For(i,l,mid)w+=c[a[i]]++;
	For(i,L,p-1)w-=--c[a[i]];
	solve(mid+1,r,p,R,w);
	For(i,l,mid)w-=--c[a[i]];
	For(i,L,p-1)w+=c[a[i]]++;
	
	
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),k=read();
	rep(i,n)f[i]=f[i-1]+c[a[i]=read()]++,g[i]=1e18;
	memset(c,0,sizeof c);
	while(--k){
		solve(1,n,1,n,0);
		rep(i,n)f[i]=g[i],g[i]=1e18;
	}cout<<f[n]<<endl;
	return 0;
}