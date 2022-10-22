#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int mn=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int bac[mn];
int main(){
    #ifdef LOCAL
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
    #endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=0;
    ll cum=0;
    set<ll>t;
    for(int i=0;i<n;i++){
        if(s[i]=='0')bac[i]=i;
        else if(i)bac[i]=bac[i-1];
        else bac[i]=-1;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            t.insert(i),cum+=i;
            auto it=t.lower_bound(bac[i]);
            if(it==t.begin())cum-=-1;
            else{
                cum-=*prev(it);
                t.erase(prev(it));
            }
        }
        ans+=cum;
    }
    printf("%lld\n",ans);
}