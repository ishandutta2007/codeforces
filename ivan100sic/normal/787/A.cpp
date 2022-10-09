
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

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int i=0; i<=1000000; i++) {
                if (i >= b && (i-b) % a == 0
                && i >= d && (i-d) % c == 0)
                {
                        cout << i;
                        return 0;
                }
        }
        cout << -1;
}