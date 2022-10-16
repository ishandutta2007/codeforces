#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> il;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
string RGB = "RGB";
il dp[200500][3];

int main() {
    //cout.precision(10);
    int n;
    string s;
    vector<int> field;
    field.push_back(-1);
    cin >> n >> s;
    s = "#" + s;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            if(RGB[j] == s[i]) field.push_back(j);
        }
    }
    for(int i = 0; i < 3; i++) {
        dp[0][i] = {-1, 0};
    }
    for(int index = 1; index <= n; index++) {
        for(int now = 0; now < 3; now++) {
            dp[index][now] = {-1, 1e9};
            for(int before = 0; before < 3; before++) {
                if(now == before) continue;
                ll NEW = dp[index - 1][before].second;
                if(field[index] != now) NEW++;
                if(dp[index][now].second > NEW) {
                    dp[index][now] = {before, NEW};
                }
            }
        //cout << index << " " << now << " " << dp[index][now].first << " " << dp[index][now].second << endl;
        }
    }
    int ans_index = 0;
    for(int i = 1; i <= 2; i++) {
        if(dp[n][i].second < dp[n][ans_index].second) ans_index = i;
    }
    cout << dp[n][ans_index].second << endl;
    vector<char> ans(n);
    for(int i = n; i >= 1; i--) {
        //cout << i << " " << ans_index << endl;
        ans[i - 1] = RGB[ans_index];
        ans_index = dp[i][ans_index].first;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}