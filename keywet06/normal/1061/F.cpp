#include <bits/stdc++.h>

using namespace std;

static const uint64_t seed =
    std::chrono::steady_clock::now().time_since_epoch().count();
uint64_t now = seed;

static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

uint64_t rand_ull() {
    now = splitmix64(now);
    return now;
}

bool on_path(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    string s;
    cin >> s;
    return s[0] == 'Y';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, K;
    cin >> n >> K;
    int depth = 0;
    for (int sum = 0, now = 1; sum < n; sum += now, now = now * K, depth++)
        ;
    int x, y;
    vector<int> a;
    while (true) {
        x = rand_ull() % n + 1;
        y = rand_ull() % n + 1;
        a.clear();
        for (int i = 1; i <= n; i++) {
            if (i != x && i != y && on_path(x, i, y)) {
                a.push_back(i);
            }
        }
        if (a.size() + 2 == depth * 2 - 1) break;
    }
    for (int i = 0; i < (a.size() + 1) / 2; i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (on_path(x, a[j], a[i])) {
                swap(a[i], a[j]);
            }
        }
    }
    cout << "! " << a[(a.size() - 1) / 2] << endl;
    return 0;
}