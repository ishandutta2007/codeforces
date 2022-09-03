#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <utility>
#include <vector>
using namespace std;

int q(int u, int v, int w) {
    cout << "? " << u + 1 << ' ' << v + 1 << ' ' << w + 1 << endl;
    int ret;
    cin >> ret;
    return ret - 1;
}

int main()
{
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int H;
    cin >> H;
    const int N = (1 << H) - 1;

    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> d(0, N - 1);

    vector<pair<int, int>> cnt;
    for (int i = 0; i < N; i++) {
        cnt.emplace_back(0, i);
    }
    for (int t = 0; t < 420; t++) {
        int a = d(mt), b = d(mt), c = d(mt);
        while (b == a) {
            b = d(mt);
        }
        while (c == a or c == b) {
            c = d(mt);
        }
        cnt[q(a, b, c)].first++;
    }
    sort(cnt.rbegin(), cnt.rend());
    const int s = cnt[0].second, t = cnt[1].second;
    for (int i = 0; i < N; i++) {
        if (i != s and i != t and q(s, t, i) == i) {
            cout << "! " << i + 1 << endl;
            return 0;
        }
    }
}