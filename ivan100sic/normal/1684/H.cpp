// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void solve(span<int> p, int tgt, vector<int>& sol);

void solve_last(span<int> p, int tgt, vector<int>& sol) {
    sol.push_back(1);
    sol.push_back(p[1] - p[0] - 1);
    solve(p.subspan(1), tgt - 1, sol);
}

bool solve_last_three_except_111(span<int> p, int tgt, vector<int>& sol) {
    // 100...
    if (p[1] - p[0] >= 3) {
        sol.push_back(3);
        sol.push_back(p[1] - p[0] - 3);
        solve(p.subspan(1), tgt - 4, sol);
        return true;
    }

    // 101...
    if (p[1] - p[0] == 2) {
        sol.push_back(3);
        sol.push_back(p[2] - p[0] - 3);
        solve(p.subspan(2), tgt - 5, sol);
        return true;
    }

    // 110...
    if (p[1] - p[0] == 1 && p[2] - p[1] >= 2) {
        sol.push_back(3);
        sol.push_back(p[2] - p[0] - 3);
        solve(p.subspan(2), tgt - 6, sol);
        return true;
    }

    return false;
}

void solve_last_three(span<int> p, int tgt, vector<int>& sol) {
    if (solve_last_three_except_111(p, tgt, sol)) {
        return;
    }
    
    // 111
    if (p[2] - p[0] == 2) {
        sol.push_back(3);
        sol.push_back(p[3] - p[0] - 3);
        solve(p.subspan(3), tgt - 7, sol);
    }
}

void solve_111x(span<int> p, int tgt, vector<int>& sol) {
    // 1111
    if (p[3] - p[0] == 3) {
        sol.push_back(4);
        sol.push_back(p[4] - p[0] - 4);
        solve(p.subspan(4), tgt - 15, sol);
        return;
    }

    // 1110
    sol.push_back(4);
    sol.push_back(p[3] - p[0] - 4);
    solve(p.subspan(3), tgt - 14, sol);
    return;
}

void solve_prefix_chunk(span<int> p, int tgt, vector<int>& sol, int cnt, int wt) {
    solve(p.subspan(0, cnt), wt, sol);
    sol.push_back(p[cnt] - p[cnt-1] - 1);
    solve(p.subspan(cnt), tgt - wt, sol);
}

