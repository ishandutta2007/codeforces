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
const ll mod=998244353;

int a[mn];
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
        string s;
        cin>>s;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if((i&&s[i]==s[i-1])||(i>=2&&s[i]==s[i-2])){
                s[i]='*';
                ans++;
            }
        }
        printf("%d\n",ans);
    }
}