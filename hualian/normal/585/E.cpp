#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e7+9;
const int p=1e9+7;
const int lim=1e7;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
char In[1<<20],*Ss=In,*Tt=In;
//#define getchar() (Ss==Tt&&(Tt=(Ss=In)+fread(In,1,1<<20,stdin),Ss==Tt)?EOF:*Ss++)
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,f[N],g[N],p2[N];
bitset<N>vis;
int pr[N],len,mu[N];
void get(int n){
	mu[1]=1;
	For(i,2,n){
		if(!vis[i])pr[++len]=i,mu[i]=-1;
		for(int j=1;j<=len&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;
			if(i%pr[j]==0)break;
			mu[pr[j]*i]=-mu[i];
		}
	}
}
void upd(int &x){x+=(x>=p?-p:(x<0?p:0));}
void mulpre(int *a){
	rep(i,len)for(int j=1;j*pr[i]<=lim;j++)
		a[pr[i]*j]+=a[j],upd(a[pr[i]*j]);
}
void divpre(int *a){
	Rof(i,len,1)for(int j=lim/pr[i];j>=1;j++)
		a[pr[i]*j]-=a[j],upd(a[pr[i]*j]);
}
void mulsuf(int *a){
	rep(i,len)for(int j=lim/pr[i];j>=1;j--)
		a[j]+=a[pr[i]*j],upd(a[j]);
}
void divsuf(int *a){
	Rof(i,len,1)for(int j=1;j*pr[i]<=lim;j++)
		a[j]-=a[pr[i]*j],upd(a[j]);
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();rep(i,n)g[read()]++;get(lim);
	p2[0]=1;rep(i,n)p2[i]=p2[i-1]*2,upd(p2[i]);
	memcpy(f,g,sizeof f);
	mulsuf(f);For(i,1,lim)f[i]=p2[f[i]]-1;divsuf(f);
	mulsuf(g);For(i,1,lim)g[i]=g[i]*mu[i],upd(g[i]);
	mulpre(g);
	long long ans=0;
	For(i,2,lim)ans=(ans+1ll*g[i]*f[i])%p;
	cout<<(ans+p)%p<<endl;
	return 0;
}