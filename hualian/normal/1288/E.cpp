#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=6e5+9;
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
#define lowbit(x) (x&-x)
int sum[N];
void add(int x,int v){x+=300000;while(x<N)sum[x]+=v,x+=lowbit(x);}
int get(int x,int res=0){x+=300000;while(x)res+=sum[x],x-=lowbit(x);return res;}
int mn[N],mx[N];
int n,m,pos[N];
int main(){
//	freopen(".in","r",stdin);
//	froepen(".out","w",stdout);
	n=read(),m=read();
	rep(i,n)mn[i]=mx[i]=i;
	rep(i,n)add(i,1),pos[i]=i;int idx=1;
	while(m--){
		int x=read();mn[x]=1;
		chmx(mx[x],get(pos[x]));
		add(pos[x],-1);pos[x]=--idx;
		add(pos[x],1);
	}rep(i,n)chmx(mx[i],get(pos[i])),printf("%d %d\n",mn[i],mx[i]);
	return 0;
}