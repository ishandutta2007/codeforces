#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=2e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
const ll half=(mod+1)/2;
const double PI=acos(-1);

int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        vector<ll>pos,neg;
        ll ps=0,ns=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            if(x>=0)pos.push_back(x),ps+=x;
            else neg.push_back(x),ns-=x;
        }
        sort(pos.begin(),pos.end(),greater<ll>());
        sort(neg.begin(),neg.end());
        if(ps==ns){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        if(ps>ns){
            for(ll x:pos)printf("%lld ",x);
            for(ll x:neg)printf("%lld ",x);
        }
        else{
            for(ll x:neg)printf("%lld ",x);
            for(ll x:pos)printf("%lld ",x);
        }
        printf("\n");
    }
}