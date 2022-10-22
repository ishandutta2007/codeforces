#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
const int mn=1e5+10;
int ans[mn];
bool sw[mn];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        ll n,k;
        cin>>n>>k;
        k--;
        if(n<64&&k>=(1LL<<(n-1))){printf("-1\n");continue;}
        iota(ans,ans+n,0);
        memset(sw,0,sizeof(sw[0])*n);
        for(int i=0;i<min(n-1,63LL);i++){
            sw[n-2-i]=(k>>i)&1;
        }
        for(int i=0,st=0;i<n;i++){
            if(!sw[i]){
                reverse(ans+st,ans+i+1);
                st=i+1;
            }
        }
        for(int i=0;i<n;i++)printf("%d ",ans[i]+1);
        printf("\n");
    }
}