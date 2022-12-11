#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }

    cin >> m;
    vector<int> b(m), c(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    int cnt1 = -1, cnt2 = -1, ans = -1;
    for (int i = 0; i < m; ++i) {
        int a1 = cnt[b[i]], a2 = cnt[c[i]];
        if (a1 > cnt1) {
            cnt1 = a1, cnt2 = a2, ans = i;
        } else if (a1 == cnt1 && a2 > cnt2) {
            cnt2 = a2, ans = i;
        }
    }

    cout << ans + 1 << "\n";

}