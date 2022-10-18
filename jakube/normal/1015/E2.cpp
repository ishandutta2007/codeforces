#include <bits/stdc++.h>
using namespace std;


class SegmentTree {
public:
    SegmentTree(int count) {
        n = count;
        data.assign(2 * n, 0);
    }

    SegmentTree(std::vector<int> const &values) {
        n = values.size();
        data.resize(2 * n);
        std::copy(values.begin(), values.end(), &data[0] + n);
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = data[2 * idx] + data[2 * idx + 1];
    }

    int get(int idx) {
        idx += n;
        int ret = data[idx];
        while (idx > 1) {
            idx /= 2;
            ret |= data[idx];
        }
        return ret;
    }

    void update(int left, int right) { // interval [left, right)
        left += n;
        right += n;

        while (left < right) {
            if (left & 1) data[left++] = 1;
            if (right & 1) data[--right] = 1;
            left >>= 1;
            right >>= 1;
        }
    }

private:
    int n;
    std::vector<int> data;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (auto& x : board)
        cin >> x;

    vector<vector<int>> dot_left(n, vector<int>(m));
    vector<vector<int>> dot_right(n, vector<int>(m));
    vector<vector<int>> dot_up(n, vector<int>(m));
    vector<vector<int>> dot_down(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        int last = -1;
        for (int j = 0; j < m; j++) {
            dot_left[i][j] = last;
            if (board[i][j] == '.')
                last = j;
        }
    }
    for (int i = 0; i < n; i++) {
        int last = m;
        for (int j = m-1; j >= 0; j--) {
            dot_right[i][j] = last;
            if (board[i][j] == '.')
                last = j;
        }
    }
    for (int j = 0; j < m; j++) {
        int last = -1;
        for (int i = 0; i < n; i++) {
            dot_up[i][j] = last;
            if (board[i][j] == '.')
                last = i;
        }
    }
    for (int j = 0; j < m; j++) {
        int last = n;
        for (int i = n-1; i >= 0; i--) {
            dot_down[i][j] = last;
            if (board[i][j] == '.')
                last = i;
        }
    }

    auto max_possible = [&](int x, int y) {
        int res = 1'000'000;
        res = min(res, y - dot_left[x][y]);
        res = min(res, dot_right[x][y] - y);
        res = min(res, x - dot_up[x][y]);
        res = min(res, dot_down[x][y] - x);
        res--;
        return res;
    };

    vector<SegmentTree> rows(n, {m}), cols(m, {n});
    struct S {
        int x, y, len;
    };
    vector<S> result;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.')
                continue;
            int ma = max_possible(i, j);
            if (ma == 0)
                continue;
            result.push_back({i, j, ma});
            rows[i].update(j - ma, j + ma + 1);
            cols[j].update(i - ma, i + ma + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '*' && !(rows[i].get(j) || cols[j].get(i))) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << (int)result.size() << '\n';
    for (auto s : result) {
        cout << s.x + 1 << " " << s.y + 1 << " " << s.len << "\n";
    }
}