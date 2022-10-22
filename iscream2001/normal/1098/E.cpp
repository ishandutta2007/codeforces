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
int n,x;

#define pa pair<int,int>

int tp=0;
pa q[50];
LL a[100050];
LL num[100050],sum[100050];

LL check(LL M){
	LL re=0,t;
	int i=1,j;
	LL A,B,V,x;
	if(a[1]){
		t=min(M,a[1]);
		re+=(LL)a[1]*t-(LL)t*(t-1)/2;
	}
	for(LL r=2;r<=mx;++r){
		if(!a[r]) continue;
		t=min(M/r,a[r]);
		re+=(LL)a[r]*t-(LL)t*(t-1)/2;
		if(sum[r]-sum[i-1]<=M){
			re+=(LL)(num[r-1]-num[i-1])*(LL)a[r];
			continue;
		}
		while(sum[r-1]-sum[i]>=M) ++i;
		j=i;
		while(sum[r]-sum[j]>=M&&j+1!=r) ++j;
		if(r-1>=j+1)
			re+=(LL)(num[r-1]-num[j])*(LL)a[r];
		for(LL k=i;k<=j;++k){
			if(!a[k]) continue;
			A=r;B=k;
			V=0;
			if(r-1>=k+1) V=sum[r-1]-sum[k];
			V=M-V;
			if(V<=0) continue;
			t=min(a[r],(V-B)/A);
			if(t<=0) continue;
			x=likegcd(-A,V,B,t);
			x=x-(V/B);
			re+=x;
			t=min(a[r],(V-(LL)a[k]*B)/A);
			if(t<=0) continue;
			x=likegcd(-A,V,B,t);
			x=x-(V/B);
			re-=x;
			re+=(LL)a[k]*t;
		}
		i=j;
	}
	return re;
}
int main(){
	pa aaa;
	int x;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		q[++tp]=pa(x,i);
		for(int j=tp-1;j>=1;--j)
			q[j].first=gcd(q[j].first,x);
		int tmp=1;
		for(int j=2;j<=tp;++j)
			if(q[j].first!=q[j-1].first)
				q[++tmp]=q[j];
		tp=tmp;
		for(int j=1;j<=tp;++j)
			a[q[j].first]+=(j==tp?i+1:q[j+1].second)-q[j].second;
	}
	//for(int i=1;i<=)
	for(int i=1;i<=mx;++i){
		num[i]=num[i-1]+a[i];
		sum[i]=sum[i-1]+(LL)a[i]*i;
	}
	LL P=(LL)n*(n+1)/2;
	P=P*(P+1)/2;
	P=(P+1)/2;
	LL l=1,r=sum[mx],mid;
	while(l!=r){
		mid=l+r>>1;
		if(check(mid)>=P) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}
/*

*/