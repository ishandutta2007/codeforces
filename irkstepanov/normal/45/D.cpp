#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct datum {
    int lf, rg;
    int id;
    bool operator<(const datum& other) const {
        return tie(lf, rg) < tie(other.lf, other.rg);
    }
};

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<datum> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].lf >> a[i].rg;
        a[i].id = i;
    }
    sort(all(a));

    vector<int> ans(n, -1);
    vector<int> curr(n);
    int day = 1;

    for (int i = 0; i < n; ++i) {
        day = max(day, a[i].lf);
        for (int j = 0; j < n; ++j) {
            if (ans[a[j].id] != -1) {
                continue;
            }
            if (a[j].lf <= day && a[j].rg >= day) {
                curr[a[j].id] = a[j].rg - day + 1;
            } else {
                curr[a[j].id] = 0;
            }
        }
        int opt = -1;
        for (int j = 0; j < n; ++j) {
            if (ans[a[j].id] != -1 || curr[a[j].id] == 0) {
                continue;
            }
            if (opt == -1 || curr[a[j].id] < curr[opt]) {
                opt = a[j].id;
            }
        }
        //cout << "!" << opt << " " << curr[opt] << endl;
        ans[opt] = day;
        ++day;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}