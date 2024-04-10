#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,len,lim,a[N],L[N],R[N],blo[N];
int out[N],cnt[N],last[N]; 
void work(int l,int r){
	Rof(i,r,l){
		if(i+a[i]>n){out[i]=i+a[i];cnt[i]=1;last[i]=i;continue;}
		if(blo[i+a[i]]==blo[i]){out[i]=out[i+a[i]];cnt[i]=cnt[i+a[i]]+1;last[i]=last[i+a[i]];continue;}
		out[i]=i+a[i];cnt[i]=1;
	}
}
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();len=sqrt(n)+1;
	rep(i,n)a[i]=read();
	lim=n/len;
	rep(i,lim)L[i]=R[i-1]+1,R[i]=L[i]+len-1;
	if(R[lim]!=n)L[++lim]=R[lim-1]+1,R[lim]=n;
	rep(i,lim)For(j,L[i],R[i])blo[j]=i;
	work(1,n);
	while(m--){
		int op=read();
		switch(op){
			case 0:{
				int x=read(),y=read();
				a[x]=y;
				work(L[blo[x]],x);
				break;
			}
			case 1:{
				int x=read(),LAST=0,res=0;
				while(x<=n)LAST=last[x],res+=cnt[x],x=out[x];
				printf("%d %d\n",LAST,res);
				break;
			}
		}
	}
	return 0;
}