/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

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

int dp[2][105];
int cop[105];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[0][0] = 0;
    dp[1][0] = -1;
    for1(i, 1, 100){
        set<int> st;
        for1(j, 0, i - 1) st.insert((dp[0][j] ^ dp[0][i - 1 - j]));
        for1(j, 1, i - 2) st.insert((dp[1][j] ^ dp[1][i - 1 - j]));
        for1(j, 0, maxN){
            if(st.find(j) == st.end()){
                dp[0][i] = j; break;
            }
        }
        st.clear();
        for1(j, 1, i - 1) st.insert(dp[1][j] ^ dp[0][i - 1 - j]);
        for1(j, 0, maxN){
            if(st.find(j) == st.end()){
                dp[1][i] = j; break;
            }
        }
    }
    for1(i, 2, 100){
        set<int> st;
        for1(j, 0, i - 1) st.insert((dp[0][j] ^ cop[i - 1 - j]));
        for1(j, 1, i - 1) st.insert((dp[1][j] ^ cop[i - 1 - j]));
        for1(j, 0, maxN){
            if(st.find(j) == st.end()){
                cop[i] = j; break;
            }
        }
    }
    cin >> n; int o; cin >> o;
    if(o == 0){
        set<int> st;
        for1(i, 0, n - 1) st.insert(i ^ (n - 1 - i));
        if(st.find(0) == st.end()) cout << "LOSE\n";
        else cout << "WIN\n";
        return 0;
    }
    memset(a, 0, sizeof(a));
    while(o--){
        cin >> x >> y;
        a[x] = y;
    }
    int plc = 0;
    int ans = 0;
    for1(i, 1, n){
        if(a[i]){
            if(!plc) ans ^= (i - 1);
            else{
                ans ^= dp[(a[plc] != a[i])][i - plc - 1];
            }
            plc = i;
        }
    }
    ans ^= (n - plc);
    if(ans) cout << "WIN";
    else cout << "LOSE";
    cout << endl;
}