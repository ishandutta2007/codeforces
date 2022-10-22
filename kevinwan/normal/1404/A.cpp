#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int n1=0,nn=0,ded=0;
        for(int i=0;i<k;i++){
            bool z=0,o=0;
            for(int j=i;j<n;j+=k){
                if(s[j]=='0')z=1;
                if(s[j]=='1')o=1;
            }
            if(z&&o)ded=1;
            else if(o)n1++;
            else if(!z)nn++;
        }
        if(ded){
            printf("NO\n");
            continue;
        }
        if(n1<=k/2&&k/2<=n1+nn)printf("YES\n");
        else printf("NO\n");
    }
}