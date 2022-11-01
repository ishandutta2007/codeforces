#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 998244353;


int solve(){
    int n,k; cin>>n>>k;
    vi a(n), b(k); 
    loop(i,0,n) cin>>a[i], a[i]--;
    loop(i,0,k) cin>>b[i], b[i]--;
    vi pos(n); loop(i,0,n) pos[a[i]] = i;
    vb check(n); 
    loop(i,0,k) check[pos[b[i]]] = 1;
    int ans = 1;
    loop(i,0,k){
        int p = pos[b[i]];
        check[p] = 0;
        int mult = 0;
        if (p && !check[p-1]) mult++;
        if (p+1<n && !check[p+1]) mult++;
        ans = ans * mult % MOD;
    }
    cout<<ans<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ b.cpp -o a & a
3
5 3
1 2 3 4 5
3 2 5
4 3
4 3 2 1
4 3 1
7 4
1 4 7 3 6 2 5
3 2 4 5


*/