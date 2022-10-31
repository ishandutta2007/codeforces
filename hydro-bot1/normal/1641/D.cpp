// Hydro submission #6332f9d15741ce022119322a@1664285138104
#include <bits/stdc++.h>
typedef long long llt;
typedef unsigned uint;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return(a<b)?a=b,true:false;}
template<typename T>bol _min(T&a,T b){return(b<a)?a=b,true:false;}
template<typename T>T power(T base,T index,T mod){return((index<=1)?(index?base:1):(power(base*base%mod,index>>1,mod)*power(base,index&1,mod)))%mod;}
template<typename T>T lowbit(T n){return n&-n;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<typename T>T lcm(T a,T b){return(a!=0||b!=0)?a/gcd(a,b)*b:(T)0;}
template<typename T>T exgcd(T a,T b,T&x,T&y){if(!b)return y=0,x=1,a;T ans=exgcd(b,a%b,y,x);y-=a/b*x;return ans;}
uint W[100005],A[100005][5],Ans[6][6];
std::vector<uint>QAQ;
typedef std::pair<uint,uint>Pair;
Pair P[6][6];
uint m;
uint lcs(uint a,uint b)
{
    for(uint i=0;i<m;i++)for(uint j=0;j<m;j++)
        if(A[a][i]==A[b][j])Ans[i+1][j+1]=Ans[i][j]+1,P[i+1][j+1]=Pair(i,j);
        else Ans[i+1][j+1]=std::max(Ans[i+1][j],Ans[i][j+1]),P[i+1][j+1]=Ans[i+1][j]>Ans[i][j+1]?Pair(i+1,j):Pair(i,j+1);
    QAQ.clear();
    Pair now=Pair(m,m);
    while(now!=Pair())
    {
        if(P[now.first][now.second].first<now.first&&P[now.first][now.second].second<now.second)QAQ.push_back(A[a][now.first]);
        now=P[now.first][now.second];
    }
    return Ans[m][m];
}
uint Id[100005],Now[100005],cnt=0;
const uint Lim[]={0,1,5,15,40,100};
int main()
{
    uint n;uint ans=-1;
    scanf("%u%u",&n,&m);
    for(uint i=0;i<n;i++)
    {
        for(uint j=0;j<m;j++)scanf("%u",A[i]+j);
        scanf("%u",W+i);
        std::sort(A[i],A[i]+m);
        Id[i]=i;
    }
    std::sort(Id,Id+n,[&](uint a,uint b){return W[a]<W[b];});
    for(uint i=0;i<n;i++)
    {
        uint p=Id[i];
        std::map<std::vector<uint>,uint>LCNT;
        for(uint j=0;j<cnt;j++)
        {
            uint c=lcs(p,Now[j]);
            LCNT[QAQ]++;
            if(!c)_min(ans,W[p]+W[Now[j]]);
        }
        bol b=true;
        for(auto p:LCNT)if(p.second>Lim[m-p.first.size()]){b=false;break;}
        if(b)Now[cnt++]=p;
    }
    printf("%d\n",(int)ans);
    return 0;
}