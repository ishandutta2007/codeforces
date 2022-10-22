#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
typedef vector<int> vi;
typedef vector<ll> vl;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;

int main(){
    #ifdef LOCAL
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
    #endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        bool c1=1,c2=1;
        for(int i=0;i<n;i++){
            if(s[i]=='<')c1=0;
            if(s[i]=='>')c2=0;
        }
        if(c1||c2){
            printf("%d\n",n);
            continue;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(s[i]=='-')||(s[(i+1)%n]=='-');
        }
        printf("%d\n",ans);
    }
}