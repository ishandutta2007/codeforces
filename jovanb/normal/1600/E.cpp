#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 200000;

int a[N+5];

map <int, short> dp[N+5];

int n;

bool solve(int l, int r, int m1, int m2){
    if(l > r) return 0;
    int g = max(a[l-1], a[r+1]);
    if(dp[l][r]){
        if(dp[l][r] == 1) return 1;
        return 0;
    }
    bool postoji = 0;
    if(a[l] >= a[r] && a[l] > g){
        postoji |= (m1 - l + 1)%2;
    }
    if(a[l] < a[r] && a[l] > g){
        postoji |= 1 ^ solve(l+1, r, m1, m2);
    }
    if(a[r] >= a[l] && a[r] > g){
        postoji |= (m2 - (n-r))%2;
    }
    if(a[r] < a[l] && a[r] > g){
        postoji |= 1 ^ solve(l, r-1, m1, m2);
    }
    if(postoji) dp[l][r] = 1;
    else dp[l][r] = -1;
    return postoji;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) a[i] += 5;
    vector <int> v1, v2;
    for(int i=1; i<=n; i++){
        if(v1.empty() || v1.back() < a[i]) v1.push_back(a[i]);
        else break;
    }
    for(int i=n; i>=1; i--){
        if(v2.empty() || v2.back() < a[i]) v2.push_back(a[i]);
        else break;
    }
    cout << (solve(1, n, v1.size(), v2.size()) == 1 ? "Alice" : "Bob") << "\n";
    return 0;
}