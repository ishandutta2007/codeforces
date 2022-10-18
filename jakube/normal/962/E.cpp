#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, char>> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i].first >> cities[i].second;
    }

    int INF = std::numeric_limits<int>::max();
    int min_b = INF;
    int min_r = INF;
    int min_p = INF;
    int max_b = -INF;
    int max_r = -INF;
    int max_p = -INF;
    for (int i = 0; i < n; i++) {
        if (cities[i].second == 'B') {
            min_b = min(min_b, cities[i].first);
            max_b = max(max_b, cities[i].first);
        } else if (cities[i].second == 'P') {
            min_p = min(min_p, cities[i].first);
            max_p = max(max_p, cities[i].first);
        } else {
            min_r = min(min_r, cities[i].first);
            max_r = max(max_r, cities[i].first);
        }
    }

    long long res = 0;
    if (min_p == INF) {
        if (min_b != INF)
            res += max_b - min_b;
        if (min_r != INF)
            res += max_r - min_r;
    } else {
        if (min_b != INF)
            res += max(0, min_p - min_b);
        if (min_r != INF)
            res += max(0, min_p - min_r);
        int idx = 0;
        while (cities[idx].second != 'P')
            idx++;
        long long last = cities[idx].first;
        idx++;

        while (idx < n && last < max_p) {
            vector<int> B, R;
            while (cities[idx].second != 'P') {
                if (cities[idx].second == 'B')
                    B.push_back(cities[idx].first);
                if (cities[idx].second == 'R')
                    R.push_back(cities[idx].first);
                idx++;
            }
            long long next = cities[idx].first;
            long long length = next - last;
            idx++;

            long long best = 2*length;
            long long best_R = length;
            long long best_B = length;
            if (!R.empty())
                best_R = min(next - R[0], R.back() - last);
            else
                best_R = 0;
            if (!B.empty())
                best_B = min(next - B[0], B.back() - last);
            else
                best_B = 0;
            for (int i = 1; i < (int)R.size(); i++) {
                best_R = min(best_R, R[i-1] - last + next - R[i]);
            }
            for (int i = 1; i < (int)B.size(); i++) {
                best_B = min(best_B, B[i-1] - last + next - B[i]);
            }
            best = min(best, best_R + best_B + length);
            res += best;

            last = next;
        }

        if (min_b != INF)
            res += max(0, max_b - max_p);
        if (min_r != INF)
            res += max(0, max_r - max_p);
    }

    cout << res << endl;
}