#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, s;
    cin >> n >> s;
    
    int best = -1;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        int cost = x*100 + y;
        if (cost <= s*100) {
            best = max(best, (100 - (cost%100))%100);
            cost += x*100 + y;
        }
    }

    cout << best << endl;


    return 0;
}