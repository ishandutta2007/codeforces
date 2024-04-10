// Hydro submission #6332f94e5741ce022119316d@1664285007188
// Problem: E. Three Days Grace
// Contest: Codeforces - Codeforces Round #804 (Div. 2)
// URL: https://codeforces.com/contest/1699/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms

#include <bits/stdc++.h>
typedef long long llt;
typedef unsigned uint;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return(a<b)?a=b,true:false;}
template<typename T>bol _min(T&a,T b){return(b<a)?a=b,true:false;}
template<typename T>T lowbit(T n){return n&-n;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T lcm(T a,T b){return(a!=0||b!=0)?a/gcd(a,b)*b:(T)0;}
template<typename T>T exgcd(T a,T b,T&x,T&y){if(b!=0){T ans=exgcd(b,a%b,y,x);y-=a/b*x;return ans;}else return y=0,x=1,a;}
template<typename T>T power(T base,T index,T mod)
{
    T ans=1%mod;
    while(index)
    {
        if(index&1)ans=ans*base%mod;
        base=base*base%mod,index>>=1;
    }
    return ans;
}
uint Ans[5000005];bol S[5000005];
namespace S2
{
    uint B;
    uint Sum[6000005],W[5000005];
    voi build(uint m)
    {
        B=sqrt(m)+1;
        for(uint i=0;i<=B*B;i++)Sum[i]=0;
        for(uint i=0;i<=B;i++)W[i]=0;
    }
    voi add(uint v){Sum[v]++,W[v/B]++;}
    voi del(uint v){Sum[v]--,W[v/B]--;}
    uint find()
    {
        for(uint i=B;~i;i--)if(W[i])for(uint j=B-1;~j;j--)if(Sum[i*B+j])return i*B+j;
        return-1;
    }
};
int main()
{
    uint t;
    scanf("%u",&t);
    while(t--)
    {
        uint n,m,x=-1,ans=-1;
        scanf("%u%u",&n,&m);uint w=sqrt(m)+10;
        S2::build(m);
        for(uint i=1;i<=m;i++)Ans[i]=i,S[i]=false;
        for(uint i=0,v;i<n;i++)scanf("%u",&v),_min(x,v),S[v]=true;
        for(uint i=1;i<=m;i++)if(S[i])S2::add(Ans[i]);
        if(x>w)_min(ans,S2::find()-x);
        for(uint q=w;q;q--)
        {
            for(uint i=q*q;i<=m;i+=q)
            {
                if(S[i])S2::del(Ans[i]);
                _min(Ans[i],std::max(q,Ans[i/q]));
                if(S[i])S2::add(Ans[i]);
            }
            if(q<=x)_min(ans,S2::find()-q);
        }
        printf("%u\n",ans);
    }
    return 0;
}