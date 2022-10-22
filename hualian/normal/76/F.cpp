#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define int long long
#define mk make_pair
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=3e5+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,V,flag;
pair<int,int>a[N];
int b[N],lim;
void find(int &x){x=lower_bound(b+1,b+1+lim,x)-b;}
int sum[N],ans;
void add(int x,int v){while(x<=n)chmx(sum[x],v),x+=lowbit(x);}
int get(int x,int res=-1e9){while(x)chmx(res,sum[x]),x-=lowbit(x);return res;}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	rep(i,n){
		int x=read(),y=read();
		a[i]=mk(x,y);
	}V=read();
	a[++n]=mk(0,0);b[++lim]=0;
	rep(i,n){
		int x=a[i].first,y=a[i].second*V;
		a[i]=mk(y-x,y+x);b[++lim]=x+y;
	}
	sort(b+1,b+1+lim);lim=unique(b+1,b+1+lim)-b-1;
	int qwe=lower_bound(b+1,b+1+lim,0)-b;
	rep(i,n)find(a[i].second);
	sort(a+1,a+1+n);
	memset(sum,0xc0,sizeof sum);flag=1;
	rep(i,n){
		int res=get(a[i].second);
		if(a[i].first==0&&a[i].second==qwe&&flag){flag=0;chmx(res,0);}
		add(a[i].second,res+1);
		chmx(ans,res+1);
	}cout<<ans-1<<" ";
	memset(sum,0,sizeof sum);flag=1;
	ans=0;
	 rep(i,n){
	 	if(a[i].first==0&&a[i].second==qwe&&flag){flag=0;continue;}
		int res=get(a[i].second);
		add(a[i].second,res+1);
		chmx(ans,res+1);
	}cout<<ans<<endl;
	return 0;
}