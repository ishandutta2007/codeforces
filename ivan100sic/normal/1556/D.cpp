// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int ask(string op, int x, int y) {
    cout << op << ' ' << x << ' ' << y << '\n' << flush;
    int z;
    cin >> z;
    return z;
}

void finish(int x) {
    cout << "finish " << x << '\n' << flush;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    int and_res[6];
    int or_res[6];
    for (int i=1; i<=2; i++) {
        for (int j=i+1; j<=3; j++) {
            and_res[i+j] = ask("and", i, j);
            or_res[i+j] = ask("or", i, j);
        }
    }

    for (int i=0; i<30; i++) {
        vector<int> bits(3);
        for (int j=0; j<3; j++) {
            int bit = -1;
            for (int k=0; k<3; k++) {
                if (k == j) continue;
                int and_val = (and_res[j+k+2] >> i) & 1;
                int or_val = (or_res[j+k+2] >> i) & 1;
                if (and_val == 1) {
                    bit = 1;
                    break;
                } else if (or_val == 0) {
                    bit = 0;
                    break;
                }
            }

            bits[j] = bit;
        }

        for (int j=0; j<3; j++) {
            if (bits[j] == -1) {
                bits[j] = 1 - bits[(j+1) % 3];
            }

            a[j] += bits[j] << i;
        }
    }

    for (int j=3; j<n; j++) {
        int and_res = ask("and", 1, j+1);
        int or_res = ask("or", 1, j+1);
        int y_val = 0;
        for (int i=0; i<30; i++) {
            int and_val = (and_res >> i) & 1;
            int or_val = (or_res >> i) & 1;
            int x_val = (a[0] >> i) & 1;
            if (and_val == 1) {
                y_val += 1 << i;
            } else if (or_val == 0) {
                // nothing
            } else {
                y_val += (1 - x_val) << i;
            }
        }
        a[j] = y_val;
    }

    sort(begin(a), end(a));
    finish(a[k-1]);
}