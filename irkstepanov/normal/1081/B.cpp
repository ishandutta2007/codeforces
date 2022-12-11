#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map<int, int> mapa;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = n - a[i];
        ++mapa[a[i]];
    }

    for (auto it : mapa) {
        if (it.second % it.first) {
            cout << "Impossible\n";
            return 0;
        }
    }

    cout << "Possible\n";
    map<int, int> ans;
    int iter = 1;
    for (int i = 0; i < n; ++i) {
        if (!ans.count(a[i])) {
            ans[a[i]] = iter++;
        }
        cout << ans[a[i]] << " ";
        --mapa[a[i]];
        if (mapa[a[i]] && mapa[a[i]] % a[i] == 0) {
            ans[a[i]] = iter++;
        }
    }

    cout << "\n";
    
}