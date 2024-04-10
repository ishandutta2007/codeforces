#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxk=1e4+5;
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll times(ll x,ll y,ll mod){
	ll ans=0;
	while(y){
		if(y&1)ans=(ans+x)%mod;
		x=(x+x)%mod;
		y>>=1;
	}
	return ans;
}
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
ll p,q;
ll exgcd(ll a,ll b){
	if(b==0){
		p=1;q=0;
		return a;
	}
	ll g=exgcd(b,a%b);
	ll tmp=p;
	p=q;
	q=tmp-a/b*q;
	return g;
}
ll a[maxk],b[maxk];
ll excrt(int n){
    ll x=b[1],M=a[1];
	for(int i=2;i<=n;i++){
		ll g=exgcd(M,a[i]),mod;
		mod=M/g*a[i];
		if((b[i]-x)%g){puts("NO");exit(0);}
		p=times(p,((b[i]-x)%a[i]+a[i])%a[i]/g,a[i]);
		x=(x+p*M%mod+mod)%mod;
		M=mod;
	}
    return x==0?M:x;
}
int main(){
    ll n,m,x=1,y;
    int k;
    n=read();m=read();k=read();
    for(int i=1;i<=k;i++){
        a[i]=read();
        x=x/gcd(x,a[i])*a[i];
        if(x>n){puts("NO");exit(0);}
        b[i]=(a[i]+1-i%a[i])%a[i];
    }
    y=excrt(k);
    if(y+k-1>m){puts("NO");exit(0);}
    for(int i=1;i<=k;i++)
        if(gcd(x,y+i-1)^a[i]){puts("NO");exit(0);}
    puts("YES");
//    cout<<x<<" "<<y<<endl;
    return 0;
}