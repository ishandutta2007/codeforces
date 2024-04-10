#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
const int N=3e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n;
int a[N];
int last[N],nt[N],mxx[N],mx[N];
#define lowbit(x) (x&-x)
void add(int pos,int x){while(pos<=n)chmx(mx[pos],x),pos+=lowbit(pos);}
int get(int pos,int res=-1e9){while(pos)chmx(res,mx[pos]),pos-=lowbit(pos);return res;}
int main(){
	n=read();memset(mx,0xc0,sizeof(mx));
	rep(i,n)a[i]=read();
	Rof(i,n,1){
		if(!last[a[i]])last[a[i]]=i;
		else nt[i]=last[a[i]];
	}
	int pre=0,Last=0;
	rep(i,n){
		chmx(pre,mxx[i]);
		if(nt[i]<Last)continue;
		int tmp=get(n-i);Last=nt[i];
		mxx[nt[i]]=max(pre+nt[i]-i-1,max(tmp+nt[i]-1,mxx[nt[i]]));
		add(n-nt[i]+1,mxx[nt[i]]-nt[i]);
	}
	cout<<pre<<endl;
	return 0;
}