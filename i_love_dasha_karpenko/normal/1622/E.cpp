#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
//#define int ll
#define all(var) var.begin(),var.end()
#define mp make_pair
#define gi(x) int(x-'0')
#define gb(mask,bit) (((1<<bit)&mask)>>bit)
const int N = 10+2;
const int M = 1e4+7;
int EXP[N],pass[M];
bool can[N][M];
int ans[M],st[M];
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;++i)
        cin>>EXP[i];
    for(int i = 0;i<n;++i){
        for(int j = 1;j<=m;++j) {
            char ch; cin>>ch;
            can[i][j] = ch=='1';
        }
    }
    int masksz = 1<<n;
    ll res = -1e18;
    for(int mask = 0;mask<masksz;++mask){

        for(int i = 1;i<=m;++i)
            pass[i] = 0;
        ll r = 0;
        for(int bit = 0;bit<n;++bit){
            int add = gb(mask,bit)?1:-1;
            r += add*EXP[bit];
            for(int j = 1;j<=m;++j){
                pass[j]-=add*can[bit][j];
            }
        }
        vector<pair<int,int> > V;
        for(int i = 1;i<=m;++i)
            V.push_back({pass[i],i});
        sort(all(V));
        int ptr = 1;
        for(auto [val,pos]:V){
            r+=ll(val)*ptr;
            st[pos] = ptr++;
        }
        if (res<r){
            res = r;
            for(int i = 1;i<=m;++i)
                ans[i] = st[i];
        }
    }
    for(int i = 1;i<=m;++i)
        cout<<ans[i]<<' ';
    cout<<endl;
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}