#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool is_palindrome = true;
        for (int i = 0; i < n / 2; i++) {
            if (a[i] != a[n - 1 - i]) {
                is_palindrome = false;
            }
        }

        if (is_palindrome) {
            cout << "YES\n";
            continue;
        }

        int n_index = 0;
        while (true) {
            if (a[n_index] != a[n - 1 - n_index]) {
                break;
            }
            n_index++;
        }

        vector<int> a0;
        vector<int> a1;

        for (int i = 0; i < n; i++) {
            if (a[i] != a[n_index]) {
                a0.push_back(a[i]);
            }

            if (a[i] != a[n - 1 - n_index]) {
                a1.push_back(a[i]);
            }
        }


        bool is_palindrome_0 = true;
        for (int i = 0; i < a0.size() / 2; i++) {
            if (a0[i] != a0[a0.size() - 1 - i]) {
                is_palindrome_0 = false;
            }
        }

        if (is_palindrome_0) {
            cout << "YES\n";
            continue;
        }

        bool is_palindrome_1 = true;
        for (int i = 0; i < a1.size() / 2; i++) {
            if (a1[i] != a1[a1.size() - 1 - i]) {
                is_palindrome_1 = false;
            }
        }

        if (is_palindrome_1) {
            cout << "YES\n";
            continue;
        }

        cout << "NO\n";
    }
}