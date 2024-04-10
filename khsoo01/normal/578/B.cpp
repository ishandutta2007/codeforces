#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define sq(X) ((X)*(X))
#define INF 0x7fffffff
#define MAXN
using namespace std;
ll n,k,x,gop=1,a[200005],mx;

struct segtree{
    ll val[888888],lim;
    void init(ll N) {
        for(lim=1;lim<N;lim<<=1);
    }
    void build() {
        ll i;
        for(i=lim;--i;) {
            val[i]=val[i*2]|val[i*2+1];
        }
    }
    ll query(int S,int E) {
        ll ret=0;
        S+=lim; E+=lim;
        while(S<E) {
            if(S%2==1)ret|=val[S++];
            if(E%2==0)ret|=val[E--];
            S>>=1; E>>=1;
        }
        if(S==E)ret|=val[S];
        return ret;
    }
}seg;

int main()
{
    ll i;
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n>>k>>x;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    for(i=0;i<k;i++) {
        gop*=x;
    }
    seg.init(n);
    for(i=0;i<n;i++) {
        seg.val[i+seg.lim]=a[i];
    }
    seg.build();
    mx=max(seg.query(1,n-1)|(a[0]*gop),seg.query(0,n-2)|(a[n-1]*gop));
    for(i=1;i<n-1;i++) {
        mx=max(mx,seg.query(0,i-1)|seg.query(i+1,n-1)|(a[i]*gop));
    }
    cout<<mx;
}