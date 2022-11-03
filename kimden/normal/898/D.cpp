#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(auto& x: a){
        cin >> x;
    }
    sort(all(a));
    int nd = 0;
    int ans = 0;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i){
        v[nd++] = a[i];
        while(nd >= k && v[nd - 1] - v[nd - k] < m){
            ++ans;
            --nd;
        }
    }
    cout << ans << endl;



}