#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    if (k < 500) {
        int wins = 0;
        while (wins < k) {
            if (v[0] > v[1]) {
                wins++;
                v.push_back(v[1]);
                v.erase(v.begin() + 1);
            } else {
                wins = 1;
                v.push_back(v[0]);
                v.erase(v.begin());
            }
        }
        cout << v[0] << endl;
    } else {
        cout << *max_element(v.begin(), v.end()) << endl;
    }
}