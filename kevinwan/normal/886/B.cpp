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
const int mn=2e5+34;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int lv[mn];
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
    memset(lv,0x3f,sizeof(lv));
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        lv[x]=i;
    }
    int ans=0;
    for(int i=1;i<mn;i++)if(lv[i]<lv[ans])ans=i;
    printf("%d",ans);
}