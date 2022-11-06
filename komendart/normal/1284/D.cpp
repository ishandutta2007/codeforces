#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <chrono>
#include <random>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

struct Segment {
    int id, left, right;
};

int n;
vector<int> xorval;

vector<int> solve(vector<Segment> segs) {
    vector<int> xs;
    for (auto seg: segs) {
        xs.push_back(seg.left);
        xs.push_back(seg.right);
    }
    sort(begin(xs), end(xs));
    for (auto &seg: segs) {
        seg.left = lower_bound(begin(xs), end(xs), seg.left) - begin(xs) + 1;
        seg.right = lower_bound(begin(xs), end(xs), seg.right) - begin(xs) + 1;
    }
    vector<int> prefleft(sz(xs) + 2);
    vector<int> prefright(sz(xs) + 2);
    for (auto seg: segs) {
        prefleft[seg.left] ^= xorval[seg.id];
        prefright[seg.right] ^= xorval[seg.id];
    }
    for (int i = 1; i < sz(prefleft); ++i) {
        prefleft[i] ^= prefleft[i - 1];
        prefright[i] ^= prefright[i - 1];
    }
    vector<int> ans(n);
    for (auto seg: segs) {
        ans[seg.id] = prefleft[seg.right] ^ prefright[seg.left - 1];
    }
    return ans;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dis(1, (int) 1e18);
    
    cin >> n;
    xorval.resize(n);
    for (int i = 0; i < n; ++i) {
        xorval[i] = dis(gen);
    }
    vector<Segment> a(n);
    vector<Segment> b(n);
    for (int i = 0; i < n; ++i) {
        a[i].id = b[i].id = i;
        cin >> a[i].left >> a[i].right;
        cin >> b[i].left >> b[i].right;
    }
    vector<int> first = solve(a);
    vector<int> second = solve(b);
    if (first == second) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}