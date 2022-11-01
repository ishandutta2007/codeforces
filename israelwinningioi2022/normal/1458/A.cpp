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
const int INF = 4e18;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vi a(n), b(m); 
    loop(i,0,n) cin>>a[i];
    loop(j,0,m) cin>>b[j];
    sort(all(a));
    loopr(i,1,n) a[i] -= a[i-1];
    int g = 0;
    loop(i,1,n) g = __gcd(g, a[i]);
    loop(i,0,m) cout<<__gcd(g, a[0] + b[i])<<" ";
    return 0;
}
/*
color a
cls
g++ a.cpp -o a & a
4 4
1 25 121 169
1 2 7 23


*/