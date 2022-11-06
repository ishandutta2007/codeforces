#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
} 

int n,q;
#define Maxn 105

int a[Maxn],c[Maxn];

int b[Maxn],num[Maxn];

int F[1000010];

const int Mod=1000000007;
namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
}using namespace modular;

void calc(int X){
	//a[i]-b[i]-X
	ll sum=0;int all=0;
	F[0]=1;
	rep(i,1,n){
		all+=c[i];
		rep(k,1,all)F[k]=add(F[k],F[k-1]);
		per(k,all,c[i]+1)F[k]=dec(F[k],F[k-c[i]-1]);
		sum+=b[i]+X;
		rep(k,0,min(sum-1,(ll)all))F[k]=0;
	}
	int res=0;rep(i,0,all)res=add(res,F[i]);
	printf("%d\n",res); 
}

int main(){
	rd(n);
	rep(i,1,n)rd(c[i]);
	rep(i,2,n){
		rd(b[i]);
		b[i]+=b[i-1];
	}
	rd(q);rep(i,1,q)rd(num[i]);
	rep(i,1,q)calc(num[i]);
}