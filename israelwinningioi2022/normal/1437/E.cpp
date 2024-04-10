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
const int INF = 1e18;


int ans = 0;
vi a;

void solve(int l, int r){
    map<int, int> dp;
    dp[a[l]] = 0;
    loop(i,l+1,r){
        //cout<<"I: "<<i<<" "<<a[i]<<" "<<endl;
        auto it = dp.upper_bound(a[i]);
        if (it==dp.begin()) continue;
        auto p = prev(it);
        //cout<<"HI: "<<p->x<<" "<<p->y<<endl;
        //if (dp.find(a[i])==dp.end()) dp[a[i]] = 
        chkmax(dp[a[i]], p->y + 1);
        int v = dp[a[i]];
        while(1){
            it = dp.upper_bound(a[i]);
            if (it!=dp.end() && it->y<=v) dp.erase(it);
            else break;
        } 
        //cout<<"DP: "<<dp[a[i]]<<endl;
    }
    //auto it = prev(dp.upper_bound(a[r]));
    int v = 0;
    for(auto p:dp) if(p.x<=a[r]) chkmax(v, p.y);
    //cout<<"IT: "<<it->x<<" "<<it->y<<endl;
    v = (r-l-1) - v;
    //cout<<"LR: "<<l<<" "<<r<<"  : "<<v<<endl;
    ans += v;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    a.resize(n+2); loop(i,1,n+1) cin>>a[i], a[i]-=i;
    vi b(k+2); loop(i,1,k+1) cin>>b[i];
    b[0] = 0, b[k+1] = n+1;
    a[0] = -INF, a[n+1] = INF;
    loop(i,0,k+1) if(a[b[i]]>a[b[i+1]]) return cout<<-1<<endl,0;
    //solve(0,b[0]-1);
    loop(i,0,k+1) solve(b[i],b[i+1]);
    //solve(b[k-1]+1, n-1);
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ e.cpp -o a & a
5 0
4 3 1 2 3



10 3
1 3 5 6 12 9 8 10 13 15
2 4 9



7 2
1 2 1 1 3 5 1
3 5


*/