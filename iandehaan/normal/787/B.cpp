#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

void bad() {
    cout << "YES" << endl;
    exit(0);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        bool good = false;
        int k;
        cin >> k;
        bool seen[n+1];
        unordered_set<int> stupid;
        for (int j = 0; j <= n; j++) seen[j] = false;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if (stupid.find(x) != stupid.end()) continue;
            stupid.insert(x);
            if (seen[abs(x)]) good = true;
            seen[abs(x)] = true;
        }
        if (!good) bad();
    }
    cout << "NO" << endl;
}