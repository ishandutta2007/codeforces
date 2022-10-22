//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=5e5+5,mod=1e9+7;
int n;
inline int add(int x){return (x>=mod)?x-mod:x;}
inline int sub(int x){return (x<0)?x+mod:x;}
const __int128 one=1;
struct point{
	__int128 x,y;
	point operator *(int v)const{return (point){1ll*v*x,1ll*v*y};}
	point operator +(point p)const{return (point){x+p.x,y+p.y};}
	point operator -(point p)const{return (point){x-p.x,y-p.y};}
	__int128 operator *(point p)const{return x*p.y-y*p.x;}
}a[2*maxn],s0[2*maxn],s1[2*maxn];
int s2[2*maxn],s3[2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int calc(int l,int r,point p){
	if(r<l)r+=n;
	int res=0;
	res=sub(sub(s3[r]-s3[l])-sub(1ll*s2[l]*(r-l)%mod));
	res=sub(res-sub((p*(s1[r-1]-s1[l-1]-s0[l-1]*(r-l)))%mod));
	res=sub(res-sub(((s1[r]-s1[l]-s0[l]*(r-l))*p)%mod));
	return res;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i].x=a[i+n].x=read(),a[i].y=a[i+n].y=read();
	for(int i=1;i<=2*n;i++)s0[i]=s0[i-1]+a[i];
	for(int i=1;i<=2*n;i++)s1[i]=s1[i-1]+s0[i];
	for(int i=1;i<=2*n;i++)s2[i]=add(s2[i-1]+sub((a[i]*a[i-1])%mod));
	for(int i=1;i<=2*n;i++)s3[i]=add(s3[i-1]+s2[i]);
	ll S=0,s=0;
	for(int i=3;i<=n;i++)S+=(a[i]-a[1])*(a[i-1]-a[1]);
	int p=2,sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		while(2ll*(s+(a[p%n+1]-a[i])*(a[p]-a[i]))<=S)s+=(a[p%n+1]-a[i])*(a[p]-a[i]),p=p%n+1;
		if((S%2==0)&&s==(S>>1))cnt++;
		sum=add(sum+calc(i%n+1,p,a[i]));
		s-=(a[p]-a[i%n+1])*(a[p]-a[i]);
	}
	sum=sub(sum-1ll*(cnt>>1)*((S>>1)%mod)%mod);
	int res=1ll*n*(n-3)/2%mod*(S%mod)%mod;
	res=sub(res-add(sum+sum));
	printf("%d\n",res);
    return 0;
}