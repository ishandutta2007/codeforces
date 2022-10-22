#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=998244353;
const int mn=2e5+10;
ll bit[mn];
void upd(int a,ll b){for(;a<mn;a+=a&-a)bit[a]+=b;}
ll qu(int a){ll b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
int n;
int bs(ll x){
    int cur=0;
    ll sum=0;
    for(int i=1<<17;i;i>>=1){
        if(cur+i>n)continue;
        if(sum+bit[cur+i]<x)cur+=i,sum+=bit[cur];
    }
    return cur+1;
}
ll v[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>v[i],upd(i,v[i]);
    while(k--){
        int a,b;
        cin>>a>>b;
        upd(a,b-v[a]),v[a]=b;
        int t=1;
        ll s=v[1];
        for(t=bs(s*2);t<=n;t=bs(s*2)){
            s=qu(t);
            ll l=qu(t-1);
            if(l*2==s){
                printf("%d\n",t);
                break;
            }
        }
        if(t>n)printf("-1\n");
    }
}