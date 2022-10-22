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
int a[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        bool g1=1;
        for(int i=1;i<=n;i++)g1&=(a[i]==i);
        vector<int>v;
        for(int i=1;i<=n;i++)if(a[i]!=i)v.push_back(i);
        if(g1)printf("0\n");
        else if(v.back()-v[0]+1==v.size())printf("1\n");
        else printf("2\n");
    }
}