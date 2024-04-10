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
const int MAX = 6e5 + 1;
vi f(MAX,1), invf(MAX);
int pp(int b, int p){
    if (p==0) return 1;
    int v = pp(b*b%MOD, p/2);
    return v * (p%2?b:1) % MOD;
}
int choose(int a, int b){
    if (b>a) return 0;
    int v = f[a] * invf[b] %MOD;
    return v * invf[a-b] % MOD;
}
void add(int &a, int b){
    a = (a+b)%MOD;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    loop(i,1,MAX) f[i] = f[i-1] * i % MOD;
    loop(i,0,MAX) invf[i] = pp(f[i], MOD - 2);
    int ans = 0;
    vii a;
    loop(i,0,n){
        int x,y; cin>>x>>y;
        a.pb({x,0});
        a.pb({y,1});
    }
    sort(all(a));
    int cnt = 0;
    for(auto p:a){
        if (p.y){
            cnt--;
        }
        else{
            int v = choose(cnt, k-1);
            //cout<<"CNT: "<<cnt<<" "<<k-1<<" "<<v<<endl;
            add(ans, v);
            cnt++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
7 3
1 7
3 8
4 5
6 7
1 3
5 10
8 9

*/