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


int solve(){
    int n; cin>>n;
    vi a(n);  loop(i,0,n) cin>>a[i];
    int m = INF, m2 = 0;
    bool ok = 1;
    loop(i,0,n){
        a[i]-=m2;
        if (a[i]<0) ok = 0;
        chkmin(m, a[i]);
        a[i]-=m;
        if (a[i]){
            a[i]+=m2;
            chkmax(m2, a[i]);
            a[i]-=m2;
        }
    }
    loop(i,0,n) if(a[i]) ok = 0;
    if (ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
g++ a.cpp -o a & a
4
3
1 2 1
5
11 7 9 6 8
5
1 3 1 3 1
4
5 2 1 10


*/