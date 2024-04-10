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

void transpose(vector<vector<int>>& a, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}

void perm_inverse(vector<vector<int>>& a, int n) {
    for (int i = 0; i < n; i++) {
        vector<int> p(n);
        for (int j = 0; j < n; j++) {
            p[a[i][j]] = j;
        }
        for (int j = 0; j < n; j++) {
            a[i][j] = p[j];
        }
    }
}

const int NUM_OPS = 6;

struct OpMatrix {
    int a[NUM_OPS][NUM_OPS];
};

void make_nill(OpMatrix& a) {
    for (int i = 0; i < NUM_OPS; i++) {
        for (int j = 0; j < NUM_OPS; j++) {
            a.a[i][j] = 0;
        }
    }
}

void make_identity(OpMatrix& a) {
    make_nill(a);
    for (int i = 0; i < NUM_OPS; i++) {
        a.a[i][i] = 1;
    }
}

void make_I(OpMatrix& a) {
    make_nill(a);
    a.a[0][0] = 1;
    a.a[1][1] = 1;
    a.a[2][4] = 1;
    a.a[3][5] = 1;
    a.a[4][2] = 1;
    a.a[5][3] = 1;
}

void make_C(OpMatrix& a) {
    make_nill(a);
    a.a[0][4] = 1;
    a.a[1][5] = 1;
    a.a[2][2] = 1;
    a.a[3][3] = 1;
    a.a[4][0] = 1;
    a.a[5][1] = 1;
}

OpMatrix mul(OpMatrix& a, OpMatrix& b) {
    OpMatrix res;
    make_nill(res);
    for (int i = 0; i < NUM_OPS; i++) {
        for (int j = 0; j < NUM_OPS; j++) {
            for (int k = 0; k < NUM_OPS; k++) {
                res.a[i][j] += a.a[i][k] * b.a[k][j];
            }
        }
    }
    return res;
}

vector<int> mul_vector(vector<int>& a, OpMatrix& b) {
    vector<int> res(NUM_OPS, 0);
    for (int i = 0; i < NUM_OPS; i++) {
        for (int j = 0; j < NUM_OPS; j++) {
            res[i] += b.a[i][j] * a[j];
        }
    }
    return res;
}

int get_int(char c) {
    if (c == 'D') return 0;
    if (c == 'U') return 1;
    if (c == 'R') return 2;
    if (c == 'L') return 3;
    if (c == 'P') return 4;
    if (c == 'M') return 5;
    return 6;
}

vector<int> get_vector(char c) {
    vector<int> a(NUM_OPS, 0);
    a[get_int(c)] = 1;
    return a;
}

char get_char(vector<int>& a) {
    if (a[0] == 1) return 'D';
    if (a[1] == 1) return 'U';
    if (a[2] == 1) return 'R';
    if (a[3] == 1) return 'L';
    if (a[4] == 1) return 'P';
    if (a[5] == 1) return 'M';
}

void move_down(vector<vector<int>>& a, int n, int c) {
    c = ((c % n) + n) % n;
    if (c == 0) return;
    for (int j = 0; j < n; j++) {
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[(i + c) % n] = a[i][j];
        }
        for (int i = 0; i < n; i++) {
            a[i][j] = p[i];
        }
    }
}

void move_right(vector<vector<int>>& a, int n, int c) {
    c = ((c % n) + n) % n;
    if (c == 0) return;
    for (int i = 0; i < n; i++) {
        vector<int> p(n);
        for (int j = 0; j < n; j++) {
            p[(j + c) % n] = a[i][j];
        }
        for (int j = 0; j < n; j++) {
            a[i][j] = p[j];
        }
    }
}

void increment(vector<vector<int>>& a, int n, int c) {
    c = ((c % n) + n) % n;
    if (c == 0) return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = (a[i][j] + c) % n;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    string s;
    cin >> s;
    
    OpMatrix matrix_I;
    make_I(matrix_I);
    OpMatrix matrix_C;
    make_C(matrix_C);
    OpMatrix res;
    make_identity(res);

    int num_perms = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == 'I' || s[i] == 'C') num_perms++;
    }
   
    vector<char> perms(num_perms);
    vector<int> num_ops(NUM_OPS, 0);

    for (int i = m - 1; i >= 0; i--) {
        if (s[i] == 'I') {
            res = mul(res, matrix_I);
            perms[num_perms - 1] = 'I';
            num_perms--;
        } else if (s[i] == 'C') {
            res = mul(res, matrix_C);
            perms[num_perms - 1] = 'C';
            num_perms--;
        } else {
            char c = s[i];
            vector<int> c_vector = get_vector(c);
            c_vector = mul_vector(c_vector, res);
            int x = get_int(get_char(c_vector));
            // cout << x << "\n";
            num_ops[x]++;
        }
    }

    if (!perms.empty()) {
        vector<char> skimmed_perms;
        for (auto c : perms) {
            if (skimmed_perms.empty()) {
                skimmed_perms.push_back(c);
            } else if (skimmed_perms[skimmed_perms.size() - 1] == c) {
                skimmed_perms.pop_back();
            } else {
                skimmed_perms.push_back(c);
            }
        }
        
        for (int i = skimmed_perms.size() / 6 * 6; i < skimmed_perms.size(); i++) {
            if (skimmed_perms[i] == 'I') {
                perm_inverse(a, n);
            } else {
                transpose(a, n);
                perm_inverse(a, n);
                transpose(a, n);
            }
        }
    }

    int down_count = num_ops[0] - num_ops[1];
    int right_count = num_ops[2] - num_ops[3];
    int plus_count = num_ops[4] - num_ops[5];

    move_down(a, n, down_count);
    move_right(a, n, right_count);
    increment(a, n, plus_count);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] + 1 << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}