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

        int n, m;
        cin >> n >> m;
        while (m--) {
                int c;
                bool bad = true;
                cin >> c;
                set<int> s;
                while (c--) {
                        int x;
                        cin >> x;
                        if (s.count(-x)) {
                                bad = false;
                        }
                        s.insert(x);
                }
                if (bad) {
                        cout << "YES\n";
                        return 0;
                } 
        }
        cout << "NO\n";
}