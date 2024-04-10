#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct node{
	int x,y,id;
	bool operator<(const node&X)const{
		return x<X.x||(x==X.x&&(y<X.y||(y==X.y&&id<X.id)));
	}
}a[N];
int b[N],lim,n,m;
int sum[N],ans[N];
map<pair<int,int>,bool>mp;
bool del[N];
#define lowbit(x) (x&-x)
void add(int x){while(x<=n+m)sum[x]++,x+=lowbit(x);}
int get(int x,int res=0){while(x)res+=sum[x],x-=lowbit(x);return res;}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	rep(i,n)a[i].x=read(),a[i].y=b[++lim]=read();
	rep(i,n)mp[make_pair(a[i].x,a[i].y)]=1;
	mp[make_pair(0,0)]=1;
	rep(i,m){
		a[i+n].x=read(),a[i+n].y=read(),a[i+n].id=i;
		if(mp[make_pair(a[i+n].x,a[i+n].y)])a[i+n].id=1e9,ans[i]=1;
	}
	sort(a+1,a+1+n+m);sort(b+1,b+1+lim);lim=unique(b+1,b+1+lim)-b-1;
	int X=0,pre=-1;
	rep(i,n+m)if(a[i].id&&a[i].id<=m){
		if(a[i].x==pre)continue;
		int y=upper_bound(b+1,b+1+lim,a[i].y)-b-1;
		if(a[i].y==b[y]&&del[y])continue;
		ans[a[i].id]=(a[i].y+X-get(y)==a[i].x);
	}else if(a[i].id==0){
		int y=lower_bound(b+1,b+1+lim,a[i].y)-b;
		int D=X-get(y);
		if(a[i].x<D+a[i].y){if(!del[y])add(y),del[y]=1;}
		else if(a[i].x>D+a[i].y&&pre!=a[i].x)pre=a[i].x,X++;
	}
	rep(i,m)puts(ans[i]?"LOSE":"WIN");
	return 0;
}