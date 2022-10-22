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
const int mn=1e5+10;
const ll mod=1e9+7;
bool vis[mn];
int rem[mn];
int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    string s;
    ll x,y;
    cin>>s>>x>>y;
    int n=s.size();
    if(y<x){
        swap(x,y);
        for(char&c:s){
            if(c=='0')c='1';
            else if(c=='1')c='0';
        }
    }
    ll cur=0;
    for(int i=n-1;i>=0;i--){
        if(i<n-1)rem[i]=rem[i+1]+(s[i+1]!='0');
        if(s[i]=='0'){
            cur+=rem[i]*x;
        }
        else{
            cur+=(n-i-1-rem[i])*y;
        }
    }
    ll ans=cur;
    int num=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')num++;
        if(s[i]=='?'){
            cur-=(i-num)*x+(n-i-1-rem[i])*y;
            cur+=num*y+rem[i]*x;
            ans=min(ans,cur);
        }
    }
    printf("%lld\n",ans);
}