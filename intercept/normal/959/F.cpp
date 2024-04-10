#include<bits/stdc++.h>
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
const int M=1e5+9;
const int X=20;
int n,q,k;
int ans[M],a[M];
vector<pii>p[M];
int lb[X+9];
void add(int x){
    for(int i=X;i>=0;--i){
        if(x>>i&1){
            if(!lb[i]){
                lb[i]=x;
                k++;
                break;
            }
            x^=lb[i];
        }
    }
}
bool check(int x){
    for(int i=X;i>=0;--i){
        if(x>>i&1){
            if(!lb[i])return 0;
            x^=lb[i];
        }
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=q;++i){
        int l,x;
        scanf("%d%d",&l,&x);
        p[l].eb(x,i);
    }
    for(int i=1;i<=n;++i){
        add(a[i]);
        for(auto o:p[i]){
            if(check(o.fi))ans[o.se]=kpow(2,i-k);
            else ans[o.se]=0;
        }
    }
    for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
    return 0;
}