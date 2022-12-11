#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);

    set<int> used;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        if (used.count(b)) {
            cout << "0 ";
            continue;
        }
        int cnt = 0;
        while (a[ptr] != b) {
            used.insert(a[ptr]);
            ++cnt;
            ++ptr;
        }
        used.insert(b);
        ++ptr;
        ++cnt;
        cout << cnt << " ";
    }
    cout << "\n";

}