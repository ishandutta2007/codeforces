#include <bits/stdc++.h>
using namespace std;

class Sums {
public:
    Sums(vector<vector<long long>> v) {
        psum.assign(v.size() + 1, vector<long long>(v[0].size() + 1, 0));
        for (auto i = 0u; i < v.size(); i++) {
            for (auto j = 0u; j < v[0].size(); j++) {
                psum[i+1][j+1] = psum[i+1][j] + psum[i][j+1] - psum[i][j] + v[i][j];
            }
        }
    }

    vector<vector<long long>> psum;

    long long sum(int x1, int y1, int x2, int y2) {
        return psum[x2+1][y2+1] - psum[x2+1][y1] - psum[x1][y2+1] + psum[x1][y1];
    }
};

long long compute(vector<vector<long long>> v, int n) {
    Sums sums(v);
    long long top = 0;
    for (int i = 0; i < n; i++)
        top += i * v[0][i];
    for (int i = 0; i < n; i++)
        top += (n + i) * v[1][n-1-i];


    long long best = 0;
    int idx = 0;
    for (int i = 0; i < n; i+=2) {
        best = max(best, top);
        top -= idx*v[0][i];
        top -= (idx+1)*v[0][i+1];
        top -= (2*n-1)*v[1][i];
        top -= (2*n-2)*v[1][i+1];
        top += sums.sum(0, i+2, 1, n-1) * 2;
        top += idx*v[0][i];
        top += (idx+1)*v[1][i];
        top += (idx+2)*v[1][i+1];
        top += (idx+3)*v[0][i+1];
        idx += 4;
    }
    return best;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 0 1 2 3 4
    // 9 8 7 6 5
    //
    // . . 4 5 6
    // . . 9 8 7
    
    int n;
    cin >> n;
    vector<vector<long long>> v(2, vector<long long>(n + 2, 0));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    
    long long best = compute(v, n);
    long long other = Sums(v).sum(0, 1, 1, n-1) * 2 + v[1][0];
    for (auto& vv : v)
        vv.erase(vv.begin());
    swap(v[0], v[1]);
    best = max(best, other + compute(v, n-1));
    cout << best << '\n';
}