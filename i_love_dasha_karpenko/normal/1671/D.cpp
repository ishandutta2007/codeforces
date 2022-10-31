#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cmath>
#include<ctime>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5+7;
const int INF = 1e9;
int A[N];
void solve(){
    int n,x;
    cin>>n>>x;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
    }
    ll res = 0;
    int mi = INF,mx = -INF;
    for(int i = 1;i<=n;++i){
        mx = max(mx,A[i]);
        mi = min(mi,A[i]);
    }
    for(int i = 1;i<n;++i){
        
        res+=abs(A[i]-A[i+1]);
    }
    
    res+=min({(mi-1)*2,A[1]-1,A[n]-1});
    if (mx<x){
        res+=min({(x-mx)*2,x-A[n],x-A[1]});
    }
    cout<<res<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}