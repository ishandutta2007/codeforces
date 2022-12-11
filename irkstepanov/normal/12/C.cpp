#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    sort(all(cost));

    map<string, int> a;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        ++a[s];
    }

    vector<int> cnt;
    for (auto& it : a) {
        cnt.pb(it.second);
    }

    sort(all(cnt));

    int minn = 0;

    for (int i = 0, j = sz(cnt) - 1; j >= 0; ++i, --j) {
        minn += cnt[j] * cost[i];
    }

    cout << minn << " ";

    int maxx = 0;
    reverse(all(cost));

    for (int i = 0, j = sz(cnt) - 1; j >= 0; ++i, --j) {
        maxx += cnt[j] * cost[i];
    }
    cout << maxx << "\n";

}