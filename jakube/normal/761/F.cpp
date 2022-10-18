#include <bits/stdc++.h>
using namespace std;

struct Rect {
    int a, b, c, d, e;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> s(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            s[i][j] = tmp[j] - 'a';
        }
    }
    vector<Rect> v(k);
    for (int i = 0; i < k; i++) {
        Rect& r = v[i];
        char e;
        cin >> r.a >> r.b >> r.c >> r.d >> e;
        r.a--;
        r.b--;
        r.e = e - 'a';
    }

    // cnt[x][y][c] .. how many pictures have at pixel (x,y) the char c (different to original)
    vector<vector<vector<int>>> cnt(n + 1, vector<vector<int>>(m + 1, vector<int>(26, 0)));
    for (auto r : v) {
        cnt[r.a][r.b][r.e]++;
        cnt[r.a][r.d][r.e]--;
        cnt[r.c][r.b][r.e]--;
        cnt[r.c][r.d][r.e]++;
    }
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            for (int c = 0; c < 26; c++) {
                if (i) 
                    cnt[i][j][c] += cnt[i-1][j][c];
                if (j)
                    cnt[i][j][c] += cnt[i][j-1][c];
                if (i && j)
                    cnt[i][j][c] -= cnt[i-1][j-1][c];
            }
        }
    }

    // f[x][y] .. cost of all pictures to original at pixel (x,y)
    vector<vector<int>> f(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int c = 0; c < 26; c++) {
                f[i][j] += abs(c - s[i][j]) * cnt[i][j][c];
            }
        }
    }

    // g[x][y] .. total cost of subarray (1,1,x,y)
    vector<vector<long long>> g(n, vector<long long>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g[i][j] = f[i][j];
            if (i)
                g[i][j] += g[i-1][j];
            if (j)
                g[i][j] += g[i][j-1];
            if (i && j)
                g[i][j] -= g[i-1][j-1];
        }
    }

    // cnt2[x][y][c] .. similar to cnt, but also with original pixels
    vector<vector<vector<int>>> cnt2(n + 1, vector<vector<int>>(m + 1, vector<int>(26, 0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int total = 0;
            for (int c = 0; c < 26; c++) {
                cnt2[i][j][c] = cnt[i][j][c];
                total += cnt2[i][j][c];
            }
            cnt2[i][j][s[i][j]] += k - total;
        }
    }

    // q[x][y][c] .. total cnt2 of subarray (1,1,x,y)
    vector<vector<vector<long long>>> q(n + 1, vector<vector<long long>>(m + 1, vector<long long>(26, 0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int c = 0; c < 26; c++) {
                q[i][j][c] = cnt2[i][j][c];
                if (i)
                    q[i][j][c] += q[i-1][j][c];
                if (j)
                    q[i][j][c] += q[i][j-1][c];
                if (i && j)
                    q[i][j][c] -= q[i-1][j-1][c];
            }
        }
    }

    // solve
    long long result = numeric_limits<long long>::max();
    for (auto r : v) {
        // outside rectangle
        long long outside_costs = g[n-1][m-1];
        outside_costs -= g[r.c-1][r.d-1];
        if (r.a)
            outside_costs += g[r.a-1][r.d-1];
        if (r.b)
            outside_costs += g[r.c-1][r.b-1];
        if (r.a && r.b)
            outside_costs -= g[r.a-1][r.b-1];

        // and inside rectangle
        long long inside_costs = 0;
        for (int c = 0; c < 26; c++) {
            long long count_inside = q[r.c-1][r.d-1][c];
            if (r.a)
                count_inside -= q[r.a-1][r.d-1][c];
            if (r.b)
                count_inside -= q[r.c-1][r.b-1][c];
            if (r.a && r.b) 
                count_inside += q[r.a-1][r.b-1][c];
            inside_costs += abs(c - r.e) * count_inside;
        }

        result = min(result, outside_costs + inside_costs);
    }

    cout << result << endl;

    return 0;
}