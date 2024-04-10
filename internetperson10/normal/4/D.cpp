#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll MOD = (ll)1000000007;
vector<pair<pair<int, int>, int>> env;
vector<vector<int>> dp(5000);
vector<int> answers(5000, -1);
vector<int> ans;

bool contains(pair<int, int> p1, pair<int, int> p2) {
    return ((p1.first > p2.first) && (p1.second > p2.second));
}

vector<int> dep(int i, pair<int, int> c) {
    vector<int> v(0);
    if(!contains(env[i].first, c)) {
        answers[i] = 0;
        return dp[i] = v;
    }
    if(answers[i] > -1) return dp[i];
    v.push_back(env[i].second);
    int ans = 0, n = -1;
    for(int j = 0; j < i; j++) {
        if(contains(env[i].first, env[j].first)) {
            // cout << "Putting " << j << " in " << i << '\n';
            int x = answers[j];
            if(ans < x) {
                ans = x;
                n = j;
            }
        }
    }
    // cout << "Answer to " << i << " is " << ans+1 << '\n';
    answers[i] = ans+1;
    if(n == -1) return dp[i] = v;
    v = dp[n];
    v.push_back(env[i].second);
    return dp[i] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m, n;
    pair<int, int> card;
    ll k;
    string s1, s2;
    bool sad = false;
    cin >> n >> card.first >> card.second;
    env.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> env[i].first.first >> env[i].first.second;
        env[i].second = i+1;
    }
    sort(env.begin(), env.end());
    // for(int i = 0; i < n; i++) cout << env[i].first.first << ' ' << env[i].first.second << '\n';
    for(int i = 0; i < n; i++) {
        int x = dep(i, card).size();
        if(ans.size() < x) ans = dp[i];
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
}