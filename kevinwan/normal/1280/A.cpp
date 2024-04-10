#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const int mn=3e5+10;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        string s;
        cin>>s;
        ll ans=s.size();
        for(int i=0;i<x;i++){
            ll lr=(ans-i-1);
            ans=(ans+lr*(s[i]-'1'))%mod;
            int cur=s.size();
            if(cur<x){
                s.resize(ans);
                for(int i=cur;i<s.size();i++){
                    s[i]=s[i-lr];
                }
            }
        }
        if(ans<0)ans+=mod;
        printf("%lld\n",ans);
    }
}