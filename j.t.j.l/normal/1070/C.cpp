#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K,M;
LL T[4000010],T2[4000010];
const int MM = 1000001;
struct query
{
    int c,p;
};
vector<query>q[1000010];

void add(int x,int L,int R,int pos,LL v)
{
    T[x] += v * pos;
    T2[x] += v;
    if (L == R) return;
    int mid = (L + R) / 2;
    if (pos <= mid)
        add(x*2,L,mid,pos,v);
    else
        add(x*2+1,mid+1,R,pos,v);
}

void gao(query t)
{
    add(1,1,MM,t.p,t.c);
}

int getpos(int x,int L,int R,int KK)
{
    if (L == R) return L;
    int mid = (L + R) / 2;
    if (T2[x*2] < KK) return getpos(x*2+1,mid+1,R,KK-T2[x*2]);
    return getpos(x*2,L,mid,KK);
}
typedef pair<LL,LL> pll;
pll add(pll a,pll b)
{
    return pll(a.first+b.first,a.second+b.second);
}
pll getsum(int x,int L,int R,int ql,int qr)
{
    //printf("fuck %d %d %d %d %d\n",x,L,R,ql,qr);
    //getchar();
    if (L == ql && R == qr) return pll(T[x],T2[x]);
    int mid = (L + R) / 2;
    if (qr <= mid) return getsum(x*2,L,mid,ql,qr);
    if (ql > mid) return getsum(x*2+1,mid+1,R,ql,qr);
    return add(getsum(x*2,L,mid,ql,mid), getsum(x*2+1,mid+1,R,mid+1,qr));
}

int main()
{
    scanf("%d%d%d",&N,&K,&M);
    for (int i=1;i<=M;i++)
    {
        int l,r,c,p;
        scanf("%d%d%d%d",&l,&r,&c,&p);
        q[l].push_back((query){c,p});
        q[r+1].push_back((query){-c,p});
    }
    LL ans = 0;
    for (int i=1;i<=N;i++)
    {
        for (auto t:q[i]) gao(t);
        int pos = getpos(1,1,MM,K);
        pll ret;
        if (pos == 1)
            ret = pll(0,0);
        else
            ret = getsum(1,1,MM,1,pos - 1);
        if (pos == MM)
        {
            ans += ret.first;
        }
        else
        {
            ans += ret.first;
            ans += 1LL * (K - ret.second) * pos;
        }
    }
    printf("%lld\n",ans);
}