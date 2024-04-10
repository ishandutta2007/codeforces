#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#include<bitset>
#define DB long double
#define LL long long
#define ui unsigned int
#define ull unsigned long long
using namespace std;
  
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
    if(x>9) Out(x/10);
    putchar('0'+x%10);
}
int gcd(int x,int y){
    if(!y) return x;
    return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
LL likegcd(LL a,LL b,LL c,LL n){
    LL re,p;
    if(c<0)
        return likegcd(-a,-b,-c,n);
    if(a<0||b<0){
        re=likegcd(a%c+c,b%c+c,c,n);
        re+=n*(n+1)/2*((a/c)-1);
        re+=(n+1)*((b/c)-1);
        return re;
    }
    
    if(a==0) {
        re=(b/c)*(n+1);
        return re;
    }
    if(a>=c||b>=c){
        p=likegcd(a%c,b%c,c,n);
        re=n*(n+1)/(LL)2*(a/c);
        re+=(b/c)*(n+1);
        re+=p;
        return re;
    }
    LL m=(a*n+b)/c;
    p=likegcd(c,c-b-1,a,m-1);
    re=-p+n*m;
    return re;
}
const DB eps=1e-6;
const int N=5e4+10;
const int mx=1e5+1;
const LL P=998244353;

struct date{
	int t,l,r,w;
}p[200]; 
bool operator < (date A,date B){
	return A.t<B.t;
}

int n;
int x[55],y[55],h[200],a[200];
int T;
LL get(int k){
	if(k<0) return 0;
	int cnt=0;
	for(int i=1;i<=n;++i){
		p[++cnt]=date{x[i]-k,y[i]-k,y[i]+k+1,1};h[cnt]=y[i]+k+1;
		p[++cnt]=date{x[i]+k+1,y[i]-k,y[i]+k+1,-1};h[cnt]=y[i]-k;
	}
	sort(p+1,p+1+cnt);sort(h+1,h+1+cnt);
	cnt=unique(h+1,h+1+cnt)-h-1;
	LL re=0;
	for(int i=1;i<=n+n;++i){
		if(p[i].t!=p[i-1].t)
			for(int j=1;j<cnt;++j)
				if(a[j]) re+=(LL)(p[i].t-p[i-1].t)*(h[j+1]-h[j]);
		int l=lower_bound(h+1,h+cnt+1,p[i].l)-h;
		int r=lower_bound(h+1,h+cnt+1,p[i].r)-h;
		for(int j=l;j<r;j++) a[j]+=p[i].w;
	}
	return re;
}
LL cha(int t){
	return get(t)-get(t-1);
}
const LL inv2=qpow((LL)2,P-2,P);
const LL inv3=qpow((LL)3,P-2,P);
const LL inv6=qpow((LL)6,P-2,P);

int main(){
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;++i) scanf("%d%d",&x[i],&y[i]);
	int now=0,l,r,mid,to;
	LL ans=0;
	//cout<<inv2<<" "<<inv6<<endl;
	while(now<=T){
		l=to=now;
		r=T;
		LL g=cha(now),e=cha(now+1)-g;
		while(l!=r){
			mid=l+r+1>>1;
			LL y=cha(mid);
			if(y!=g+(mid-now)*e) r=mid-1;
			else l=mid;
		}
		to=l;
		LL y=e*(to-now)%P*(to-now+1)%P*(to-now+2)%P*inv6%P;
		(g=g%P*(to-now)%P*(to-now+1)%P*inv2%P)%=P;
		(ans+=get(now)%P*(to-now+1)%P+y+g)%=P;
		now=to+1;
		//cout<<to<<" "<<y<<" "<<g<<endl;
	}
	//cout<<ans<<endl;
	cout<<((get(T)%P*(T+1)%P)-ans+P)%P;
}
/*

*/