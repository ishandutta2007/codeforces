#include <bits/stdc++.h>
using namespace std;


struct Line {
    long long k, d;

    long long eval(int x) {
        return k * x + d;
    }
};

class LiChaoNode {
public:
    LiChaoNode(Line line) : line(line) {}

    void add_line(Line new_line, int l, int r) {
        int m = (l + r) / 2;
        bool left_smaller = new_line.eval(l) < line.eval(l);
        bool middle_smaller = new_line.eval(m) < line.eval(m);
        if (middle_smaller)
            std::swap(line, new_line);

        if (r - l == 1)
            return;

        if (left_smaller != middle_smaller) {
            if (left == nullptr)
                left = new LiChaoNode(new_line);
            else
                left->add_line(new_line, l, m);
        } else {
            if (right == nullptr)
                right = new LiChaoNode(new_line);
            else
                right->add_line(new_line, m, r);
        }
    }

    long long get_minimum(int x, int l, int r) {
        long long val = line.eval(x);
        int m = (l + r) / 2;
        if (r - l > 1) {
            if (x < m && left != nullptr)
                val = std::min(val, left->get_minimum(x, l, m));
            if (x >= m && right != nullptr)
                    val = std::min(val, right->get_minimum(x, m, r));
        }
        return val;
    }

private:
    Line line;
    LiChaoNode* left = nullptr;
    LiChaoNode* right = nullptr;
};

class LiChaoTree
{
public:
    LiChaoTree()
        : mi(numeric_limits<int>::min() / 2), 
          ma(numeric_limits<int>::max() / 2), 
          root(nullptr) {}

    LiChaoTree(int mi, int ma) : mi(mi), ma(ma) {
        root = new LiChaoNode({0, std::numeric_limits<long long>::max() / 2});
    }

    ~LiChaoTree() {
    }

    void add_line(Line line) {
        root->add_line(line, mi, ma + 1);
    }

    long long get_minimum(int x) {
        return root->get_minimum(x, mi, ma + 1);
    }

private:
    int mi, ma;
    LiChaoNode* root;
};

vector<LiChaoTree> dp;
vector<long long> result, a, b;
vector<vector<int>> adj;
vector<int> sz;
vector<vector<Line>> dp_lines;

void dfs(int v, int p) {
    result[v] = std::numeric_limits<long long>::max();
    sz[v] = 1;
    int mxsz = 0;
    int mxidx = -1;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            result[v] = min(result[v], dp[u].get_minimum(a[v]));
            if (sz[u] > mxsz) {
                mxidx = u;
                mxsz = sz[u];
            }
            sz[v] += sz[u];
        }
    }

    dp[v] = {-100'001, 100'001};
    if (mxidx < 0) {
        result[v] = 0;
    } else {
        dp[v] = dp[mxidx];
        dp_lines[v].swap(dp_lines[mxidx]);
        for (int u : adj[v]) {
            if (u == p || u == mxidx)
                continue;
            for (auto& line : dp_lines[u]) {
                dp_lines[v].push_back(line);
                dp[v].add_line(line);
            }
        }
    }

    Line l{b[v], result[v]};
    dp[v].add_line(l);
    dp_lines[v].push_back(l);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    result.resize(n);
    dp_lines.resize(n);
    sz.resize(n);
    dp.resize(n);
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

}