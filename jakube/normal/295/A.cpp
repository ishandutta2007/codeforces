#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> tr;


template <typename T>
void update(int l, int r, long long v, int n, vector<T> &data) {
    l += n;
    r += n;

    while (l < r) {
        if (l & 1) {
            data[l] += v;
            l++;
        }
        if (r & 1) {
            r--;
            data[r] += v;
        }
        l >>= 1;
        r >>= 1;
    }
}

template <typename T>
long long getVal(int idx, vector<T> &data, int n) {
    idx += n;
    long long sum = 0;

    while (idx > 0) {
        sum += data[idx];
        idx >>= 1;
    }
    return sum;
}


int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    vector<int> data2;
    int n2;
    vector<long long> data;
    int n;

    int m, k;
    cin >> n >> m >> k;
    n2 = m;
    data2 = vector<int>(2*n2, 0);
    data = vector<long long>(2*n, 0);
    for (int idx = 0; idx < n;  idx++)
        cin >> data[n + idx];
    
    vector<tr> op(m);
    for (int i = 0; i < m; ++i) {
        cin >> get<0>(op[i]) >> get<1>(op[i]) >> get<2>(op[i]);
        get<0>(op[i])--;
        get<1>(op[i])--;
    }

    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        update(l, r+1, 1, n2, data2);
    }

    for (int i = 0; i < m; ++i) {
        update(get<0>(op[i]), get<1>(op[i]) + 1, (long long)get<2>(op[i]) * (long long)getVal(i, data2, m), n, data);
    }


    for (int i = 0; i < n; ++i) {
        cout << getVal(i, data, n) << " ";
    }
    cout << endl;


    return 0;
}