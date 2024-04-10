#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T>void chkmin(T &x,const T &y){
    if(y<x){
        x=y;
    }
}
template<class T>void chkmax(T &x,const T &y){
    if(y>x){
        x=y;
    }
}
template<class T>void sort(vector<T> &a){
    sort(a.begin(),a.end());
}
template<class T,class Cmp>void sort(vector<T> &a,Cmp cmp){
    sort(a.begin(),a.end(),cmp);
}
void solve_single_test(int test_id=1){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    chkmin(m,n);
    vector<ll> mn(m,1e18),suf(m);
    mn[m-1]=k;
    ll sum=0,ans=0,p=1e18;
    for(int i=0;i<n;++i){
        int a;
        scanf("%d",&a);
        sum+=a;
        if(i%m==0){
            ll x=1e18;
            for(int j=m-1;j>=0;--j){
                chkmin(x,mn[j]);
                suf[j]=x;
            }
            p=1e18;
        }
        ll x=sum-1ll*i/m*k;
        chkmax(ans,x-suf[i%m]);
        chkmax(ans,x-p-k);
        chkmin(mn[i%m],x);
        chkmin(p,mn[i%m]);
    }
    printf("%lld\n",ans);
}
void solve_multiple_tests(){
    int tests;
    scanf("%d",&tests);
    for(int i=1;i<=tests;++i){
        solve_single_test(i);
    }
}
int main(){
    solve_single_test();
    return 0;
}