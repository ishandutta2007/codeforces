#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> A(n); 
        vector<pair<int, int>> V(n);
        unordered_set<int> Chosen;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            V[i] = make_pair(-(A[i] - (n - i - 1)), i);
        }

        sort(V.begin(), V.end());

        for (int i = 0; i < k; ++i) Chosen.insert(V[i].second);

        long long sm = 0;
        int amt_left = k;

        for (int i = 0; i < n; ++i) {
            if (Chosen.count(i)) {
                amt_left -= 1;
                sm += (n - i - 1) - amt_left;
            } else {
                sm += A[i];
            }
        }

        cout << sm << endl;
    }
    return 0;
}