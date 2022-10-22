#include<bits/stdc++.h>
#define int long long
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
vector<int>e[N];
int l[N],r[N],n;
int mx[N],ans=0;
void dfs(int x,int fa){
	mx[x]=0;
	for(int to:e[x]){
		dfs(to,x);
		mx[x]+=mx[to];
	}
	chmn(mx[x],r[x]);
	if(mx[x]>=l[x])return;
	if(mx[x]<l[x])mx[x]=r[x],ans++;
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();
	while(T--) {
		n=read();ans=0;
		rep(i,n)e[i].clear();
		For(i,2,n){
			int fa=read();
			e[fa].push_back(i);
		}
		rep(i,n) l[i]=read(),r[i]=read();
		dfs(1,0);cout<<ans<<endl; 
	}
	
	return 0;
}