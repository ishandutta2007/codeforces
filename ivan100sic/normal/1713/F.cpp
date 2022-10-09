// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[500000];
int b[500000];

map<pair<int, int>, vector<int>> cache;

void triangle(int al, int ar, int* b) {
    if (ar-al == 1) {
        b[0] ^= a[al];
        return;
    }

    auto it = cache.find({al, ar});
    if (it != cache.end()) {
        for (int i : ra(0, ar-al)) {
            b[i] ^= it->second[i];
        }
        return;
    }

    int am = (ar+al) / 2;
    vector<int> bt(ar-al);
    triangle(al, am, bt.data());
    triangle(am, ar, bt.data() + am-al);
    
    for (int i : ra(0, am-al)) {
        bt[i] ^= bt[i + am-al];
    }

    for (int i : ra(0, ar-al)) {
        b[i] ^= bt[i];
    }

    if ((ar-al) >= 32) {
        cache[{al, ar}] = move(bt);
    }
}

void process(int al, int ar, int* b) {
    if (al == ar) {
        return;
    }

    int w = 1;
    while (2*w <= ar-al) {
        w *= 2;
    }

    int rest = ar-al-w;

    triangle(al, al+w, b+rest);

    vector<int> box(rest);

    process(al, al+rest, box.data());
    process(ar-rest, ar, box.data());

    for (int i : ra(0, rest)) {
        b[i] ^= box[i];
        b[i+w] ^= box[i];
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(0, n)) cin >> a[i];

    process(0, n, b);
    for (int i : ra(0, n)) cout << b[i] << " \n"[i == n-1];
}