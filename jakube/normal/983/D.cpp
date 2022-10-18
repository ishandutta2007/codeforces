#include <bits/stdc++.h>
using namespace std;

struct Point {
    friend istream& operator>>(istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }

    int x, y;
};

vector<pair<Point, Point>> rectangles;
vector<bool> answer;

struct Segment {
    set<int> cover;
    int mavna = -1;
    int miv = -1;
};

class SegmentTreeRec
{
public:
    SegmentTreeRec(int n) : n(n) { data.resize(4 * n); }

    void recompute(int id, int l, int r) {
        if (l + 1 == r) {
            if (data[id].cover.empty()) {
                data[id].mavna = data[id].miv = -1;
            } else {
                int m = *data[id].cover.rbegin();
                data[id].mavna = answer[m] ? -1 : m;
                data[id].miv = m;
            }
        } else {
            int m_ch = max(data[id<<1].mavna, data[id<<1|1].mavna);
            int mi_ch = min(data[id<<1].miv, data[id<<1|1].miv);
            if (!data[id].cover.empty()) {
                int m = *data[id].cover.rbegin();
                if (m > m_ch)
                    data[id].mavna = (answer[m] || m < mi_ch) ? -1 : m;
                else
                    data[id].mavna = m_ch;
                data[id].miv = max(m, mi_ch);
            } else {
                data[id].mavna = m_ch;
                data[id].miv = mi_ch;
            }
        }
    }

    void add(int color, int x, int y, int id = 1, int l = 0, int r = -1) {
        if (r == -1)
            r = n;

        if (x <= l && r <= y) {
            data[id].cover.insert(color);
        } else {
            int mid = (l + r) / 2;
            if (x < mid)
                add(color, x, y, id<<1, l, mid);
            if (y > mid)
                add(color, x, y, id<<1|1, mid, r);
        }

        recompute(id, l, r);
    }

    void remove(int color, int x, int y, int id = 1, int l = 0, int r = -1) {
        if (r == -1)
            r = n;

        if (x <= l && r <= y) {
            data[id].cover.erase(color);
        } else {
            int mid = (l + r) / 2;
            if (x < mid)
                remove(color, x, y, id<<1, l, mid);
            if (y > mid)
                remove(color, x, y, id<<1|1, mid, r);
        }

        recompute(id, l, r);
    }

    int n;
    std::vector<Segment> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    rectangles.resize(n);
    vector<int> x(2*n), y(2*n);
    for (int i = 0; i < n; i++) {
        auto & r = rectangles[i];
        cin >> r.first >> r.second;
        x[2*i] = r.first.x;
        x[2*i+1] = r.second.x;
        y[2*i] = r.first.y;
        y[2*i+1] = r.second.y;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    y.erase(unique(y.begin(), y.end()), y.end());

    vector<vector<int>> starts(2*n);
    vector<vector<int>> ends(2*n);
    for (int i = 0; i < n; i++) {
        auto & r = rectangles[i];
        r.first.x = lower_bound(x.begin(), x.end(), r.first.x) - x.begin();
        r.second.x = lower_bound(x.begin(), x.end(), r.second.x) - x.begin();
        r.first.y = lower_bound(y.begin(), y.end(), r.first.y) - y.begin();
        r.second.y = lower_bound(y.begin(), y.end(), r.second.y) - y.begin();
        starts[r.first.x].push_back(i);
        ends[r.second.x].push_back(i);
    }

    SegmentTreeRec st(2*n);
    answer.assign(n, false);
    int cnt = 0;
    for (int i = 0; i < 2*n; i++) {
        for (int s : starts[i]) {
            auto r = rectangles[s];
            st.add(s, r.first.y, r.second.y);
        }
        for (int e : ends[i]) {
            auto r = rectangles[e];
            st.remove(e, r.first.y, r.second.y);
        }
        while (st.data[1].mavna >= 0) {
            int x = st.data[1].mavna;
            answer[x] = true;
            auto r = rectangles[x];
            st.remove(x, r.first.y, r.second.y);
            st.add(x, r.first.y, r.second.y);
            cnt++;
        }
    }
    cout << cnt + 1 << '\n';
}