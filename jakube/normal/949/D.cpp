#include <bits/stdc++.h>
using namespace std;

class SegmentTreeRec
{
public:
    SegmentTreeRec(int n) : n(n) { data.assign(4 * n, 0); }

    SegmentTreeRec(std::vector<int> const &values)
    {
        n = values.size();
        data.assign(4 * n, 0);
        build(values);
    }

    void build(std::vector<int> const &values, int id = 1, int l = 0, int r = -1) {
        if (r == -1)
            r = n;

        if (l + 1 == r) {
            data[id] = values[l];
        } else {
            int m = (l + r) >> 1;
            build(values, id << 1, l, m);
            build(values, id << 1 | 1, m, r);
            data[id] = data[id << 1] + data[id << 1 | 1];
        }
    }

    int sum(int x, int y, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (x >= r || y <= l) {
            return 0;
        } else if (x <= l && r <= y) {
            return data[id];
        } else {
            int m = (l + r) >> 1;
            return sum(x, y, id << 1, l, m) + sum(x, y, id << 1 | 1, m, r);
        }
    }

    int remove_left(int a, int b, int rem, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (b < l || a >= r || data[id] == 0) {
            return rem;
        }
       
        if (l + 1 == r) {
            int x = min(rem, data[id]);
            data[id] -= x;
            rem -= x;
            return rem;
        } else {
            int m = (l + r) >> 1;
            rem = remove_left(a, b, rem, id << 1, l, m);
            if (rem)
                rem = remove_left(a, b, rem, id << 1 | 1, m, r);
            data[id] = data[id << 1] + data[id << 1 | 1];
            return rem;
        }
    }

    int remove_right(int a, int b, int rem, int id = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n;

        if (b < l || a >= r || data[id] == 0) {
            return rem;
        }
       
        if (l + 1 == r) {
            int x = min(rem, data[id]);
            data[id] -= x;
            rem -= x;
            return rem;
        } else {
            int m = (l + r) >> 1;
            rem = remove_right(a, b, rem, id << 1 | 1, m, r);
            if (rem)
                rem = remove_right(a, b, rem, id << 1, l, m);
            data[id] = data[id << 1] + data[id << 1 | 1];
            return rem;
        }
    }

private:
    int n;
    std::vector<int> data;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, d, b;
    cin >> n >> d >> b;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTreeRec st(a);
    
    int first = 0;
    int x1 = 0;
    int x2 = 0;
    int second = n - 1;
    for (; first <= second; first++, second--) {
        long long time = first + 1;
        // first i
        // check if it is possible to fill the room
        int l = max(0LL, first - time * d);
        int r = min(n-1, first + time * d);
        int s = st.sum(l, r + 1);
        if (s >= b) {
            st.remove_left(l, r + 1, b);
        } else 
            x1++;
        
        // then n - i - 1
        if (first == second)
            break;
        l = max(0LL, second - time * d);
        r = min(n-1, second + time * d);
        s = st.sum(l, r + 1);
        if (s >= b) {
            st.remove_right(l, r + 1, b);
        } else 
            x2++;
    }

    cout << max(x1, x2) << endl;
}