#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector <int> graf[300005];
int dp[300005];
int h[300005];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    stack <int> lower, higher;
    for(int i=1; i<=n; i++){
        cin >> h[i];
        while(!lower.empty() && h[lower.top()] < h[i]) lower.pop();
        if(!lower.empty()) graf[i].push_back(lower.top());
        lower.push(i);
        while(!higher.empty() && h[higher.top()] > h[i]) higher.pop();
        if(!higher.empty()) graf[i].push_back(higher.top());
        higher.push(i);
    }
    while(!lower.empty()) lower.pop();
    while(!higher.empty()) higher.pop();
    for(int i=n; i>=1; i--){
        while(!lower.empty() && h[lower.top()] < h[i]) lower.pop();
        if(!lower.empty()) graf[lower.top()].push_back(i);
        lower.push(i);
        while(!higher.empty() && h[higher.top()] > h[i]) higher.pop();
        if(!higher.empty()) graf[higher.top()].push_back(i);
        higher.push(i);
    }
    for(int i=2; i<=n; i++) dp[i] = n+5;
    for(int i=2; i<=n; i++){
        //dp[i] = dp[i-1] + 1;
        for(auto c : graf[i]) dp[i] = min(dp[i], dp[c] + 1);
    }
    cout << dp[n];
    return 0;
}