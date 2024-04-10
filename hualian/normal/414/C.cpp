#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=3e6+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,ans,idx,a[N];
int *A[2*N];
int res[N],all[N];
void solve(int p,int l,int r,int dep){
	if(l==r){A[p]=new int[1];A[p][0]=a[l];return;}
	int mid=(l+r)>>1;
	solve(p<<1,l,mid,dep-1),solve(p<<1|1,mid+1,r,dep-1);
	int ls=p<<1,rs=p<<1|1;
	int j=1,len=1<<dep-1;A[p]=new int[1<<dep];
	int a1=0,a2=0;
	rep(i,len){
		while(j<=len&&A[ls][j-1]<A[rs][i-1])j++;
		a1+=j-1;
	}
	j=len;
	Rof(i,len,1){
		while(j&&A[ls][j-1]>A[rs][i-1])j--;
		a2+=len-j;
	}
	res[dep]+=a1;
	all[dep]+=a1+a2;
	merge(A[ls],A[ls]+len,A[rs],A[rs]+len,A[p]);
	return;
}

signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();rep(i,1<<n)a[i]=read();
	solve(1,1,1<<n,n);
	int m=read();
	For(i,0,n)ans+=(res[i]=all[i]-res[i]);
	while(m--){
		int x=read();
		For(i,0,x)ans-=res[i],res[i]=all[i]-res[i],ans+=res[i];
		cout<<ans<<endl;
	}
	return 0;
}