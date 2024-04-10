#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=220;
const int p=1e9+7;
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
int s[N][N],c[N][N],k,l,r;
int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
struct node{
	int a,b;
	node(int aa=0,int bb=0):a(aa),b(bb){}
	node operator+(const node x)const{return node((a+x.a)%p,(b+x.b)%p);}
	node operator-(const node x)const{return node((a+p-x.a)%p,(b+p-x.b)%p);}
	node operator*(const node x)const{return node((a*x.a+b*x.b*5)%p,(a*x.b+b*x.a)%p);}
	node operator/(const node x)const{
		node res,z=x;
		if(z.b!=0)z.b=p-z.b;
		res=(*this)*z;
		return res*inv((x.a*x.a-x.b*x.b*5)%p+p);
	}
};

node inv(node x,int base=p-2){
	node res(1,0);
	while(base){
		if(base&1)res=res*x;
		x=x*x;
		base>>=1;
	}return res;
}
node sum(node x,int n){
	return (inv(x,n+1)-1)/(x-1);
}
node get(node x,int l,int r){
	if(x.a==1&&x.b==0)return x*(r-l+1);
	return sum(x,r)-sum(x,l-1);
}
void solve(){
	int ans=0;
	node A,B,x,y;
	A=node(0,inv(5));
	B=node(0,p-inv(5));
	x=node(inv(2),inv(2));
	y=node(inv(2),p-inv(2));
	For(i,0,k){
		node res;
		For(j,0,i){
			res=res+inv(A,j)*inv(B,i-j)*get(inv(x,j)*inv(y,i-j),l,r)*c[i][j];
		}
		res=res*s[k][i];
		ans=(ans+p+inv(-1,k-i)*res.a)%p;
	}
	rep(i,k)(ans*=inv(i))%=p;
	cout<<ans<<endl;
	return;
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	k=read();l=read()+2,r=read()+2;
	rep(i,k)c[i][0]=1;
	c[0][0]=1;rep(i,k)rep(j,i)c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
	s[0][0]=1;rep(i,k)rep(j,i)s[i][j]=(s[i-1][j-1]+s[i-1][j]*(i-1))%p;
	solve();
	return 0;
}