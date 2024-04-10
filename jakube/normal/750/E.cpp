#include <bits/stdc++.h>
using namespace std;

#define L 200001

struct Matrix {
    // minimal cost to go from state i to state j when feeding a string of chars
    int d11 = 0;
    int d12 = L;
    int d13 = L;
    int d14 = L;
    int d15 = L;
    int d22 = 0;
    int d23 = L;
    int d24 = L;
    int d25 = L;
    int d33 = 0;
    int d34 = L;
    int d35 = L;
    int d44 = 0;
    int d45 = L;
    int d55 = 0;
};

Matrix combine(Matrix &A, Matrix &B) {
    Matrix res;
    res.d11 = min(L, A.d11 + B.d11);
    res.d12 = min(L, min(A.d11 + B.d12, A.d12 + B.d22));
    res.d13 = min(L, min(A.d11 + B.d13, min(A.d12 + B.d23, A.d13 + B.d33)));
    res.d14 = min(L, min(A.d11 + B.d14, min(A.d12 + B.d24, min(A.d13 + B.d34, A.d14 + B.d44))));
    res.d15 = min(L, min(A.d11 + B.d15, min(A.d12 + B.d25, min(A.d13 + B.d35, min(A.d14 + B.d45, A.d15 + B.d55)))));

    res.d22 = min(L, A.d22 + B.d22);
    res.d23 = min(L, min(A.d22 + B.d23, A.d23 + B.d33));
    res.d24 = min(L, min(A.d22 + B.d24, min(A.d23 + B.d34, A.d24 + B.d44)));
    res.d25 = min(L, min(A.d22 + B.d25, min(A.d23 + B.d35, min(A.d24 + B.d45, A.d25 + B.d55))));

    res.d33 = min(L, A.d33 + B.d33);
    res.d34 = min(L, min(A.d33 + B.d34, A.d34 + B.d44));
    res.d35 = min(L, min(A.d33 + B.d35, min(A.d34 + B.d45, A.d35 + B.d55)));

    res.d44 = min(L, A.d44 + B.d44);
    res.d45 = min(L, min(A.d44 + B.d45, A.d45 + B.d55));

    res.d55 = min(L, A.d55 + B.d55);

    return res;
}

class SegementTree {
    public:
        vector<Matrix> data;
        int n;

        SegementTree(string s) {
            n = s.size();
            data.assign(2*n, {});

            Matrix ms[10];
            ms[2].d11 = 1;
            ms[2].d12 = 0;

            ms[0].d22 = 1;
            ms[0].d23 = 0;

            ms[1].d33 = 1;
            ms[1].d34 = 0;

            ms[6].d44 = 1;
            ms[6].d55 = 1;

            ms[7].d44 = 1;
            ms[7].d45 = 0;

            for (int i = n; i < 2*n; i++) {
                data[i] = ms[s[i - n] - '0'];
            }

            for (int i = n-1; i > 0; i--) {
                data[i] = combine(data[i<<1], data[i<<1|1]);
            }
        }

        int range(int left, int right) {
            left += n;
            right += n;
            Matrix res_l, res_r;

            while (left < right) {
                if (left & 1) res_l = combine(res_l, data[left++]);
                if (right & 1) res_r = combine(data[--right], res_r);
                left >>= 1;
                right >>= 1;
            }

            Matrix res = combine(res_l, res_r);
            if (res.d15 > 2e5)
                return -1;
            return res.d15;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;
    SegementTree st(s);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << st.range(l-1, r) << '\n';
    }
    cout << flush;

    return 0;
}