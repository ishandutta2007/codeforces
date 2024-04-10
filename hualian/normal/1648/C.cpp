#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
const int p=998244353;
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N],b[N];
int sum[N];
#define lowbit(x) (x&-x)
int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
void add(int x,int v){v=inv(v);while(x<N)(sum[x]+=v)%=p,x+=lowbit(x);}
int get(int x,int res=0){while(x)(res+=sum[x])%=p,x-=lowbit(x);return res;}
int all=1;
int fac[N],ifac[N];
void init(int n=N-1){
	fac[0]=1;rep(i,n)fac[i]=fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);
	Rof(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%p;
	assert(fac[10]*ifac[10]%p==1);
}
void del(int pos){
	int x=a[pos];
	add(pos,-fac[x-1]*inv(fac[x])%p);
	all=all*fac[x]%p;
	a[pos]--;x=a[pos];
	if(x==0)return;
	add(pos,fac[x-1]*inv(fac[x])%p);
	all=all*ifac[x]%p;
}
signed main(){
//	freopen(".in","r",stdin);
//	froepen(".out","w",stdout);
	int n=read(),m=read();init();
	rep(i,n)a[read()]++;
	rep(i,N-1)if(a[i])add(i,fac[a[i]-1]*inv(fac[a[i]])%p),all=all*ifac[a[i]]%p;
	rep(i,m)b[i]=read();
	int ans=0;bool f=1;
	rep(i,min(n,m)){
		int mx=b[i]-1;
		ans=(ans+fac[n-i]*all%p*get(mx)%p)%p;
		if(!a[b[i]]){f=0;break;}
		del(b[i]);
	}
	if(f&&n<m)ans++;
	cout<<(ans+p)%p<<endl;
	return 0;
}