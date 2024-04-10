// Hydro submission #62ccbc434125dc528b1caa2c@1657584708210
#include <bits/stdc++.h>
using namespace std;
const int N(1e5),B{300},K{N/B+1};
long long sum[B],val[B],rep[B],a[N],res[N];
int n;
inline int L(int b){return b*K;}
inline int R(int b){return min(n-1,L(b+1)-1);}
void construct(int l,int r,int p)
{
    for (int b{l/K};b<=r/K;++b)
        if (val[b]!=-1)
        {
            for (int i{L(b)};i<=R(b);++i)
                a[i]=val[b];
            val[b]=-1;
        }
    for (int i{l};i<=r;++i)
    {
        sum[i/K]+=abs(a[i]-p);
        res[i]+=abs(a[i]-p);
        a[i]=p;
    }
}
void modify(int l,int r,int p)
{
    if (l/K==r/K) return construct(l,r,p);
    construct(l,R(l/K),p);construct(L(r/K),r,p);
    for (int i{l/K+1};i<r/K;++i)
        if (val[i]!=-1)
        {
            sum[i]+=abs(p-val[i])*K;
            rep[i]+=abs(p-val[i]);
            val[i]=p;
        }
        else
        {
            for (int j{L(i)};j<=R(i);++j)
            {
                sum[i]+=abs(a[j]-p);
                res[j]+=abs(a[j]-p);
                a[j]=p;
            }
            val[i]=p;
        }
}
long long get(int l,int r)
{
    long long ans{0};
    for (int i{l};i<=r;++i)
        ans+=res[i]+rep[i/K];
    return ans;
}
long long query(int l,int r)
{
    if (l/K==r/K) return get(l,r);
    long long ans{get(l,R(l/K))+get(L(r/K),r)};
    for (int i{l/K+1};i<r/K;++i)
        ans+=sum[i];
    return ans;
}
int main()
{
    int m;cin>>n>>m;
    for (int i{0};i<=(n-1)/K;++i)
        val[i]=-1;
    for (int i{0};i<n;++i)
        a[i]=i+1;
    while (m--)
    {
        int op,l,r;
        scanf("%d %d %d",&op,&l,&r);
        --l;--r;
        if (op==1)
        {
            scanf("%d",&op);
            modify(l,r,op);
        }
        else printf("%lld\n",query(l,r));
    }
    return 0;
}