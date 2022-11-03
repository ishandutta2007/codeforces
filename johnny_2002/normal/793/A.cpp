#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N=1e5+10;
const int MOD=1e9+7;


int n,k,a[N];
ll solve(){
    ll ans=0;
    int bar=*min_element(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if ((a[i]-bar)%k) return -1;
        ans+=(a[i]-bar)/k;
    }
    return ans;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<solve();
}