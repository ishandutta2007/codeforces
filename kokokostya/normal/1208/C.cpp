#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <bitset>
#include <random>

typedef long long ll;

using namespace std;

bool check(const vector<vector<int>>& a) {
    int sum = 0;
    int n = (int)a.size();
    for (int i = 0; i < n; i++) {
        sum ^= a[0][i];
    }
    for (int i = 0; i < n; i++) {
        int res1 = 0;
        int res2 = 0;
        for (int j = 0; j < n; j++) {
            res1 ^= a[i][j];
            res2 ^= a[j][i];
        }
        if (res1 != sum || res2 != sum) {
            return false;
        }
    }
    return true;
}

void print(const vector<vector<int>>& a) {
    int n = (int)a.size();
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = 0;
            int ii = i;
            int jj = j;

            if (ii >= n / 2) {
                val += 2;
                ii -= n / 2;
            }
            if (jj >= n / 2) {
                val += 1;
                jj -= n / 2;
            }

            a[i][j] = (ii * (n / 2) + jj) * 4 + val;
        }
    }
    print(a);

    return 0;
}