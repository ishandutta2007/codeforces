#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
using namespace std;

vector<int> solve(int l, int r, bool done = false, int x = 0, int f = 0) {
    if (r == l - 1) {
        vector<int> res;
        return res;
    }
    
    if (!done) {
        cout << "? " << l << " " << r << "\n";
        cout.flush();
        cin >> x >> f;
    }

    // check if full
    if (f == r - l + 1) {
        vector<int> res(r - l + 1, x);
        return res;
    }

    if (r == l + 1) {
        cout << "? " << r << " " << r << "\n";
        cout.flush();
        int y, fy;
        cin >> y >> fy;
        vector<int> res(2);
        res[0] = x, res[1] = y;
        return res;
    }

    int mid = (r + l - 1) / 2;
    cout << "? " << l << " " << mid << "\n";
    cout.flush();
    int y, fy;
    cin >> y >> fy;

    // check if this part full
    if (fy == mid - l + 1) {
        if (x == y) {
            auto resR = solve(l + f, r);
            vector<int> res(r - l + 1, x);
            for (int i = 0; i < r - l - f + 1; i++) {
                res[i + f] = resR[i];
            }
            return res;
        }

        // we now know that x != y
        if (f + fy == r - l + 1) {
            vector<int> res(r - l + 1, x);
            for (int i = 0; i < fy; i++) {
                res[i] = y;
            }
            return res;
        }

        // we now also know that f + fy < n
        cout << "? " << mid + 1 << " " << mid + 1 << "\n";
        cout.flush();
        int z, fz;
        cin >> z >> fz;
        if (z != x && z != y) {
            vector<int> res(r - l + 1, x);
            for (int i = 0; i < fy; i++) res[i] = y;
            res[fy] = z;
            return res;
        }
        cout << "? " << r << " " << r << "\n";
        cout.flush();
        cin >> z >> fz;
        vector<int> res(r - l + 1, x);
        for (int i = 0; i < fy; i++) res[i] = y;
        res[r - l] = z;
        return res;
    }

    // now first part is not full
    if (x == y) {
        if (f != fy) {
            auto resL = solve(l, mid - fy);
            auto resR = solve(mid + f - fy + 1, r);
            vector<int> res;
            for (auto elemL : resL) res.push_back(elemL);
            for (int i = 0; i < f; i++) res.push_back(x);
            for (auto elemR : resR) res.push_back(elemR);
            return res;
        }

        cout << "? " << mid + 1 << " " << r << "\n";
        cout.flush();
        int z, fz;
        cin >> z >> fz;
        // cannot be full
        auto resL = solve(l, mid, true, y, fy);
        auto resR = solve(mid + 1, r, true, z, fz);
        vector<int> res;
        for (auto elemL : resL) res.push_back(elemL);
        for (auto elemR : resR) res.push_back(elemR);
        return res;
    }

    // now x != y
    if (f + fy == r - l + 1) {
        vector<int> res(r - l + 1, x);
        for (int i = 0; i < fy; i++) res[i] = y;
        return res;
    }

    cout << "? " << mid + 1 << " " << r << "\n";
    cout.flush();
    int z, fz;
    cin >> z >> fz;
    if (fz == r - mid) {
        // we know that x == z
        auto resL = solve(l, r - f, true, y, fy);
        for (int i = 0; i < f; i++) resL.push_back(x);
        return resL;
    }

    // second part not full either, can do recursive
    auto resL = solve(l, mid, true, y, fy);
    auto resR = solve(mid + 1, r, true, z, fz);
    vector<int> res;
    for (auto elemL : resL) res.push_back(elemL);
    for (auto elemR : resR) res.push_back(elemR);
    return res;
}

int main(void) {
    int n;
    cin >> n;
    auto res = solve(1, n);
    cout << "!";
    for (auto x : res) cout << " " << x;
    cout << "\n";
    cout.flush();
}