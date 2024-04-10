#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>
struct seg_tree{
    vector<T> seg;
    function<T(T,T)> func=plus<>();
    int n;
    seg_tree(int n){this->n=n;seg.resize(n*2);}
    void set_func(function<T(T,T)> f){func=f;}
    void update(int a,T b){
        seg[a+=n]=b;
        for(a>>=1;a;a>>=1)seg[a]=func(seg[a*2],seg[a*2+1]);
    }
    int query(int a,int b){
        a+=n,b+=n;
        if(a==b)return seg[a];
        T l=seg[a++],r=seg[b--];
        for(;a<=b;a>>=1,b>>=1){
            if(a&1)l=func(l,seg[a]),a++;
            if(!(b&1))r=func(seg[b],r),b--;
        }
        return func(l,r);
    }
};
vector<ll> m[11];
int dig(ll x){
    int ans=0;
    for(;x;x/=10,ans++);
    return ans;
}
ll p[11],num[200000];
int bs(int a,int x){
    int cur=-1;
    for(int i=1<<17;i;i>>=1){
        if(cur+i>=m[a].size())continue;
        if(m[a][cur+i]<x)cur+=i;
    }
    return cur;
}
int main(){
    int n,i,j;
    ll k;
    scanf("%d%lld",&n,&k);
    p[0]=1;
    for(i=1;i<=10;i++)p[i]=p[i-1]*10%k;
    for(i=0;i<n;i++){
        scanf("%lld",num+i);
        for(j=0;j<=10;j++){
            m[j].push_back(num[i]*p[j]%k);
        }
    }
    for(i=0;i<=10;i++)sort(m[i].begin(),m[i].end());
    ll ans=0;
    for(i=0;i<n;i++){
        ll tar=(k*1000000000LL-num[i])%k,d=dig(num[i]);
        ans+=bs(d,tar+1)-bs(d,tar);
        if((num[i]*p[d]+num[i])%k==0)ans--;
    }
    printf("%lld",ans);
}