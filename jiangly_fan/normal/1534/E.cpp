#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> c(n + 1);
    for(int p = 1; p <= 500; p += 1){
        if(p * k < n or (p * k - n) % 2 == 1) continue;
        int x = ((p * k - n) / 2 + n - 1) / n;
        if(x * 2 + 1 > p) continue;
        for(int i = 1; i <= n; i += 1) c[i] = 1;
        int y = (p * k - n) / 2;
        for(int i = 1; y; i = i == n ? 1 : i + 1, y -= 1) c[i] += 2;
        while(true){
            vector<int> p(n + 1);
            for(int i = 1; i <= n; i += 1) p[i] = i;
            sort(p.begin() + 1, p.end(), [&](const int& x, const int& y){
                return c[x] > c[y];
            });
            if(c[p[1]] == 0) break;
            cout << "?";
            for(int i = 1; i <= k; i += 1){
                cout << " " << p[i];
                c[p[i]] -= 1;
            }
            cout << endl;
            int pans = 0;
            cin >> pans;
            ans ^= pans;
        }
        cout << "! " << ans << endl;
        return 0;
    }
    cout << "-1";
    return 0;
}