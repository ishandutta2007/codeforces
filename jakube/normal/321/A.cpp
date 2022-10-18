#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long a, b;
    cin >> a >> b;
    
    string s;
    cin >> s;

    int n = s.size();
    vector<pair<long long, long long>> psum(n+1);
    psum[0] = {0, 0};

    map<char, int> x_dir = {{'R', 1}, {'L', -1}, {'U', 0}, {'D', 0}};
    map<char, int> y_dir = {{'R', 0}, {'L', 0}, {'U', 1}, {'D', -1}};
    for (int i = 0; i < n; i++) {
        psum[i+1] = {psum[i].first + x_dir[s[i]], psum[i].second + y_dir[s[i]]};
    }

    for (int i = 0; i < n; i++) {
        if (psum.back().first != 0) {
            if ((a - psum[i].first) % psum.back().first == 0) {
                long long t = (a - psum[i].first) / psum.back().first;
                if (t >= 0 && psum[i].second + t * psum.back().second == b) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        } else if (psum.back().second != 0) {
            if ((b - psum[i].second) % psum.back().second == 0) {
                long long t = (b - psum[i].second) / psum.back().second;
                if (t >= 0 && psum[i].first + t * psum.back().first == a) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        } else {
            if (psum[i].first == a && psum[i].second == b) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }


    cout << "No" << endl;
    return 0;
}