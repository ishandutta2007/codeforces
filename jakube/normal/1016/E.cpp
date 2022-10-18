#include <bits/stdc++.h>
using namespace std;

double cut(pair<int, int> p, pair<int, int> q){
    return p.first + (q.first - p.first) / (double)(q.second - p.second) * -p.second;
}

vector<pair<int, int>> v;
vector<int> psum;

double left_of(double val) {
    int idx = lower_bound(v.begin(), v.end(), make_pair((int)ceil(val),(int)-1e9-100)) - v.begin();
    if (idx == 0)
        return 0.;
    --idx;
    if (v[idx].second <= val)
        return psum[idx];
    else
        return psum[idx] + (val - v[idx].second);
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout << std::fixed << std::setprecision(9);

    int sy, a, b;
    cin >> sy >> a >> b;
    pair<int, int> A(a,sy), B(b,sy);
    int n;
    cin >> n;
    v.resize(n);
    for (auto& x : v)
        cin >> x.first >> x.second;
    sort(v.begin(), v.end());
    
    psum.resize(n);
    for (int idx = 0; idx < n; idx++) {
        psum[idx] = v[idx].second - v[idx].first;
        if (idx)
            psum[idx] += psum[idx-1];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        pair<int,int> pt;
        cin >> pt.first >> pt.second;
        double left = cut(A,pt);
        double right = cut(B,pt);
        double length = left_of(right) - left_of(left);
        cout << length / (double)pt.second * (pt.second - sy) << '\n';
    }
}