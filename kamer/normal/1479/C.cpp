#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

vector<tuple<int, int, int>> construct(int k) {
    vector<tuple<int, int, int>> res;
    for (int i = k; i >= 1; i--) {
        res.emplace_back(i, k + 1, 1);
        int curr_pow = 1;
        for (int j = k; j > i; j--) {
            res.emplace_back(i, j, curr_pow);
            curr_pow *= 2;
        }
    }
    return res;
}

int find_pow(int R) {
    int pow = 0;
    while (R > 1) {
        R /= 2;
        pow++;
    }
    return pow;
}

int find_max_pow(int R) {
    int pow = 0;
    while ((1 << pow) <= R) pow++;
    pow--;
    return pow;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int L, R;
    cin >> L >> R;
    if (L == R) {
        cout << "YES\n";
        cout << "2 1\n1 2 " << L << "\n";
        return 0;
    }

    bool inc = false;
    int how_much = -1;
    if (L > 1) {
        inc = true;
        how_much = L - 1;
        L -= how_much;
        R -= how_much;
    }

    int k = find_pow(R - 1);
    k++;
    auto edges = construct(k);
    edges.emplace_back(0, k + 1, 1);

    L = 2;
    while (L <= R) {
        int pow = find_max_pow(R - L + 1);
        edges.emplace_back(0, k - pow, L - 1);
        L += (1 << pow);
    }

    cout << "YES\n";
    if (inc) {
        cout << k + 3 << " " << edges.size() + 1 << "\n";
        cout << "1 2 " << how_much << "\n";
    } else {
        cout << k + 2 << " " << edges.size() << "\n";
    }

    for (auto [x, y, c] : edges) {
        if (inc) {
            cout << x + 2 << " " << y + 2 << " " << c << "\n";
        } else {
            cout << x + 1 << " " << y + 1 << " " << c << "\n";
        }
    }

}