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

        int n, sol=0;
        cin >> n; 
        set<int> s;

        for (int i=0; i<2*n; i++) {
                int x;
                cin >> x;
                if (s.count(x) == 1) {
                        s.erase(x);
                } else {
                        s.insert(x);
                }
                sol = max(sol, (int)s.size());
        }
        cout << sol;
}