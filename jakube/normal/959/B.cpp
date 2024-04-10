#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;
    cin >> n >> k >> m;
    vector<string> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<string, int> map;
    for (int i = 0; i < k; i++) {
        int xx;
        cin >> xx;
        vector<int> x(xx);
        int best = 0;
        for (int i = 0; i < xx; i++) {
            cin >> x[i];
            x[i]--;
            if (a[x[best]] > a[x[i]])
                best = i;
        }

        for (int k : x)
            map[w[k]] = a[x[best]];
    }

    long long total = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        total += map[s];
    }
    cout << total << endl;
}