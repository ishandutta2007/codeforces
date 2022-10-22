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
const int mn=2e5+10;
const ll mod=1e9+7;

int a[mn];
int solve(int l,int r,int lev){
    if(r<l)return 0;
    if(!lev)return 0;
    int m=lower_bound(a+l,a+r+1,1<<lev)-a;
    for(int i=l;i<=r;i++)a[i]&=(1<<lev)-1;
    return min(solve(l,m-1,lev-1)+max(r-m,0),solve(m,r,lev-1)+max(m-l-1,0));
}
int main(){
#ifdef LOCAL
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    printf("%d\n",solve(0,n-1,29));
}