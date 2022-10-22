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

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        vector<ll> a(n - 1);
        bool found_greater = false;
        for (int i = 0; i < n - 1; i++) {
            a[i] = A[i + 1] - A[i];
            if (a[i] < 0) a[i] = -a[i];
            if (a[i] > 1) found_greater = true;
        }

        if (!found_greater) {
            cout << "1\n";
            continue;
        }

        n--;

        int log_n = 0;
        vector<ll> powers(20, 1);
        for (int i = 1; i < 20; i++) powers[i] = 2 * powers[i - 1];
        
        while (powers[log_n] <= n) log_n++;
        log_n--;

        vector<vector<ll>> gcds(n, vector<ll>(log_n + 1, -1));
        for (int i = 0; i < n; i++) gcds[i][0] = a[i];
        for (int j = 1; j <= log_n; j++) {
            for (int i = 0; i <= n - powers[j]; i++) {
                gcds[i][j] = gcd(gcds[i][j - 1], gcds[i + powers[j - 1]][j - 1]);
            }
        }

        /*
        for (int j = 0; j <= log_n; j++) {
            for (int i = 0; i <= n - powers[j]; i++) {
                cout << gcds[i][j] << " ";
            }
            cout << "\n";
        }
        */

        int l = 1, r = n + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            // cout << "T " << mid << "\n";
            vector<int> decompose;
            for (int i = 0; i < 20; i++) {
                if (powers[i] & mid) decompose.push_back(i);
            }
            // cout << "D ";
            // for (auto d : decompose) cout << d << " " ;
            // cout << "\n";
            bool found_clique = false;
            int k = decompose.size();
            for (int i = 0; i <= n - mid; i++) {
                int i_copy = i;
                ll current_gcd = gcds[i_copy][decompose[0]];
                i_copy += powers[decompose[0]];
                for (int j = 1; j < k; j++) {
                    if (current_gcd == 1) break;
                    current_gcd = gcd(current_gcd, gcds[i_copy][decompose[j]]);
                    i_copy += powers[decompose[j]];
                }
                if (current_gcd > 1) {
                    found_clique = true;
                    break;
                }
            }

            if (found_clique) l = mid;
            else r = mid;
        }

        cout << l + 1 << "\n";

    }
}