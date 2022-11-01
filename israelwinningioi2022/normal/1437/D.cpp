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
    vi a(n); loop(i,0,n) cin>>a[i];
    int layer = 1;
    int ans = 0;
    for(int i=1;i<n;){
        int prei = i;
        loop(x,0,layer) {
            while(i+1<n && a[i]<a[i+1]) i++;
            i++;
        }
        layer = i-prei;
        ans++;
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
g++ d.cpp -o a & a
1
7
1 5 7 2 3 4 6


3
4
1 4 3 2
2
1 2
3
1 2 3


*/