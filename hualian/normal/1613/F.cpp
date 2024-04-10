#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int p=998244353;
const int N=262144+9;
const int G=3,Gi=332748118;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,all;
int s[N];
int b[N],a[N];
int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
int fac[N],ifac[N];
void init(int n){
	fac[0]=1;rep(i,n)fac[i]=fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);Rof(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%p;
	assert(fac[10]*ifac[10]%p==1);
}
int len,L;
int r[N];
void prepare(int all){
	len=1,L=0;
	while(len<=all)len<<=1,L++;
	rep(i,len-1)r[i]=(r[i>>1]>>1)|((i&1)<<L-1);
	return;
}
int upd(int x){return x>=p?x-p:x;}
void NTT(int *A,int op){
	For(i,0,len-1)if(i<r[i])swap(A[i],A[r[i]]);
	for(int mid=1;mid<len;mid<<=1){ 
		int wn=inv(op?Gi:G,(p-1)/(mid<<1));
		for(int j=0;j<len;j+=(mid<<1))
		for(int k=0,w=1;k<mid;k++,(w*=wn)%=p){
			int x=A[j+k],y=w*A[j+k+mid]%p;
			A[j+k]=upd(x+y);
			A[j+k+mid]=upd(x+p-y);
		}
	}if(!op)return;
	int INV=inv(len);
	For(i,0,len-1)(A[i]*=INV)%=p;
	
}
int C(int n,int m){return fac[n]*ifac[m]%p*ifac[n-m]%p;}
int d[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();init(N-1);
	rep(i,n-1)d[read()]++,d[read()]++; 
	For(i,2,n)d[i]--;
	rep(i,n)s[d[i]]++;
	a[0]=1;
	Rof(i,n,1)if(s[i]){//(1+ix)^s[i] 
		int res=1;
		For(j,0,s[i]){
			b[j]=C(s[i],j)*res%p;
			(res*=p-i)%=p;
		}
		all+=s[i];prepare(all);
		For(j,s[i]+1,len-1)b[j]=0;
		NTT(a,0);NTT(b,0);
		For(i,0,len-1)(a[i]*=b[i])%=p;
		NTT(a,1);
	}
	int ans=0;
	For(i,0,n)(ans+=a[i]*fac[n-i])%=p;
//	For(i,0,n)cout<<a[i]<<" ";puts("");
	cout<<(ans%p+p)%p<<endl;
	return 0;
}