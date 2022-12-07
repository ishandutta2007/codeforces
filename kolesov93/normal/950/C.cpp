#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

const int N = 200222;
char s[N];

int main() {
    gets(s);
    int n = strlen(s);

    int balance = 0;
    int max_balance = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') ++balance;
        else --balance;

        if (balance < 0) {
            puts("-1");
            return 0;
        }
        max_balance = max(max_balance, balance);
    }
    if (balance <= 0 || balance < max_balance) {
        puts("-1");
        return 0;
    }

    vector<vector<int>> ans(balance);
    queue<int> wants[2];
    for (int i = 0; i < balance; ++i) {
        wants[0].push(i);
    }
    for (int i = 0; i < n; ++i) {
        int who = wants[s[i] - '0'].front();
        wants[s[i] - '0'].pop();

        ans[who].push_back(i + 1);
        wants[1 - s[i] + '0'].push(who);
    }

    printf("%d\n", static_cast<int>(ans.size()));
    for (auto&& row : ans) {
        printf("%d", static_cast<int>(row.size()));
        for (int x : row) {
            printf(" %d", x);
        }
        puts("");
    }

    return 0;
}