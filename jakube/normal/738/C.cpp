#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long n, k, s, t;
    cin >> n >> k >> s >> t;
    
    vector<pair<long long, long long>> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx].first >> v[idx].second;
    
    vector<long long> g(k);
    for (int idx = 0; idx < k;  idx++)
        cin >> g[idx];
    sort(g.begin(), g.end());
    g.push_back(s);
    
    long long l = 0;
    long long r = numeric_limits<int>::max();
    
    while (l + 1 < r) {
        long long G = (l + r) / 2;

        long long last = 0;
        long long time = 0;
        for (int next : g) {
            if ((next - last) * 2 <= G) {
                time += next - last;
                last = next;
            } else if (next - last <= G) {
                long long tmp = G - (next - last);
                time += 2*(next - last) - tmp;
                last = next;
            } else {
                break;
            }
        }

        if (last == s && time <= t) {
            // cout << "G=" << G << ": t = " <<  time << endl;
            r = G;
        }
        else  {
            // cout << "G=" << G << ": t = " <<  time << endl;
            l = G;
        }
    }

    if (r == numeric_limits<int>::max()) {
        cout << -1 << endl;
        return 0;
    }

    long long m = numeric_limits<int>::max();
    for (auto p : v) {
        if (p.second >= r) {
            m = min(m, p.first);
        }
    }

    if (m == numeric_limits<int>::max())
        cout << -1 << endl;
    else 
        cout << m << endl;



    return 0;
}