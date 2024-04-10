#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

int main()
{
    
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m + 1);
    vector<int> a(n);
    map<int, int> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++s[a[i]];
    }
    
    for (auto& it : s) {
        int x = it.first;
        for (int j = x; j <= m; j += x) {
            cnt[j] += it.second;
        }
    }
    
    int ans = 0, lcm = 1;
    for (int i = 1; i <= m; ++i) {
        if (cnt[i] > ans) {
            ans = cnt[i];
            lcm = i;
        }
    }
    
    cout << lcm << " ";
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (lcm % a[i] == 0) {
            pos.pb(i);
        }
    }
    cout << sz(pos) << "\n";
    for (int p : pos) {
        cout << p + 1 << " ";
    }
    cout << "\n";
    
}