void solve(span<int> p, int tgt, vector<int>& sol) {
    const int n = ssize(p);

    if (n >= 12) {
        if (tgt == 2*n) {
            solve_last_three(p, tgt, sol);
        } else {
            solve_last(p, tgt, sol);
        }
        return;
    }

    if (n == 11) {
        if (tgt == 22) {
            if (!solve_last_three_except_111(p, tgt, sol)) {
                solve_111x(p, tgt, sol);
            }
        } else {
            solve_last(p, tgt, sol);
        }
        return;
    }

    if (n == 10) {
        if (tgt == 20) {
            solve_prefix_chunk(p, tgt, sol, 5, 10);
        } else {
            solve_last(p, tgt, sol);
        }
        return;
    }

    // this is the last one where everything is possible
    if (n == 9) {
        if (tgt == 18 || tgt == 16) {
            solve_prefix_chunk(p, tgt, sol, 5, 10);
        } else {
            solve_last(p, tgt, sol);
        }
        return;
    }

    // 8-14, 16
    if (n == 8) {
        if (tgt == 16) {
            solve_prefix_chunk(p, tgt, sol, 4, 8);
        } else {
            solve_last(p, tgt, sol);
        }
        return;
    }

    // 7-13
    if (n == 7) {
        if (tgt == 13) {
            solve_prefix_chunk(p, tgt, sol, 5, 10);
        } else {
            solve_last(p, tgt, sol);
        }
        return;
    }

    // 6-11
    if (n == 6) {
        if (tgt == 9) {
            solve_prefix_chunk(p, tgt, sol, 4, 6);
        } else {
            solve_last(p, tgt, sol);
        }
        return;
    }

    // 5, 6, 7, 9, 10
    if (n == 5) {
        if (tgt == 10) {
            // 111...
            if (p[2] - p[0] == 2) {
                sol.push_back(3);
                sol.push_back(p[3] - p[0] - 3);
                solve(p.subspan(3), 3, sol); // 2 left
                return;
            }

            // 110...
            if (p[1] - p[0] == 1) {
                sol.push_back(3);
                sol.push_back(p[2] - p[0] - 3);
                solve(p.subspan(2), 4, sol); // 3 left
                return;
            }

            // 10...
            sol.push_back(2);
            sol.push_back(p[1] - p[0] - 2);
            solve(p.subspan(1), 8, sol); // 4 left
            return;
        } else {
            solve_last(p, tgt, sol);
        }
        return;
    }

    // 4, 5, 6, 8
    if (n == 4) {
        if (tgt == 4 || tgt == 5) {
            solve_last(p, tgt, sol);
        } else if (tgt == 6) {
            solve_prefix_chunk(p, tgt, sol, 2, 3);
        } else {
            solve_last_three(p, tgt, sol);
        }
        return;
    }

    // 3, 4
    if (n == 3) {
        solve_prefix_chunk(p, tgt, sol, 1, 1);
        return;
    }

    // 2, 3
    if (n == 2) {
        if (tgt == 2) {
            return solve_last(p, tgt, sol);
        } else {
            if (p[1] - p[0] == 1) {
                sol.push_back(2);
            } else {
                sol.push_back(2);
                sol.push_back(p[1] - p[0] - 2);
                sol.push_back(1);
            }
        }
        return;
    }

    // 1
    if (n == 1) {
        sol.push_back(1);
        return;
    }
}

void solve5(span<int> p, vector<int>& sol) {
    // 1111...
    if (p[3] - p[0] == 3) {
        sol.push_back(4);
        sol.push_back(p[4] - p[3] - 1);
        sol.push_back(1);
        return;
    }

    // 111... and thus 1110...
    if (p[2] - p[0] == 2) {
        sol.push_back(2); // 11
        sol.push_back(2); // 10
        sol.push_back(p[3] - p[0] - 4);
        solve(p.subspan(3), 3, sol);
        return;
    }

    // 11... and thus 110...
    if (p[1] - p[0] == 1) {
        // 110 0...
        if (p[2] - p[1] >= 3) {
            sol.push_back(1); // 1
            sol.push_back(3); // 100
            sol.push_back(p[2] - p[0] - 4);
            solve(p.subspan(2), 3, sol);
        } else {
            sol.push_back(1); // 1
            sol.push_back(3); // 101
            sol.push_back(p[3] - p[0] - 4);
            solve(p.subspan(3), 2, sol);
        }
        return;
    }

    // 1... and thus 10...
    sol.push_back(2); // 10
    sol.push_back(p[1] - p[0] - 2);
    solve(p.subspan(1), 6, sol);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int n = ssize(s);
        
        if (R::count(s, '1') == 0) {
            cout << "-1\n\n";
            continue;
        }

        vector<int> p;
        for (int i : ra(0, n)) {
            if (s[i] == '1') {
                p.push_back(i);
            }
        }

        // prefix zeros
        vector<int> sol;
        for (int i : ra(0, p[0])) {
            sol.push_back(1);
        }

        // main solution
        if (size(p) == 5) {
            // this one is tricky
            solve5(span(p), sol);
        } else {
            solve(span(p), bit_ceil(size(p)), sol);
        }

        // suffix zeros
        for (int i : ra(p.back() + 1, n)) {
            sol.push_back(1);
        }

        int l = 1;
        cout << sol.size() - R::count(sol, 0) << "\n";
        for (int x : sol) {
            if (x == 0) continue;
            cout << l << ' ' << l+x-1 << '\n';
            l += x;
        }
        cout << '\n';
    }
}