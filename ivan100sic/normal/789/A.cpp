#include <bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cerr.tie(nullptr);

        int n, k, sol=0;
        cin >> n >> k;

        while (n--) {
                int x;
                cin >> x;
                sol += (x + k - 1) / k;
        }
        cout << (sol + 1) / 2;
}