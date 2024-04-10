#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define int long long
using namespace std;
const int N=4e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int a[N],b[N],nt[N],mn[N];
int sum[N],n;
int sta[N],top;
inline void add1(int x,int val){
	while(x){
		sum[x]=min(sum[x],val);
		x-=lowbit(x);
	}return;
}
inline int get1(int x){
	int res=1e9+7;
	while(x<=2*n){
		res=min(res,sum[x]);
		x+=lowbit(x);
	}return res;
}

inline void add2(int x,int val){
	while(x<=2*n){
		sum[x]=min(sum[x],val);
		x+=lowbit(x);
	}return;
}
inline int get2(int x){
	int res=1e9+7;
	while(x){
		res=min(res,sum[x]);
		x-=lowbit(x);
	}return res;
}
signed main(){
	int t=read();
	while(t--){
		n=read();top=0;int ans=0,lim;
		for(int i=0;i<=2*n+1;i++)mn[i]=1e9+7,sum[i]=1e9+7;
		for(int i=1;i<=n;i++)
			a[i]=read(),b[i]=a[i];
		a[n+1]=n+1;sta[++top]=n+1;
		lim=n;sort(b+1,b+1+n);
		lim=unique(b+1,b+1+lim)-b-1;
		for(int i=1;i<=n;i++)
			a[i]=lower_bound(b+1,b+1+lim,a[i])-b;
		for(int i=n;i>=1;i--){
			while(a[i]>a[sta[top]]&&top)top--;
			nt[i]=sta[top];
			sta[++top]=i;
		}
		add2(2*n,n+1);
		for(int i=n;i>=1;i--){
			int now=nt[i];
			nt[i]=get1(a[i]);
			add1(a[i],now);
		}
		nt[n+1]=nt[n]=nt[n-1]=n+1;
		for(int i=n;i>=1;i--){
			nt[i]=min(nt[i],nt[i+1]);
			mn[i]=nt[i];
		}
		
		
		for(int i=0;i<=2*n+1;i++)sum[i]=1e9+7;
		top=0;
		
		a[n+1]=-1;sta[++top]=n+1;
		for(int i=n;i>=1;i--){
			while(a[i]<a[sta[top]]&&top)top--;
			nt[i]=sta[top];
			sta[++top]=i;
		}
		add2(2*n,n+1);
		for(int i=n;i>=1;i--){
			int now=nt[i];
			nt[i]=get2(a[i]);
			add2(a[i],now);
		}
		nt[n+1]=nt[n]=nt[n-1]=n+1;
		mn[n+1]=n+1;
		for(int i=n;i>=1;i--){
			nt[i]=min(nt[i],nt[i+1]);
			mn[i]=min(mn[i],nt[i]);
			mn[i]=min(mn[i],mn[i+1]);
			ans+=mn[i]-i;
		}cout<<ans<<endl;
	}
	return 0;
}