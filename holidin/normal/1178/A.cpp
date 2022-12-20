#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 2e5 + 1;
vector <int> ans;
int a[N];

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int sum = 0, sumk = 0;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (i == 1 || a[1] / 2 >= a[i]) {
            sumk += a[i];
            ans.push_back(i);
        }
    }
    if (sumk > sum / 2) {
        cout << ans.size() << endl;
        for (i = 0; i < ans.size(); ++i)
            cout << ans[i] << ' ';
    } else
        cout << 0;

}