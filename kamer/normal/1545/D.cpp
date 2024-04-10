#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> find_coeffs(ll v1, ll v2, ll v3) {
    vector<ll> res(3, -1);
    res[0] = v1;
    v2 -= v1;
    v3 -= v1;
    res[1] = (4 * v2 - v3) / 2;
    res[2] = (v3 - 2 * v2) / 2;
    return res;
}

ll square_sum(vector<ll>& v) {
    ll res = 0;
    for (auto el : v) {
        res = res + el * el;
    }
    return res;
}


int main(void) {
    int m, k;
    cin >> m >> k;
    vector<vector<ll>> pos(k, vector<ll>(m, 0));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pos[i][j];
        }
    }

    vector<ll> sums(k, 0);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            sums[i] += pos[i][j];
        }
    }

    ll diff = sums[1] - sums[0];
    int wrong_pos = -1;
    ll expected_sum;
    if ((sums[2] - sums[1] != diff) && (sums[3] - sums[2] != diff)) {
        diff = sums[k - 1] - sums[k - 2];
        for (int i = k - 2; i >= 1; i--) {
            if (sums[i] - sums[i - 1] != diff) {
                wrong_pos = i - 1;
                expected_sum = sums[i] - diff;
                break;
            }
        }
    } else {
        for (int i = 2; i < k; i++) {
            if (sums[i] - sums[i - 1] != diff) {
                wrong_pos = i;
                expected_sum = sums[i - 1] + diff;
                break;
            }
        }
    }

    ll v1, v2, v3;
    ll A, B, C;
    ll expected_square_sum;
    if (wrong_pos >= 3) {
        v1 = square_sum(pos[wrong_pos - 3]);
        v2 = square_sum(pos[wrong_pos - 2]);
        v3 = square_sum(pos[wrong_pos - 1]);
        auto coeffs = find_coeffs(v1, v2, v3);
        A = coeffs[0], B = coeffs[1], C = coeffs[2];
        expected_square_sum = A + 3 * B + 9 * C;
    } else {
        v1 = square_sum(pos[wrong_pos + 1]);
        v2 = square_sum(pos[wrong_pos + 2]);
        v3 = square_sum(pos[wrong_pos + 3]);
        auto coeffs = find_coeffs(v1, v2, v3);
        expected_square_sum = coeffs[0] - coeffs[1] + coeffs[2];
    }

    ll actual_sum = sums[wrong_pos];
    ll actual_square_sum = square_sum(pos[wrong_pos]);
    for (int i = 0; i < m; i++) {
        ll tentative_correct = pos[wrong_pos][i] + expected_sum - actual_sum;
        if (tentative_correct * tentative_correct - pos[wrong_pos][i] * pos[wrong_pos][i] ==
            expected_square_sum - actual_square_sum) {
            cout << wrong_pos << " " << tentative_correct << "\n";
            return 0;
        }
    }

    return 1;
}