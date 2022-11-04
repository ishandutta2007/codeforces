#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi p(n);
        int root;
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            --p[i];
            if(i == p[i]) {
                root = i;
            }
        }
        vi ans(n, 0);
        vi dist(n, -1);
        dist[root] = 0;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
        }
        if(a[0] != root) {
            cout << "-1\n";
            continue;
        }
        int now = 1;
        bool ok = true;
        for(int i = 1; i < n; i++) {
            int v = a[i];
            if(dist[p[v]] == -1) {
                ok = false;
                break;
            }
            dist[v] = now;
            ++now;
            ans[v] = dist[v] - dist[p[v]];
        }
        if(!ok) {
            cout << "-1\n";
            continue;
        }
        for(const auto& el : ans) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}