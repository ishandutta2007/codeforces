#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;

int s[N], top, tp1;
vector <int> ans;
bool use[N];

int main() {
    int i, j, k, n, l, r, q, a;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 1; i <= k; ++i) {
        cin >> a;
        ans.push_back(a);
        use[a] = 1;
        ++top;
        s[top] = a;
        if (top > 1 && s[top] > s[top - 1]) {
            cout << -1;
            return 0;
        }
        while (s[top] == tp1 + 1) {
            --top;
            ++tp1;
        }
    }
    s[0] = n + 1;
    for (i = top; i >= 0; --i) {
        j = s[i] - 1;
        while (j > 0 && !use[j]) {
            ans.push_back(j);
            --j;
        }
    }
    for (i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
}