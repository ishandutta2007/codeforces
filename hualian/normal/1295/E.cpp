#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=4e5+9;
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;
int a[N],pos[N];
int mn[N<<2],tag[N<<2];
struct tree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	void push_up(int p){mn[p]=min(mn[ls],mn[rs]);}
	void f(int x,int tg){tag[x]+=tg,mn[x]+=tg;}
	void push_down(int p){f(ls,tag[p]);f(rs,tag[p]);tag[p]=0;}
	void add(int p,int l,int r,int nl,int nr,int v){
		if(nl<=l&&r<=nr){f(p,v);return;}
		int mid=(l+r)>>1;push_down(p);
		if(mid>=nl)add(ls,l,mid,nl,nr,v);
		if(mid<nr)add(rs,mid+1,r,nl,nr,v);
		push_up(p);
	}
	int get(int p,int l,int r,int x){
		if(l==r)return mn[p];
		int mid=(l+r)>>1,res=0;push_down(p);
		if(mid>=x)res=get(ls,l,mid,x);
		else res=get(rs,mid+1,r,x);
		push_up(p);
		return res;
	}
}T;
int ans=1e18;
signed main(){
//	freopen(".in","r",stdin);
//	froepen(".out","w",stdout);
	n=read();
	rep(i,n)pos[read()]=i;
	rep(i,n)a[i]=read();
	rep(i,n)T.add(1,1,n,pos[i],n,a[pos[i]]);
	T.add(1,1,n,n,n,ans);
	ans=mn[1];
	rep(i,n){
		int m=pos[i];
		T.add(1,1,n,m,n,-a[pos[i]]);
		if(m-1)T.add(1,1,n,1,m-1,a[pos[i]]);
		chmn(ans,mn[1]);
	}
	cout<<ans<<endl;
	return 0;
}
//orz moyujiang