// Hydro submission #625a1783cc64917dc4671d8b@1650071466032
// Problem: E. Equilibrium
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <algorithm>
#include <math.h>
#include <set>
#include <map>
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
template<const uint Sqrt=1500>
struct Block
{
    uint A[Sqrt*Sqrt],B[Sqrt];
    Block()
    {
        for(uint i=0;i<Sqrt*Sqrt;i++)A[i]=0;
        for(uint i=0;i<Sqrt;i++)B[i]=0;
    }
    voi insert(uint v){A[v]++,B[v/Sqrt]++;}
    voi erase(uint v){A[v]--,B[v/Sqrt]--;}
    uint findmin()
    {
        for(uint i=0;i<Sqrt;i++)if(B[i])
            for(uint j=0;j<Sqrt;j++)if(A[i*Sqrt+j])return i*Sqrt+j;
        return-1;
    }
    uint findmax()
    {
        for(uint i=Sqrt-1;~i;i--)if(B[i])
            for(uint j=Sqrt-1;~j;j--)if(A[i*Sqrt+j])return i*Sqrt+j;
        return-1;
    }
};
Block<>B;
uint Siz;
struct ques{uint l,r,t;llt ans;};
bol cmp1(const ques&a,const ques&b){return(a.l/Siz==b.l/Siz)?(((a.l/Siz)&1)?b.r<a.r:(a.r<b.r)):(a.l<b.l);}
bol cmp2(const ques&a,const ques&b){return a.t<b.t;}
llt A[100005],_S[100005],User[100005];
uint S[100005];
ques Q[100005];
uint l,r;
std::set<llt>Set;
std::map<llt,uint>Map;
voi insert(uint m){B.insert(S[m+1]);}
voi erase(uint m){B.erase(S[m+1]);}
int main()
{
    uint n,m;llt v;
    scanf("%u%u",&n,&m),Siz=sqrt(n);
    for(uint i=0;i<n;i++)scanf("%lld",A+i);
    for(uint i=0;i<n;i++)scanf("%lld",&v),Set.insert(_S[i+1]=_S[i]+(A[i]-=v));
    Set.insert(0);
    while(!Set.empty())User[Map[*Set.rbegin()]=Set.size()]=*Set.rbegin(),Set.erase(*Set.rbegin());
    for(uint i=0;i<=n;i++)S[i]=Map[_S[i]];
    for(uint i=0;i<m;i++)scanf("%u%u",&Q[i].l,&Q[i].r),Q[i].l--,Q[i].t=i;
    std::sort(Q,Q+m,cmp1),l=r=0;
    for(uint i=0;i<m;i++)
    {
        ques&qs=Q[i];
        while(l>qs.l)insert(l-1),l--;
        while(r<qs.r)insert(r),r++;
        while(l<qs.l)erase(l),l++;
        while(r>qs.r)erase(r-1),r--;
        qs.ans=(B.findmax()==S[l]&&S[r]==S[l])?User[S[l]]-User[B.findmin()]:-1;
    }
    std::sort(Q,Q+m,cmp2);
    for(uint i=0;i<m;i++)printf("%lld\n",Q[i].ans);
    return 0;
}