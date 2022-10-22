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
const int mn=2e5+10;

int d[mn];
int sgn(int x){return x/abs(x);}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n,l,r;
        cin>>n>>l>>r;
        for(int i=0;i<n;i++)d[i]=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            d[x-1]+=(i<l?1:-1);
        }
        int num=(l-r)/2,ans=abs(num);
        for(int i=0;i<n;i++){
            if(!num)break;
            while(ll(num)*d[i]>0&&abs(d[i])>1){
                //cerr<<i<<endl;
                num-=sgn(num);
                d[i]-=sgn(d[i])*2;
            }
        }
        for(int i=0;i<n;i++){
            if(!num)break;
            while(ll(num)*d[i]>0){
                //cerr<<i<<endl;
                num-=sgn(num);
                d[i]-=sgn(d[i])*2;
            }
        }
        int ex=0;
        for(int i=0;i<n;i++)ex+=abs(d[i]);
        ans+=ex/2;
        printf("%d\n",ans);
    }
}