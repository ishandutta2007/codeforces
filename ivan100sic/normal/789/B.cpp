#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cerr.tie(nullptr);

        long long b, q, l, m, sol = 0;
        set<long long> a;

        cin >> b >> q >> l >> m;
        for (long long i=0; i<m; i++) {
                long long x;
                cin >> x;
                a.insert(x);
        }

        int steps = 0;
        while (steps < 1000) {
                steps++;
                if (abs(b) <= l) {
                        if (a.count(b) == 0) {
                                sol++;
                        }
                } else {
                        break;
                }
                b *= q;
        }

        if (sol > 100) {
                cout << "inf\n";
        } else {
                cout << sol << '\n'; 
        }

}