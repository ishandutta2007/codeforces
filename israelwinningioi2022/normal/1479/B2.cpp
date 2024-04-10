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
const int INF = 4e18, MOD = 1e9+7;


int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i], a[i]--;
    vi last(n, -1), next(n, n);
    loop(i,0,n){
        if (last[a[i]]!=-1) next[last[a[i]]] = i;
        last[a[i]] = i;
    }
    int a1 = -1, n1 = n;
    int a2 = -1, n2 = n;
    int ans = 0;
    loop(i,0,n){
        if (a1==a[i] && a2!=a[i]) a1 = a[i], n1 = next[i];
        else if (a1!=a[i] && a2==a[i]) a2 = a[i], n2 = next[i];
        else{
            if (a1!=a[i]) ans++;
            if (n1 < n2) a2 = a[i], n2 = next[i];
            else a1 = a[i], n1 = next[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ b2.cpp -o a & a
6
1 2 3 1 2 2


*/