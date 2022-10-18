#include <bits/stdc++.h>
using namespace std;

struct S
{
    int l, r;
};

class MinQueue {
public:
    MinQueue(int capacity = 1'000'000'000) : capacity(capacity) {}

    int min() {
        return dq.front().first;
    }

    void add(int elem) {
        while (!dq.empty() && dq.back().first > elem) {
            dq.pop_back();
        }
        dq.push_back({elem, added});
        added++;
        if (added - removed > capacity)
            remove();
    }

    void remove() {
        if (!dq.empty() && dq.front().second == removed)
            dq.pop_front();
        removed++;
    }

private:
    deque<pair<int, int>> dq;
    int added = 0;
    int removed = 0;
    int capacity;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<S> p;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        p.push_back({l, r});
    }
    if (p.back().r != 2*n) {
        p.push_back({2*n, 2*n});
        k++;
    }
    
    vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(n + 1, vector<int>(2, 300)));
    dp[0][0][0] = {0};
    for (int i = 0; i < k; i++) {
        int l = p[i].l;
        int r = p[i].r;
        int len = r - l;
        int dist = r - (i ? p[i-1].r : 0);

        MinQueue mq0(len+1), mq1(len+1), mq2(len+1), mq3(len+1);
        for (int v = 0; v <= n; v++) {
            int& a = dp[i+1][v][0];
            int& b = dp[i+1][v][1];

            // no switch
            if (v - dist >= 0)
                a = dp[i][v-dist][0];
            b = dp[i][v][1];
            
            // one switch
            mq0.add(dp[i][v][1]);
            a = min(a, mq0.min() + 1);

            if (v - dist + len >= 0) {
                mq1.add(dp[i][v-dist+len][0]);
                b = min(b, mq1.min() + 1);
            }

            // two switches
            if (v - dist + len >= 0) {
                mq2.add(dp[i][v-dist+len][0]);
                a = min(a, mq2.min() + 2);
            }

            mq3.add(dp[i][v][1]);
            b = min(b, mq3.min() + 2);
        }
    }

    int res = min(dp[k][n][0], dp[k][n][1]);
    if (res >= 300)
        cout << "Hungry" << endl;
    else 
        cout << "Full" << endl << res << endl;
}