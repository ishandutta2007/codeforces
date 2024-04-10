#include <bits/stdc++.h>

using namespace std;

const long long LINF = (long long)2e18 + 5;

struct segment_change {
    long long to_add;
    segment_change(long long _to_add = 0) : to_add(_to_add) {}
    void reset() { to_add = 0; }
    bool has_change() const { return to_add != 0; }
    segment_change combine(const segment_change &other) const {
        return segment_change(to_add + other.to_add);
    }
};

struct segment {
    long long maximum;
    int max_index;
    segment(long long _maximum = -LINF, int _max_index = -1)
        : maximum(_maximum), max_index(_max_index) {}
    void apply(int, const segment_change &change) { maximum += change.to_add; }
    void join(const segment &other) {
        if (other.maximum > maximum) {
            maximum = other.maximum;
            max_index = other.max_index;
        }
    }
    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct add_max_seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;
    add_max_seg_tree(int n = 0) {
        if (n > 0) init(n);
    }
    void init(int n) {
        tree_n = 1;
        while (tree_n < n) tree_n *= 2;
        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }
    void build(const vector<segment> &initial) {
        int n = initial.size();
        assert(n <= tree_n);
        for (int i = 0; i < n; i++) tree[tree_n + i] = initial[i];
        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }
    void push_down(int position, int length) {
        if (!changes[position].has_change()) return;
        if (2 * position < tree_n) {
            changes[2 * position] =
                changes[2 * position].combine(changes[position]);
            changes[2 * position + 1] =
                changes[2 * position + 1].combine(changes[position]);
        }
        tree[2 * position].apply(length / 2, changes[position]);
        tree[2 * position + 1].apply(length / 2, changes[position]);
        changes[position].reset();
    }
    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = 31 - __builtin_clz(tree_n); up > 0; up--) {
            int x = a >> up, y = b >> up;
            push_down(x, 1 << up);
            if (x != y) push_down(y, 1 << up);
        }
    }
    void join_and_apply(int position, int length) {
        tree[position].join(tree[2 * position], tree[2 * position + 1]);
        tree[position].apply(length, changes[position]);
    }
    void join_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        int length = 1;

        while (a > 1) {
            a /= 2;
            b /= 2;
            length *= 2;
            join_and_apply(a, length);
            if (a != b) join_and_apply(b, length);
        }
    }
    pair<int, int> right_half[32];
    template <typename T_range_op>
    void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a == b) return;
        push_all(a, b);
        int original_a = a, original_b = b;
        int length = 1, r_size = 0;
        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
            if (a & 1) range_op(a++, length);
            if (b & 1) right_half[r_size++] = {--b, length};
        }
        for (int i = r_size - 1; i >= 0; i--)
            range_op(right_half[i].first, right_half[i].second);
        if (needs_join) join_all(original_a, original_b);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;
        process_range(a, b, false,
                      [&](int position, int) { answer.join(tree[position]); });
        return answer;
    }

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);
        process_range(a, b, true, [&](int position, int length) {
            tree[position].apply(length, change);
            if (position < tree_n)
                changes[position] = changes[position].combine(change);
        });
    }
};

const int INF = 1e9 + 5;

struct point {
    int start, end, score;

    bool operator<(const point &other) const { return end < other.end; }
};

int N, C;
vector<int> coords;
vector<point> points;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    points.resize(N);
    for (int i = 0; i < N; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        points[i].start = min(x, y);
        points[i].end = max(x, y);
        points[i].score = c;
        coords.push_back(x);
        coords.push_back(y);
    }
    coords.push_back(INF);
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    C = coords.size();
    sort(points.begin(), points.end());
    add_max_seg_tree tree(C);
    vector<segment> initial(C);
    for (int c = 0; c < C; ++c) initial[c] = segment(coords[c], c);
    tree.build(initial);
    long long best = -LINF;
    int best_start = -1, best_end = -1;
    for (int c = 0, p = 0; c < C; ++c) {
        while (p < N && points[p].end <= coords[c]) {
            int index =
                lower_bound(coords.begin(), coords.end(), points[p].start) -
                coords.begin();
            tree.update(0, index + 1, segment_change(points[p++].score));
        }
        segment optimal = tree.query(0, c + 1);
        if (optimal.maximum - coords[c] > best) {
            best = optimal.maximum - coords[c];
            best_start = optimal.max_index;
            best_end = c;
        }
    }
    cout << best << '\n';
    cout << coords[best_start] << ' ' << coords[best_start] << ' '
         << coords[best_end] << ' ' << coords[best_end] << '\n';
}