#include<bits/stdc++.h>

using namespace std;

struct point {
    long long x = 0, y = 0;

    point() {}

    point(long long x, long long y) : x(x), y(y) {}

    point operator -(const point& a) const {
        return point(x - a.x, y - a.y);
    }

    bool operator <(const point& a) const {
        return y < a.y || (y == a.y && x < a.x);
    }
};

istream& operator >>(istream& in, point& a) {
    in >> a.x;
    in >> a.y;
    return in;
}

long long operator *(const point& a, const point& b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<point> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mn = min_element(a.begin(), a.end()) - a.begin();
    vector<int> used(n), ans = {mn};
    used[mn] = 1;
    string s;
    cin >> s;
    for (auto c : s) {
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (used[i]) {
                continue;
            }
            if (c == 'R' && (j == -1 || (a[i] - a[ans.back()]) * (a[j] - a[ans.back()]) < 0)) {
                j = i;
            }
            if (c == 'L' && (j == -1 || (a[i] - a[ans.back()]) * (a[j] - a[ans.back()]) > 0)) {
                j = i;
            }
        }
        ans.push_back(j);
        used[j] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            ans.push_back(i);
        }
    }
    for (auto x : ans) {
        cout << x + 1 << " ";
    }
}