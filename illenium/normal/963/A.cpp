#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
#define modc 1000000009
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

char c[maxn];
ll n,a,b,k;

ll quickpow(ll a,ll b)
{
    ll ret=1;
    a%=modc;
    while(b)
    {
        if(b&1) ret=(ret*a)%modc;
        b>>=1;
        a=(a*a)%modc;
    }
    return(ret%modc+modc)%modc;
}

ll inv(ll a){return quickpow(a,modc-2);}

int main()
{
	cin>>n>>a>>b>>k; scanf("%s",c);
    ll a1=0,ans;
    for(int i=0;i<k;++i)
    {
        if(c[i]=='+') a1=((a1+quickpow(a,n-i)*quickpow(b,i))%modc+modc)%modc;
        else   a1=((a1-quickpow(a,n-i)*quickpow(b,i))%modc+modc)%modc;
    }
    ll q=quickpow(inv(a),k)*quickpow(b,k)%modc;
    if(q!=1)
    {
        ans=a1*(quickpow(q,(n+1)/k)-1)%modc*inv(q-1)%modc;
        while(ans<0) ans+=modc;
    }
    else ans=a1*((n+1)/k)%modc;
    cout<<ans<<endl;
    return 0;
}