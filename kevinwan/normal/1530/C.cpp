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
typedef vector<ll> vll;
const int mn=4e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=1e9+7;


ll a[mn],b[mn];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        ll diff=0;
        for(int i=0;i<n;i++)cin>>a[i],diff-=a[i];
        for(int i=0;i<n;i++)cin>>b[i],diff+=b[i];
        sort(b,b+n);
        sort(a,a+n);
        for(int i=0;i<n/4;i++)diff+=a[i]-b[i];
        int at=n/4-1;
        int ot=n/4;
        for(int cur=0;true;++cur){
            //cerr<<diff<<" "<<at<<endl;
            if(diff<=0){
                printf("%d\n",cur);
                break;
            }
            diff-=100;
            if(at>=0&&(n+cur)%4!=3)diff+=b[at--];
            if((n+cur)%4==3){
                if(ot<n)diff+=a[ot++];
                else diff+=100;
            }
        }
    }
}