#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, s, k;
        cin >> n >> s >> k;
        unordered_set<int> closed;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            closed.insert(x);
        }
        for (int steps = 0; steps <= 1e9; steps++) {
            if (s+steps <= n && closed.find(s+steps) == closed.end()) {
                cout << steps << endl;
                break;
            }
            if (s-steps > 0 && closed.find(s-steps) == closed.end()) {
                cout << steps << endl;
                break;
            }
        }
    }
}