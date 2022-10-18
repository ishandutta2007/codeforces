#include <bits/stdc++.h>
#define int long long
#define fs first
#define sc second
#define mp make_pair
#define vc vector
#define pr pair
#define pb push_back
#define ld long double
#define all(v) v.begin(), v.end()
#define len(v) (int)v.size()
#define endl "\n"
#define in cin
#define out cout

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    map<int, int> kek;
    int n;
    in >> n;
    vc<int> rast(n + 1);
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 0; i < n - 1; i++){
        int x;
        in >> x;
        x--;
        dp[i + 1] = dp[x] + 1;
    }
    for (int i = 0; i < n; i++){
        rast[dp[i]]++;
    }
    int ans = 0;
    for (auto v : rast){
        ans += v % 2;
    }
    out << ans;
}