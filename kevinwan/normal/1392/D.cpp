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
const ll mod=998244353;
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>v;
        v.push_back(1);
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1])v.push_back(1);
            else v.back()++;
        }
        if(s[0]==s[n-1]&&v.size()>1)v[0]+=v.back(),v.pop_back();
        if(v.size()==1){
            if(n<=2)printf("0\n");
            else printf("%lld\n",(n+2)/3);
            continue;
        }
        int ans=0;
        for(int x:v){
            cerr<<x<<" ";
            ans+=x/3;
        }
        printf("%d\n",ans);
        cerr<<endl;
    }
}