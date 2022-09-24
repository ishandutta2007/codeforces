#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = (int)1.01e9;
const int N = 1 << 20;

char buf[N];

void upd(int &x, int y) {
    x = max(x, y);
}

pair<int, int> fast(string s) {
    int n = s.length();

    vector<int> pac;
    vector<int> eat;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') pac.push_back(i); 
        if (s[i] == '*') eat.push_back(i); 
    }


    if (pac.size() == 1) {
        int id = lower_bound(eat.begin(), eat.end(), pac[0]) - eat.begin();
        pair<int, int> left = make_pair(-id, pac[0] - eat[0]);
        pair<int, int> right = make_pair(-((int)eat.size() - id), eat.back() - pac[0]);
        return min(left, right);
    }

    int k = pac.size();
    int m = eat.size();
    eat.push_back(INF);


    int L = 0, R = 1e7;
    while (R - L > 1) {
        int M = (L + R) >> 1;
        
        vector<int> lb(k);
        for (int i = 0; i < k; i++) {
            if (i) lb[i] = lb[i - 1];
            while (eat[lb[i]] - pac[i] <= M) lb[i]++;
        }
        vector<int> lb2(k);
        for (int i = 0; i < k; i++) {
            if (i) lb2[i] = lb2[i - 1];
            while (eat[lb2[i]] - pac[i] <= 0) lb2[i]++;
        }

        //vector<int> dp(k + 1, 0);
        vector<vector<int> > dp(k + 1, vector<int>(2, -1));
        dp[0][1] = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 2; j++) {
                if (dp[i][j] == -1) continue;

                // fwd
                if (eat[dp[i][j]] > pac[i]) {
                    upd(dp[i + 1][0], lb[i]);
                } else {
                    upd(dp[i + 1][0], dp[i][j]);
                }

                // bckwd
                if (eat[dp[i][j]] < pac[i] && pac[i] - eat[dp[i][j]] <= M) {
                    if (i > 0 && eat[dp[i][j]] < pac[i - 1] && j == 0) {
                        upd(dp[i + 1][1], lb[i - 1]); 
                    } else {
                        upd(dp[i + 1][1], lb2[i]); 
                    }
                }
            }
        }
        if (dp[k][0] == m || dp[k][1] == m) R = M;
        else L = M;
    }
    return make_pair(-(int)eat.size() + 1, R);
}

pair<int, int> slow(string s) {
    int n = s.length();

    vector<int> pac;
    vector<int> eat;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') pac.push_back(i); 
        if (s[i] == '*') eat.push_back(i); 
    }

    int k = pac.size();
    int m = eat.size();
    pair<int, int> ans = {0, 0};
    for (int mask = 0; mask < (1 << k); mask++) {
        vector<int> cur(m, INF);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                if (!(mask & (1 << i)) == (pac[i] - eat[j] < 0)) {
                    cur[j] = min(cur[j], abs(pac[i] - eat[j]));
                }
            }
        }
        int cnt = 0, mx = -1;
        for (int i = 0; i < m; i++) {
            if (cur[i] == INF) continue;
            cnt++;
            mx = max(mx, cur[i]);
        }
        ans = min(ans, {-cnt, mx});
    }
    return ans;
}

void stress() {
    for (int it = 103;; it++) {
        cerr << it << endl;
        srand(it);

        int n = rand() % 10 + 1;
        string s = "";
        for (int i = 0; i < n; i++) s += "*P."[rand() % 3];

        if (s.find('*') == -1) continue;
        if (s.find('P') == -1) continue;

        auto ans1 = fast(s);
        auto ans2 = slow(s);

        if (ans1 != ans2) {
            cout << -ans1.first << " " << ans1.second << "  instead of  " << -ans2.first << " " << ans2.second << endl;
            cout << s << endl;
            exit(0);
        }
    }
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    //stress();

    int n;
    while (scanf("%d", &n) == 1) {
        scanf("%s", buf);

        auto o = fast(buf);
        cout << -o.first << " " << o.second << endl;
    }
    
    return 0;
}