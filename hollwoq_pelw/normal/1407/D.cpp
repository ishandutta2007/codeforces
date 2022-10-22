#include <bits/stdc++.h>
using namespace std;

int n; bool eq;
vector<int> h, dp, lw, hi;

int main(){
    cin >> n;
    h.resize(n);
    dp.assign(n, 1e9);
    dp[0] = 0;
    for (auto &v : h) cin >> v;
    
    lw.push_back(0);
    hi.push_back(0);
    
    for (int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + 1;
        eq = true;
        while(lw.size() && h[lw.back()] <= h[i]){
            if (h[lw.back()] == h[i]) eq = false;
            dp[i] = min(dp[i], dp[lw.back()] + 1);
            lw.pop_back();
        }
        if (lw.size() && eq){
            dp[i] = min(dp[i], dp[lw.back()] + 1);
        }
        eq = true;
        while(hi.size() && h[hi.back()] >= h[i]){
            if (h[hi.back()] == h[i]) eq = false;
            dp[i] = min(dp[i], dp[hi.back()] + 1);
            hi.pop_back();
        }
        if (hi.size() && eq){
            dp[i] = min(dp[i], dp[hi.back()] + 1);
        }
        
        lw.push_back(i);
        hi.push_back(i);
    }
    cout << dp[n - 1];
}