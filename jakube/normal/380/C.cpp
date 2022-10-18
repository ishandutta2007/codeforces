//     already / offene / geschlossen
// ())(      1, 1, 1
// )(()      1, 1, 1
// ())()(()  3, 1, 1
//
//
// ))()      1, 0, 2
// )))(      0, 1, 3
// ))())))(  1, 1, 5
//
// ()))      1, 0, 2
// ()))      1, 0, 2
// ()))()))  2, 0, 4

#include <bits/stdc++.h>
using namespace std;

struct State {
    int p, o, c;
};

class SegmentTree {
    public:
        vector<State> data;
        int n;
        string s;

        SegmentTree(string s) : n(s.size()), s(s) {
            data.assign(2*n, {0, 0, 0});
            build();
        }

        State combine(State a, State b) {
            State result;
            int m = min(a.o, b.c);
            result.p = a.p + b.p + m;
            result.o = a.o + b.o - m;
            result.c = a.c + b.c - m;
            return result;
        }

        void build() {
            for (int i = n; i < 2*n; i++) {
                if (s[i-n] == '(')
                    data[i].o++;
                else
                    data[i].c++;
            }

            for (int i = n-1; i > 0; i--) {
                data[i] = combine(data[i<<1], data[i<<1|1]);
            } 
        }

        int range(int left, int right) {
            left += n;
            right += n;

            State res_l{0, 0, 0}, res_r{0, 0, 0};
            while (left < right) {
                if (left & 1)
                    res_l = combine(res_l, data[left++]);
                if (right & 1)
                    res_r = combine(data[--right], res_r);
                left >>= 1;
                right >>= 1;
            }

            State res = combine(res_l, res_r);
            return res.p;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string s;
    cin >> s;
    SegmentTree st(s);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << 2*st.range(l-1, r) << '\n';
    }
    cout << flush;

    return 0;
}