// LUOGU_RID: 90452614
#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int p=1e9+7;
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
int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
int n,all,f[N],a[N],ans=0;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	rep(i,n)all+=(a[i]=read());
	f[1]=(all-1)*(all-1)%p*inv(all)%p;
	f[2]=(2*f[1]+p-1)%p;
	For(i,3,100000)f[i]=((2*f[i-1]-f[i-2]-(all-1)*inv(all-i+1)%p)%p+p)%p;
	if(all<=100000)f[all]=0;
	rep(i,n)(ans+=f[a[i]])%=p;
	cout<<ans<<endl;
	return 0;
}