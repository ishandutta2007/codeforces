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
        LL d, m;
        cin >> d >> m;
        vector<LL> v;
        for(int i = 0; i <= 30; i += 1){
            LL L = 1LL << i, R = (L << 1) - 1;
            if(d < L) break;
            v.push_back(min(R, d) - L + 1);
        }
        LL ans = 1;
        for(LL& x : v) ans = ans * (x + 1) % m;
        cout << (ans + m - 1) % m << "\n";
    }
    return 0;
}