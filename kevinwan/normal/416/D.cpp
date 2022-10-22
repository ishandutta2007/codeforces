#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll a[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int s=1,ans=1;
    ll m=-1,b=-1,p=-1;
    if(a[s]!=-1)p=s;
    for(int i=2;i<=n;i++){
        bool ded=0;
        if(a[i]==-1){
            if(m==-1&&b==-1)continue;
            if(m*i+b<=0)ded=1;
        }
        else{
            if(p==-1){
                p=i;
            }
            else if(m==-1&&b==-1){
                m=(a[i]-a[p])/(i-p);
                b=a[i]-m*i;
                if(m*p+b!=a[p])ded=1;
                if(m*s+b<=0)ded=1;
            }
            else{
                if(m*i+b!=a[i])ded=1;
            }
        }
        if(ded){
            s=i,ans++;
            m=b=p=-1;
            if(a[s]!=-1)p=s;
        }
    }
    printf("%d",ans);
}