#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
// const int mod=1e9+7;
#define inf 0x3f3f3f3f
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int>b(n+1);
    for(int i=0;i<n;++i) cin>>b[i];
    int m=1,l=0;
    while(m<=n) m<<=1,++l;
    b.resize(m);
    reverse(b.begin(),b.end());
    for(int i=0;i<l;++i)
        for(int j=m-1;j>=0;--j)
        if(!(j>>i&1))
        b[j]^=b[j^(1<<i)];//cn
    for(int i=0;i<m-n;++i) b[i]=0;//cm-n0
    for(int i=0;i<l;++i)
        for(int j=m-1;j>=0;--j)
        if(!(j>>i&1))
        b[j]^=b[j^(1<<i)];//b=g(c)
    for(int i=0;i<l;++i)
        for(int j=0;j<m;++j)
        if(j>>i&1)
        b[j]^=b[j^(1<<i)];//a=f(b)
    for(int i=0;i<n;++i)
        cout<<b[n-1-i]<<" \n"[i==n-1];
}
/*
f(a) a
g(a) a

b=f(a) <=> a=f(b)
b=g(a) <=> a=g(b)

b=f(a)am-n0
c=g(b)cm-n0

0<=i<m,0<=j<m-i-1
ajcik&i=icibkk&j=jbkajk
kk&(i|j)=(i|j)
k2^(mxbit-popcount(i|j))
popcount(i|j)=mxbit(i|j)=m-1aj
j<m-i-1(i|j)<=i+j<m-10<=i<m,0<=j<m-i-1ajci
i<=m-n-1j<m-(m-n-1)-1=n(j<n)ajcij>=naj=0ci=0 (0<=i<=m-n-1<m-n)

bncncm-n0c
b=g(c),a=f(b)a
*/