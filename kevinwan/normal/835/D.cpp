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
const int mn=5e3+34;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int lev[mn][mn];
bool pal[mn][mn];
int ans[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        for(int j=0;i+j<n&&i-j>=0;j++){
            if(s[i+j]==s[i-j])pal[i-j][i+j]=1;
            else break;
        }
        for(int j=0;i+j+1<n&&i-j>=0;j++){
            if(s[i+j+1]==s[i-j])pal[i-j][i+j+1]=1;
            else break;
        }
    }
    for(int l=0;l<n;l++)for(int i=0;i+l<n;i++){
        int j=i+l;
        if(pal[i][j]){
            lev[i][j]=min(lev[i][(i+j-1)/2],lev[(i+j)/2+1][j])+1;
        }
        cerr<<i<<' '<<j<<' '<<lev[i][j]<<endl;
        ans[lev[i][j]]++;
    }
    for(int i=n-1;i>=1;i--)ans[i]+=ans[i+1];
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}