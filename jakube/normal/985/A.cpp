#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n/2);
    for (int i = 0; i < n/2; i++) {
        cin >> p[i];
        p[i]--;
    }
    sort(p.begin(), p.end());

    int black = 0;
    for (int i = 0; i < n/2; i++) {
        black += abs(2*i - p[i]);
    }
    int white = 0;
    for (int i = 0; i < n/2; i++) {
        white += abs(2*i + 1 - p[i]);
    }
    cout << min(black, white) << '\n';
    
}