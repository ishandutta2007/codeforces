#include <bits/stdc++.h>
using namespace std;

int n, k, m;
vector<vector<int>> adj;

class UnionFind {
public:
    vector<int> parent;
    int cnt;
    int lower_idx, upper_idx;

    UnionFind() {}

    UnionFind(int n, int lower_idx, int upper_idx) : lower_idx(lower_idx), upper_idx(upper_idx) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        cnt = (n == 0) ? 0 : 1;
    }

    UnionFind(UnionFind l, UnionFind r) {
        parent.resize(l.parent.size() + r.parent.size());
        for (int i = 0; i < l.parent.size(); i++) {
            parent[i] = l.parent[i];
        }
        for (int i = 0; i < r.parent.size(); i++) {
            parent[i + l.parent.size()] = r.parent[i] + l.parent.size();
        }

        lower_idx = l.lower_idx;
        upper_idx = r.upper_idx;
        cnt = l.cnt + r.cnt;

        for (int i = max(l.lower_idx, l.upper_idx - k + 1); i <= l.upper_idx; i++) {
            for (int j : adj[i]) {
                if (r.lower_idx <= j && j <= r.upper_idx) {
                    if (Union(i - lower_idx, j - lower_idx)) {
                        cnt--;
                    }
                }
            }
        }
    }

    int find(int i) {
        if (i < 0 || i >= parent.size()) return -1;
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }

    bool Union(int i, int j) {
        int x = find(i);
        int y = find(j);
        if (x != y) {
            parent[y] = x;
            return true;
        } else {
            return false;
        }
    }

    array<int, 5> left_side() {
        return {{
            find(0), 
            find(1), 
            find(2), 
            find(3), 
            find(4)
        }};
    }

    array<int, 5> right_side() {
        return {{
            find(upper_idx - lower_idx - 4), 
            find(upper_idx - lower_idx - 3), 
            find(upper_idx - lower_idx - 2), 
            find(upper_idx - lower_idx - 1), 
            find(upper_idx - lower_idx - 0) 
        }};
    }
};

class SegmentTree {
public:
    vector<UnionFind> data;
    int n;

    SegmentTree(int n) {
        this->n = n;
        data.resize(2*n);
        
        for (int i = 0; i < n; i++) {
            data[i + n] = {1, i, i};
        }

        for (int i = n-1; i > 0; i--) {
            data[i] = {data[i<<1], data[i<<1|1]};
        }
    }

    int range(int left, int right) {
        vector<int> indices;
        vector<int> indices_r;

        left += n;
        right += n;

        while (left < right) {
            if (left & 1) indices.push_back(left++);
            if (right & 1) indices_r.push_back(--right);
            left >>= 1;
            right >>= 1;
        }

        reverse(indices_r.begin(), indices_r.end());
        for (int i : indices_r) indices.push_back(i);

        auto& old_seg = data[indices.front()];
        int result = old_seg.cnt;
        auto left_side = old_seg.right_side();

        int cur_low = old_seg.lower_idx;
        int cur_upp = old_seg.upper_idx;

        for (int i = 1; i < indices.size(); i++) {
            auto& new_seg = data[indices[i]];
            auto new_left = new_seg.left_side();
            auto new_right = new_seg.right_side();
            
            for (auto& val : new_left) {
                if (val != -1)
                    val += cur_upp + 1 - cur_low;
            }
            for (auto& val : new_right) {
                if (val != -1)
                    val += cur_upp + 1 - cur_low;
            }

            for (int i = max(cur_low, cur_upp - k + 1); i <= cur_upp; i++) {
                for (int j : adj[i]) {
                    if (new_seg.lower_idx <= j && j <= new_seg.upper_idx) {
                        int nnew = left_side[i - cur_upp + 4];
                        int old = new_left[j - new_seg.lower_idx];
                        if (nnew != old) {
                            for (auto& val : new_left) {
                                if (val == old) val = nnew;
                            }
                            for (auto& val : new_right) {
                                if (val == old) val = nnew;
                            }
                            result--;
                        }
                    }
                }
            }

            // now shift
            if (new_right[3] == -1) {
                left_side[0] = left_side[1];
                left_side[1] = left_side[2];
                left_side[2] = left_side[3];
                left_side[3] = left_side[4];
                left_side[4] = new_right[4];
            } else if (new_right[2] == -1) {
                left_side[0] = left_side[2];
                left_side[1] = left_side[3];
                left_side[2] = left_side[4];
                left_side[3] = new_right[3];
                left_side[4] = new_right[4];
            } else if (new_right[0] == -1) {
                left_side[0] = left_side[4];
                left_side[1] = new_right[1];
                left_side[2] = new_right[2];
                left_side[3] = new_right[3];
                left_side[4] = new_right[4];
            } else {
                left_side = new_right;
            }

            result += new_seg.cnt;
            cur_upp = new_seg.upper_idx;
        }


        return result;
    }  
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    cin >> n >> k >> m;

    int power = 1;
    while (power < n) power <<= 1;

    adj.resize(power);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    SegmentTree st(power);
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << st.range(l-1, r) << '\n';
    }

    return 0;
}