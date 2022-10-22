#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

vector<int> isprime[maxN];
vector<int> nd[maxN];
vector<int> vc[maxN];
bool chk[maxN];
int ans;

int dfs(int node){
    chk[node] = 0;
    int len = 1;
    for(int child : vc[node]){
        if(chk[child]){
            x = dfs(child);
            ans = max(ans, len + x - 1);
            len = max(len, x);
        }
    }
    return (len + 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(chk, 0, sizeof(chk));
    for1(i, 2, maxN - 1){
        if(isprime[i].size() == 0){
            for(int j = i; j < maxN; j += i) isprime[j].pb(i);
        }
    }
    for1(i, 1, n){
        cin >> x;
        for(int child : isprime[x]) nd[child].pb(i);
    }
    for1(i, 2, n){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    ans = 0;
    for1(i, 1, maxN - 1){
        if(nd[i].size()){
            for(int child : nd[i]) chk[child] = 1;
            for(int child : nd[i]) if(chk[child]){
                ans = max(ans, dfs(child) - 1);
            }
            // ans = max(ans, dfs(nd[i].back()));
        }
    }
    cout << ans << endl;
}