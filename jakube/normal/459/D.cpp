#include <bits/stdc++.h>
using namespace std;

vector<int> data;
int n;

void update(int idx, int add) {
    idx += n;
    data[idx] += add;

    while (idx > 1) {
        idx /= 2;
        data[idx] += add;
    }
}

int query(int left, int right) {
    left += n;
    right += n;
    int sum = 0;

    while (left < right) {
        if (left & 1) sum += data[left++];
        if (right & 1) sum += data[--right];
        left >>= 1; right >>= 1;
    }
    return sum;
}


int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n;  idx++)
        cin >> v[idx];
    
    map<int, int> m;
    vector<int> cnts(n);
    for (int i = 0; i < n; ++i) {
        int elem = v[i];
        auto it = m.find(elem);
        if (it != m.end()) {
            cnts[i] = ++(it->second);
        }
        else
        {
            cnts[i] = 1;
            m[elem] = 1;
        }
    }

    vector<int> rev(n);
    m.clear();
    for (int i = n-1; i >= 0; i--) {
        int elem = v[i];
        auto it = m.find(elem);
        if (it != m.end()) {
            rev[i] = ++(it->second);
        }
        else
        {
            rev[i] = 1;
            m[elem] = 1;
        }
    }

    data = vector<int>(2*n, 0);

    for (int i : rev) {
        update(i, 1);
    }

    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        update(rev[i], -1);
        cnt += query(0, cnts[i]);
    }

    cout << cnt << endl;
}