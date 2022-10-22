#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=109;
int n,k;
int a[M*M],b[M],vis[M];
int cnt[M*M];
pii ans[M];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n*k;++i){
        cin>>a[i];
        int l=b[a[i]],r=i;
        b[a[i]]=i;
        if(vis[a[i]]||!l)continue;
        bool flag=0;
        for(int j=l;j<=r;++j){
            if(cnt[j]==(n-1)/(k-1)+1)flag=1;
        }
        if(!flag){
            ans[a[i]]=make_pair(l,r);
            for(int j=l;j<=r;++j){
                cnt[j]++;
            }
            vis[a[i]]=1;
        }
    }
    for(int i=1;i<=n;++i)cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    return 0;
}
/*
a
a
*/