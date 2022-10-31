#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define N 300001
int i,j,k,n,m,t,l,r,nmsl[1005000];
int su(int a,int b){a+=b;return (a>=M)?a-M:a;}
struct jz{
	int f[2][2];
	jz(){memset(f,0,sizeof(f));}
	jz operator+(const jz a)const{
		jz res;
		int i,j,k;
		for(i=0;i<=1;i++)for(j=0;j<=1;j++)res.f[i][j]=su(f[i][j],a.f[i][j]);
		return res;
	}
	jz operator*(const jz a)const{
		jz res;
		int i,j,k;
		for(i=0;i<=1;i++)for(j=0;j<=1;j++)for(k=0;k<=1;k++)res.f[i][j]=su(res.f[i][j],1ll*f[i][k]*a.f[k][j]%M);
		return res;
	}
}t1;
void NMSL(jz &f,int a,int b,int c,int d){f.f[0][0]=a; f.f[0][1]=b; f.f[1][0]=c; f.f[1][1]=d;}
struct SB{
	#define md ((l+r)/2)
	#define ls (id*2)
	#define rs (ls+1)
	jz f[1300500],t[1300500];
	void init(int id,int l,int r){
		if(l==r){
			if(!nmsl[l])NMSL(f[id],1,0,0,0);
			else NMSL(f[id],0,1,0,0);
			NMSL(t[id],1,0,0,1);
			return;
		}
		NMSL(t[id],1,0,0,1);
		init(ls,l,md); init(rs,md+1,r);
		f[id]=f[ls]+f[rs];
	}
	void push(int id,int l,int r){
		t[ls]=t[ls]*t[id];t[rs]=t[rs]*t[id];f[ls]=f[ls]*t[id];f[rs]=f[rs]*t[id];
		NMSL(t[id],1,0,0,1);
	}
	void add(int id,int l,int r,int x,int y,jz w){
		if(x>y)return;
		if(x<=l&&r<=y){f[id]=f[id]*w;t[id]=t[id]*w;return;}
		push(id,l,r);
		if(x<=md)add(ls,l,md,x,y,w);
		if(y>md)add(rs,md+1,r,x,y,w);
		f[id]=f[ls]+f[rs];
	}
}sb;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	cin>>l>>r; l++; r++;
	for(i=l;i<=r;i++)nmsl[i]=1;
	t--;
	sb.init(1,1,N);
	while(t--){
		cin>>l>>r;l++;r++;
		NMSL(t1,1,2,1,2);sb.add(1,1,N,l,r,t1);
		NMSL(t1,3,0,1,2);sb.add(1,1,N,1,l-1,t1);sb.add(1,1,N,r+1,N,t1);
	}
	cout<<sb.f[1].f[0][1]%M;
}