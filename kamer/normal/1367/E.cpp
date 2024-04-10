#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    if (a == b) return a;
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> charCounts(30, 0);
        string s;
        cin >> s;
        for (auto c : s) charCounts[c - 'a']++;
        int maxN = -1;
        for (int i = 1; i <= n; i++) {
            int orbit = i / gcd(i, k);
            int numOrbits = gcd(i, k);
            vector<int> copyCharCounts(charCounts);
            int countOrbits = 0;
            for (int j = 0; j < 30; j++) {
                while (copyCharCounts[j] >= orbit) {
                    copyCharCounts[j] -= orbit;
                    countOrbits++;
                }
            }
            if (countOrbits >= numOrbits) maxN = i;
        }
        cout << maxN << "\n";
    }
}