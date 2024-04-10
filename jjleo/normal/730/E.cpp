#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace  std;
#define ll long long
#define rep(i,m,n) for(int i=m;i<=n;i++)
const int N = 1e3+10;
const double eps = 1e-8;
struct node{
    int a,d,id;
    void input(){
        cin>>a>>d;
    }
    bool operator < (const node &x)const{
        return a>x.a||(a==x.a&&id<x.id);
    }
};
node t[N];
int check(int u,int v){
    node a=t[u],b=t[v];
    node aa=a,bb=b;
    aa.a+=a.d;
    bb.a+=b.d;
    if(a<b&&bb<aa)return 1;
    if(b<a&&aa<bb)return 1;
    if(a<b&&bb<a&&aa<bb)return 2;
    if(b<a&&aa<b&&bb<aa)return 2;
    if(a<b&&b<aa&&aa<bb)return 2;
    if(b<a&&a<bb&&bb<aa)return 2;
    return 0;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,1,n){
        t[i].input();
        t[i].id=i;
    }
    sort(t+1,t+1+n);
    ll ans=0;
    rep(i,1,n){
        rep(j,i+1,n){
            ans+=check(i,j);
        }
    }
    cout<<ans<<endl;
    return 0;
}