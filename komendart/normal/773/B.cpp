#include <bits/stdc++.h>

using namespace std;

bool check_points(const vector<int> &vasya, const vector<int> &petr, const vector<int> &points) {
    static const vector<int> cost = {500, 1000, 1500, 2000, 2500, 3000};
    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        if (vasya[i] != -1) {
            ans += cost[points[i]] * (250 - vasya[i]) / 250;
        }
    }
    for (int i = 0; i < 5; ++i) {
        if (petr[i] != -1) {
            ans -= cost[points[i]] * (250 - petr[i]) / 250;
        }
    }
    return ans > 0;
}

bool check_answer(int added, int n, const vector<int> &solved, const vector<int> &points, const vector<int> &vasya) {
    static vector<int> left(6), right(6);
    right[0] = added + n;
    for (int i = 1; i < 6; ++i) {
        right[i] = right[i - 1] / 2;
        left[i - 1] = right[i] + 1;
    }
    left[5] = 0;
    for (int i = 0; i < 5; ++i) {
        if (solved[i] > right[points[i]] || left[points[i]] > right[points[i]]) {
            return false;
        }
        if (vasya[i] == -1 && max(0, left[points[i]] - solved[i]) > 0) {
            return false;
        }
        if (max(0, left[points[i]] - solved[i]) > added) {
            return false;
        }
    }
    /*for (int i = 0; i < 6; ++i) {
        cerr << left[i] << ' ' << right[i] << endl;
    }
    for (int i = 0; i < 5; ++i) {
        cerr << solved[i] << ' ';
    } cerr << endl;
    for (int i = 0; i < 5; ++i) {
        cerr << points[i] << ' ';
    } cerr << endl;*/
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector< vector<int> > a(n, vector<int>(5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> solved(5);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (a[i][j] != -1) {
                ++solved[j];
            }
        }
    }

    vector<int> vasya = a[0];
    vector<int> petr = a[1];
    vector< vector<int> > good;
    for (int i = 0; i < 6; ++i) for (int j = 0; j < 6; ++j)
    for (int k = 0; k < 6; ++k) for (int l = 0; l < 6; ++l) for (int m = 0; m < 6; ++m) {
        vector<int> points = {i, j, k, l, m};
        if (check_points(vasya, petr, points)) {
            good.push_back(points);
        }
    }

    //long long ololo = 0;
    for (int added = 0; added <= 4000; ++added) {
        for (auto &points: good) {
            if (check_answer(added, n, solved, points, vasya)) {
                cout << added << '\n';
                return 0;
            }
        }
    }
    //cerr << ololo << endl;
    cout << -1 << '\n';
}