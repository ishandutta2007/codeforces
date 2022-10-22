#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int minCount = 10000;
        for (int i = 0; i < 100; i++) {
            int aCopy = a;
            int count = i;
            if (b == 1 && i == 0) { b++; continue; }
            while (aCopy > 0) {
                aCopy /= b;
                count++;
            }
            minCount = min(minCount, count);


            b++;
        }

        cout << minCount << "\n";
    }
}