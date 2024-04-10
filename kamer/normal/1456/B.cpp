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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    if (n <= 2) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i < n - 1; i++) {
        if ((a[i] ^ a[i + 1]) < a[i - 1]) {
            cout << "1\n";
            return 0;
        }
    }

    int best_moves = n + 10;
    for (int i = 1; i < n; i++) {
        int right_xor = 0;
        for (int j = i; j < n; j++) {
            right_xor = right_xor ^ a[j];
            int left_xor = 0;
            for (int k = i - 1; k >= 0; k--) {
                left_xor = left_xor ^ a[k];
                if (left_xor > right_xor) {
                    best_moves = min(best_moves, j - k - 1);
                    break;
                }
            }
        }
    }

    if (best_moves == n + 10) {
        cout << "-1\n";
    } else {
        cout << best_moves << "\n";
    }
}