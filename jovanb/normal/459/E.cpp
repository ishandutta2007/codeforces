#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector <pair <int, int>> vec[100005];
int dp[300005];
int sta[300005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    int a, b, x;
    for(int i=1; i<=m; i++){
        cin >> a >> b >> x;
        vec[x].push_back({a,b});
    }
    for(int i=1; i<=100000; i++){
        for(auto c : vec[i]){
            b = c.second;
            sta[b] = 0;
        }
        for(auto c : vec[i]){
            a = c.first;
            b = c.second;
            sta[b] = max(sta[b], dp[a]+1);
        }
        for(auto c : vec[i]){
            b = c.second;
            dp[b] = max(dp[b], sta[b]);
        }
    }
    int maxi=0;
    for(int i=1; i<=n; i++){
        maxi = max(maxi, dp[i]);
    }
    cout << maxi;
    return 0;
}