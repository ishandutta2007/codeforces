#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int l[m];
    for (int i = 0; i < m; i++) cin >> l[i];

    ll suffsums[m+1];
    suffsums[m] = 0;
    ll sm = 0;
    for (int i = m-1; i >= 0; i--) {
        sm += l[i];
        suffsums[i] = sm;
    }

    if (suffsums[0] < n) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> out;
    ll covereduntil = n-l[0];
    ll saveafter = n-1;
    bool donecovering = false;
    out.push_back(n-l[0]);
    for (int i = 1; i < m; i++) {
        //cout << "saveafter=" << saveafter << endl;
        ll latestposs = min((ll)n-1, suffsums[i+1]);
        ll earliestposs = saveafter-l[i];
        //cout << latestposs << ' ' << earliestposs << endl;
        if (latestposs > earliestposs) {
            out.push_back(earliestposs);
            if (earliestposs < 0 || earliestposs >= n) {
                cout << -1 << endl;
                return 0;
            }
            saveafter = earliestposs + l[i] -1;
            continue;
        }

        out.push_back(latestposs);
        saveafter = latestposs + l[i] - 1;
        if (latestposs == 0) donecovering = true;
    }

    for (int blah : out) {
        cout << blah+1 << ' ';
    }
    cout << endl;
}