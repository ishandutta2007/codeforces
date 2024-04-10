#include <bits/stdc++.h>
using namespace std;


constexpr int Wmax = 2001;
std::vector<std::bitset<Wmax>> gauss_jordan(int W, std::vector<std::bitset<Wmax>> mtr) {
    int H = mtr.size(), c = 0;
    for (int h = 0; h < H; h++, c++) {
        if (c == W) break;
        int piv = -1;
        for (int j = h; j < H; j++)
            if (mtr[j][c]) {
                piv = j;
                break;
            }
        if (piv == -1) {
            h--;
            continue;
        }
        std::swap(mtr[piv], mtr[h]);
        for (int hh = 0; hh < H; hh++) {
            if (hh != h and mtr[hh][c]) mtr[hh] ^= mtr[h];
        }
    }
    return mtr;
}


// Solve Ax = b on F_2
// - retval: {true, one of the solutions, {freedoms}} (if solution exists)
//           {false, {}, {}} (otherwise)
std::tuple<bool, std::bitset<Wmax>, std::vector<std::bitset<Wmax>>> system_of_linear_equations(std::vector<std::bitset<Wmax>> A, std::bitset<Wmax> b, int W) {
    int H = A.size();
    assert(W + 1 <= Wmax);
    assert(H <= Wmax);

    std::vector<std::bitset<Wmax>> M = A;
    for (int i = 0; i < H; i++) M[i][W] = b[i];
    M = gauss_jordan(W + 1, M);
    std::vector<int> ss(W, -1);
    for (int i = 0; i < H; i++) {
        int j = M[i]._Find_first();
        if (j == W) { return std::make_tuple(false, std::bitset<Wmax>(), std::vector<std::bitset<Wmax>>()); }
        if (j < W) ss[j] = i;
    }
    std::bitset<Wmax> x;
    std::vector<std::bitset<Wmax>> D;
    for (int j = 0; j < W; j++) {
        if (ss[j] == -1) {
            std::bitset<Wmax> d;
            d[j] = 1;
            for (int jj = 0; jj < W; jj++)
                if (ss[jj] != -1) d[jj] = M[ss[jj]][j];
            D.emplace_back(d);
        } else
            x[j] = M[ss[j]][W];
    }
    return std::make_tuple(true, x, D);
}


int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<bitset<Wmax>> A;
    bitset<Wmax> b;
    vector<vector<short>> C(N);
    for (auto &v : C) v = {0, 1, 2, 3};

    auto c2i = [&](char c) -> short {
        if (c == 'R') return 1;
        if (c == 'Y') return 2;
        if (c == 'B') return 3;
        return 0;
    };

    while (K--) {
        string S;
        int sz;
        cin >> S >> sz;
        vector<int> ids(sz);
        for (auto &x : ids) cin >> x, x--;
        if (S == "mix") {
            char cr;
            cin >> cr;
            {
                const short ir = c2i(cr);
                b[A.size()] = ir % 2;
                b[A.size() + 1] = ir / 2;
            }
            bitset<Wmax> VU, VL;
            for (const auto i : ids) {
                const int l = i * 2, r = l + 1;
                if (C[i][1] == 1 and C[i][2] == 2) VU.set(l), VL.set(r);
                if (C[i][1] == 1 and C[i][2] == 3) VU.set(l), VU.set(r), VL.set(r);
                if (C[i][1] == 2 and C[i][2] == 1) VU.set(r), VL.set(l);
                if (C[i][1] == 2 and C[i][2] == 3) VU.set(r), VL.set(l), VL.set(r);
                if (C[i][1] == 3 and C[i][2] == 1) VU.set(l), VU.set(r), VL.set(l);
                if (C[i][1] == 3 and C[i][2] == 2) VU.set(l), VL.set(l), VL.set(r);
            }
            A.emplace_back(VU), A.emplace_back(VL);
        } else {
            const short s0 = c2i(S[0]), s1 = c2i(S[1]);
            for (const auto i : ids) {
                for (auto &c : C[i]) {
                    if (c == s0) c = s1;
                    else if (c == s1) c = s0;
                }
            }
        }
    }
    const auto [ok, sol, freedoms] = system_of_linear_equations(A, b, N * 2);

    const string i2c = ".RYB";
    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < N; i++) cout << i2c[2 * sol[i * 2 + 1] + sol[i * 2]];
        cout << '\n';
    } else {
        puts("NO");
    }
}