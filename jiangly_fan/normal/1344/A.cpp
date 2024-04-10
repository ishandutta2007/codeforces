#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<LL> a(n);
        for(LL& x : a) cin >> x;
        vector<LL> p(n);
        for(int i = 0; i < n; i += 1)
            p[i] = (a[i] % n + i + n) % n;
        sort(p.begin(), p.end());
        int ok = 1;
        for(int i = 0; i < n; i += 1) ok &= p[i] == i;
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}