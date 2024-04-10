#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int amax = 1010;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    int n, x;
    cin >> n >> x;

    vector<int> cnt(amax);

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        if (l > r) {
            swap(l, r);
        }
        for (int j = l; j <= r; ++j) {
            ++cnt[j];
        }
    }

    int ans = 100500;

    for (int pos = 0; pos < amax; ++pos) {
        if (cnt[pos] == n) {
            ans = min(ans, abs(x - pos));
        }
    }

    cout << (ans == 100500 ? -1 : ans) << "\n";

}