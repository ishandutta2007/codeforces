#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=4e5+9;
const int lim=1e17;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,k,d;
int L[N],a[N];
map<int,int>last;
int mn[N<<2],tag[N<<2];
struct tree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	void push_up(int p){mn[p]=min(mn[ls],mn[rs]);}
	void f(int p,int ta){
		if(ta==lim){mn[p]=lim,tag[p]=lim;return;}
		mn[p]+=ta,tag[p]+=ta;
	}
	void push_down(int p){if(!tag[p])return;f(ls,tag[p]);f(rs,tag[p]);tag[p]=0;}
	void change(int p,int l,int r,int x,int v){
		if(l==r){mn[p]=v;return;}
		int mid=(l+r)>>1;push_down(p);
		if(mid>=x)change(ls,l,mid,x,v);
		else change(rs,mid+1,r,x,v);
		push_up(p);
		return ;
	}
	void add(int p,int l,int r,int nl,int nr,int x){
		if(nl<=l&&r<=nr){f(p,x);return;}
		int mid=(l+r)>>1;push_down(p);
		if(mid>=nl)add(ls,l,mid,nl,nr,x);
		if(mid<nr)add(rs,mid+1,r,nl,nr,x);
		push_up(p);
	}
	int get(int p,int l,int r,int x){
		if(l==r){return l;}
		int mid=(l+r)>>1,f=0;push_down(p);
		if(mn[ls]<=x)f=get(ls,l,mid,x);
		else f=get(rs,mid+1,r,x);
		push_up(p);
		return f;
	}
}T;
int s1[N],s2[N],t1,t2;
int ans,len;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),k=read(),d=read();
	if(d==0){
		int now=0;
		rep(i,n){
			a[i]=read()+1e9;
			if(a[i]==a[i-1])now++;
			else now=1;
			if(now>len)len=now,ans=i;
		}
		cout<<ans-len+1<<" "<<ans<<endl;
		return 0;
	}
	rep(i,n){
		a[i]=read()+1e9;L[i]=L[i-1];
		if(a[i]%d!=a[i-1]%d)L[i]=i;
		chmx(L[i],last[a[i]]+1);
		last[a[i]]=i;
	}
	rep(i,n)a[i]/=d;
	t1=t2=1;s1[1]=s2[1]=0;
	T.add(1,1,n,1,n,lim); 
	rep(i,n){
		if(L[i]>1)T.add(1,1,n,1,L[i]-1,lim);
		T.change(1,1,n,i,i);
		while(t1>=2&&a[i]>=a[s1[t1]]){//mx
			T.add(1,1,n,s1[t1-1]+1,s1[t1],-a[s1[t1]]);
			t1--;
		}T.add(1,1,n,s1[t1]+1,i,a[i]);s1[++t1]=i;
		while(t2>=2&&a[i]<=a[s2[t2]]){
			T.add(1,1,n,s2[t2-1]+1,s2[t2],+a[s2[t2]]);
			t2--;
		}T.add(1,1,n,s2[t2]+1,i,-a[i]);s2[++t2]=i;
		
		int mxl=T.get(1,1,n,k+i);
		if(i-mxl+1>len)len=i-mxl+1,ans=i;
	}
	cout<<ans-len+1<<" "<<ans<<endl;
	return 0;
}