#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using ull = unsigned long long;

vector<int> a[1001001];
const ll mod = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    int g, h;
    for(int i = 0; i < n; ++i){
        cin >> g;
        for(int j = 0; j < g; ++j){
            cin >> h;
            h--;
            a[h].push_back(i);
        }
    }
    sort(a, a + m);
    ll ans = 1;
    ll cur = 1;
    for(int i = 1; i < m; i++){
        if(a[i] == a[i - 1]){
            cur++;
            ans = (ans * cur) % mod;
        } else {
            cur = 1;
        }
    }
    cout << ans << endl;

    return 0;
}