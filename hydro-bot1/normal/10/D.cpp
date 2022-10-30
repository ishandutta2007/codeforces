// Hydro submission #625a565137de167dd82d6349@1650087506394
#include <stdio.h>
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
uint Ans[505],Last[505];
uint A[505],B[505];
uint S[505],cnt=0;
int main()
{
    uint n,m;
    scanf("%u",&n);for(uint i=0;i<n;i++)scanf("%u",A+i);
    scanf("%u",&m);for(uint i=0;i<m;i++)scanf("%u",B+i);
    for(uint i=1;i<=n;i++)
    {
        uint t=0,v=0;
        for(uint j=1;j<=m;j++)
        {
            if(A[i-1]==B[j-1])
            {
                if(_max(Ans[j],v+1))Last[j]=t;
            }
            else if(B[j-1]<A[i-1]&&Ans[j]>v)v=Ans[t=j];
        }
    }
    uint ans=0,p=0;
    for(uint i=1;i<=m;i++)if(_max(ans,Ans[i]))p=i;
    printf("%u\n",ans);
    while(p)S[cnt++]=p-1,p=Last[p];
    while(cnt--)printf("%u%c",B[S[cnt]]," \n"[!cnt]);
    return 0;
}