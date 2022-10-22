#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mn=2e5+10;
const ll mod=1e9+7;

ll a[mn];

int hailveshy(){
    ll n,w;
    cin>>n>>w;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]>=(w+1)/2&&a[i]<=w){
            printf("1\n%d\n",i);
            return 0;
        }
    }
    vector<int>v;
    ll sum=0;
    for(int i=1;i<=n;i++)if(a[i]<(w+1)/2){
        sum+=a[i];
        v.push_back(i);
        if(sum>=(w+1)/2){
            printf("%d\n",v.size());
            for(int x:v)printf("%d ",x);
            printf("\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

int main(){
#ifdef LOCAL
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int tc;
    cin>>tc;

    for(int tcc=1;tcc<=tc;tcc++){
        hailveshy();
    }
}