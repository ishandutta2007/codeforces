
#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cerr.tie(nullptr);

        int n, s=0, bn=0;
        cin >> n; 
        while (n--) {
                int x;
                cin >> x;
                s = (s + x) % 2;
                bn += x % 2;
        }
        if (s % 2 == 1) {
                cout << "First\n";
                return 0;
        } else {
                if (bn == 0) {
                        cout << "Second\n";
                } else {
                        cout << "First\n";
                }
        }
}