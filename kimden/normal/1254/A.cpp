#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int t;
int r, c, k;
vector<string> s;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> r >> c >> k;
        int rice = 0;
        s.clear();
        s.resize(r);
        for (int i = 0; i < r; ++i) {
            cin >> s[i];
            for (int j = 0; j < c; ++j) {
                if (s[i][j] == 'R') {
                    ++rice;
                }
            }
        }
        vector<int> cnt;
        for (int i = 0; i < k; ++i) {
            cnt.push_back((rice + i) / k);
        }
        int mini = 0, maxi = r - 1;
        int minj = 0, maxj = c - 1;
        int ii = 0, jj = 0;
        int di = 0, dj = 1;
        int ptr = 0;
        int total = r * c;
        char ch = '0';
        while (1) {
            if (s[ii][jj] == 'R') {
                --cnt[ptr];
            }
            s[ii][jj] = ch;
            if (ptr < k - 1 && cnt[ptr] == 0) {
                ++ptr;
                if (ch == '9') {
                    ch = 'a';
                } else if (ch == 'z') {
                    ch = 'A';
                } else {
                    ++ch;
                }
            }
            ii += di;
            jj += dj;
            --total;
            if (total == 0) {
                break;
            }
            if (ii < mini || ii > maxi || jj < minj || jj > maxj) {
                ii -= di;
                jj -= dj;
                if (di == 0 && dj == 1) {
                    di = 1, dj = 0;
                    ++mini;
                } else if (di == 1 && dj == 0) {
                    di = 0, dj = -1;
                    --maxj;
                } else if (di == 0 && dj == -1) {
                    di = -1, dj = 0;
                    --maxi;
                } else {
                    di = 0, dj = 1;
                    ++minj;
                }
                ii += di;
                jj += dj;
            }
        }


        for (int i = 0; i < r; ++i) {
            cout << s[i] << "\n";
        }
    }


}