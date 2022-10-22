#include<bits/stdc++.h>
//#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e6+9;
char buf[(1<<21)+5],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int max(int &x,int &y){return (x>y)?x:y;}
inline long long read(){
	long long f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int c[N],n;
long long a[N];
short tag[N<<2],mx[N<<2];
int cnt[N<<2];
int f;
struct tree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	void push_down(int p){
		if(!tag[p])return;
		tag[ls]+=tag[p];mx[ls]+=tag[p];
		tag[rs]+=tag[p];mx[rs]+=tag[p];
		tag[p]=0;		
	}
	void push_up(int p){
		(mx[ls]>mx[rs])?(mx[p]=mx[ls],cnt[p]=cnt[ls]):
			((mx[ls]==mx[rs])?(mx[p]=mx[ls],cnt[p]=cnt[ls]+cnt[rs]):
			(mx[p]=mx[rs],cnt[p]=cnt[rs]));
		return;
	}
	void build(int p,int l,int r){
		tag[p]=mx[p]=cnt[p]=0;
		if(l==r){cnt[p]=1;return;}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		push_up(p);
	}
	void add(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr){mx[p]+=f;tag[p]+=f;return;}
		int mid=(l+r)>>1;push_down(p);
		(mid>=nl)&&(add(ls,l,mid,nl,nr),1);
		(mid<nr)&&(add(rs,mid+1,r,nl,nr),1);
		push_up(p);return;
	}
}T;
int MX[N],tx;
int MN[N],ty;
long long ans;
int used[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();rep(i,n)a[i]=read();
	rep(i,n){
		long long x=a[i];while(x)c[i]+=__builtin_popcount(x&((1<<16)-1)),x>>=16;
		used[c[i]]=1;
	}
	For(k,0,63)if(used[k]){
		T.build(1,1,n);tx=ty=0;
		rep(i,n){
			while(tx&&a[i]>=a[MX[tx]]){
				if(c[MX[tx]]==k)f=-1,T.add(1,1,n,MX[tx-1]+1,MX[tx]);
				tx--;
			}if(c[i]==k)f=1,T.add(1,1,n,MX[tx]+1,i);
			MX[++tx]=i;
			while(ty&&a[i]<=a[MN[ty]]){
				if(c[MN[ty]]==k)f=-1,T.add(1,1,n,MN[ty-1]+1,MN[ty]);
				ty--;
			}if(c[i]==k)f=1,T.add(1,1,n,MN[ty]+1,i);
			MN[++ty]=i;
			(mx[1]==2)&&(ans+=cnt[1]);
		}
		
	}cout<<ans<<endl;
	return 0;
}