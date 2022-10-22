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
        vector<int>o;
        for(int i=0;i<n/2;i++){
            o.push_back(i);
            o.push_back(n-1-i);
        }
        if(n&1)o.push_back(n/2);
        string a,b;
        cin>>a>>b;
        vector<int>ans;
        reverse(o.begin(),o.end());
        int s=0;
        for(int i=n-1;i>=0;i--,s^=1){
            if((a[o[i]]^s)==b[i])ans.push_back(0);
            ans.push_back(i);
        }
        printf("%d ",ans.size());
        for(int x:ans)printf("%d ",x+1);
        printf("\n");
    }
}