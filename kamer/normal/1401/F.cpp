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

int find_orig(int y, int k, vector<int>& rev, int n) {
    
    int x = y / (1 << k);
    for (int i = n; i > k; i--) {
        if (rev[i]) {
            int s = 1 << (i - k);
            x = (x / s) * s + s - x % s - 1;
        }
    }
    // cout << y << " " << k << " " << x << " " << n << endl;
    return x * (1 << k);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, q;
    cin >> n >> q;
    int N = (1 << n);
    vector<vector<ll>> seg(N + 1, vector<ll>());
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        seg[i].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < N; j += (1 << i)) {
            seg[j].push_back(seg[j][i - 1] + seg[j + (1 << (i - 1))][i - 1]);
        }
    }

   //  cout << "OK" << endl;

    vector<int> rev(n + 1, 0);
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        // cout << op << " T" << endl;
        if (op == 1) {
            int x, k;
            cin >> x >> k;
            x--;
            int u = find_orig(x, 0, rev, n);
            int diff = k - seg[u][0];
            for (int j = 0; j <= n; j++) {
                int u = find_orig(x, j, rev, n);
                seg[u][j] += diff;
            }
        } if (op == 2) {
            int k;
            cin >> k;
            rev[k] = 1- rev[k];
        } if (op == 3) {
            int k;
            cin >> k;
            rev[k] = 1 - rev[k];
            rev[k + 1] = 1 - rev[k + 1];
        } if (op == 4) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            ll sum = 0;
            while (l <= r) {
                int pow = 0;
                while ((l % (1 << (pow + 1)) == 0) && ((l + (1 << (pow + 1))) <= r + 1)) {
                    pow += 1;
                }
                int u = find_orig(l, pow, rev, n);
                sum += (ll) seg[u][pow];
                l += (1 << pow);
            }
            cout << sum << "\n";
        }
    }
}