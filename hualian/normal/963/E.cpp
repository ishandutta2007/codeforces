#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int p=1e9+7;
const int N=110;
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
int n,a1,a2,a3,a4;
int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
struct node{
	int a[N];
	node(){memset(a,0,sizeof a);}
	int& operator[](int i){return a[i];}
	node operator+(const node&x)const{
		node A;For(i,0,2*n+1)A[i]=(a[i]+x.a[i])%p;
		return A;
	}
	node operator-(const node&x)const{
		node A;For(i,0,2*n+1)A[i]=(a[i]+p-x.a[i])%p;
		return A;
	}
	node operator-(int x)const{
		node A=(*this);A[0]=(A[0]+p-1)%p;
		return A;
	}
	node operator*(int x)const{
		node A;For(i,0,2*n+1)A[i]=a[i]*x%p;
		return A;
	}
}A[N][N],a[N];int idx;
bool dis(int x,int y){return (x-n)*(x-n)+(y-n)*(y-n)<=n*n;}
int ans[N];
void guess(int n){
	rep(i,n){
		int r=0;For(j,i,n)if(a[j][i]){r=i;break;}
		assert(r);swap(a[i],a[r]);
		int x=a[i][i];
		rep(j,n+1)(a[i][j]*=inv(x))%=p;
		For(j,i+1,n){
			x=a[j][i];
			For(l,i,n+1)a[j][l]=(a[j][l]+p-x*a[i][l]%p)%p;
		}
	}
	ans[n]=a[n][n+1];
	Rof(i,n-1,1){
		ans[i]=a[i][n+1];
		For(j,i+1,n)ans[i]=(ans[i]+-a[i][j]*ans[j]%p)%p;
	}
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();a1=read(),a2=read(),a3=read(),a4=read();
	int sum=(a1+a2+a3+a4)%p;sum=inv(sum);
	a1=a1*sum%p;a2=a2*sum%p;a3=a3*sum%p;a4=a4*sum%p;
	For(i,0,2*n)For(j,0,2*n)if(dis(i,j)){
		A[i][j][++idx]++;
		break;
	}
	assert(idx==2*n+1);
	For(j,0,2*n)For(i,0,2*n)if(dis(i,j)){
		A[i][j+1]=A[i][j]-A[i+1][j]*a3-1;
		if(i)A[i][j+1]=A[i][j+1]-A[i-1][j]*a1;
		if(j)A[i][j+1]=A[i][j+1]-A[i][j-1]*a2;
		A[i][j+1]=A[i][j+1]*inv(a4);
	}
	For(i,0,2*n)Rof(j,2*n+1,0)if(dis(i,j)){a[i+1]=A[i][j+1];a[i+1][2*n+2]=p-a[i+1][0];break;}
	guess(2*n+1);
	int res=0;
	rep(i,2*n+1)(res+=ans[i]*A[n][n][i])%=p;
	res+=A[n][n][0];res+=p;res%=p;
	cout<<res<<endl;
	return 0;
}