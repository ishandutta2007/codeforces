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
const int mn=5e3+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
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
    string s,t;
    cin>>n>>s>>t;
    int b,e;
    for(int i=0;i<n;i++)if(s[i]!=t[i]){b=i;break;}
    for(int i=n-1;i>=0;i--)if(s[i]!=t[i]){e=i;break;}
    int ans=0;
    bool gud=1,gud2=1;
    for(int i=b;i+1<=e;i++){
        if(s[i]!=t[i+1])gud=0;
        if(t[i]!=s[i+1])gud2=0;
    }
    ans+=gud,ans+=gud2;
    printf("%d",ans);
}