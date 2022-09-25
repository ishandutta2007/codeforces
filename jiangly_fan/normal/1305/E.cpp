#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 5000;
int s[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i += 1) s[i] = (i & 1) ? (i / 2) * (i / 2) : (i / 2) * (i / 2 - 1);
    if(s[n] < m){
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= n; i += 1) if(s[i] >= m){
        for(int j = 1; j < i; j += 1) cout << j << " ";
        m -= s[i - 1];
        n -= i;
        map<int, int> mp;
        for(int j = 1; j < i; j += 1)
            for(int k = j + 1; k < i; k += 1)
                mp[j + k] += 1;
        mp[i + i - 1] = 0;
        int x = 0;
        for(auto p : mp) if(p.second == m) x = p.first;
        assert(x);
        cout << x << " ";
        break;
    }
    for(int i = n - 1; i >= 0; i -= 1) cout << 1000000000 - 5000 * i << " ";
    return 0;
}