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
const int mn=1e3+34;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
ll num[10];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    ll k;
    string s;
    cin>>k>>s;
    for(char c:s)num[c-'0']++,k-=c-'0';
        k=max(k,0LL);
    ll ans=0;
    for(int i=0;i<9;i++){
        if(k>num[i]*(9-i)){
            k-=num[i]*(9-i);
            ans+=num[i];
        }
        else{
            ans+=(k+8-i)/(9-i);
            break;
        }
    }
    printf("%lld",ans);
}