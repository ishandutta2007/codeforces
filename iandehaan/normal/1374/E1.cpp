#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    

    vector<int> a;
    vector<int> b;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (y == 1 && z == 1) d.pb(x);
        else if (z == 1) b.pb(x);
        else if (y == 1) a.pb(x);
    }

    sort(begin(a), end(a));
    sort(begin(b), end(b));
    sort(begin(d), end(d));

    int mind = max((ll)0, k-min((ll)a.size(), (ll)b.size()));

    if (mind > d.size()) {
        cout << -1 << endl;
        return 0;
    }

    ll out = 0;
    for (int i = 0; i < mind; i++) out += d[i];

    for (int i = 0; i < min((ll)a.size(), min((ll)k, (ll)b.size())); i++) out += a[i] + b[i];

    //cout << out << ' ' << mind << endl;
    
    //cout << "here" << endl;

    ll o = out;

    for (int i =  min((ll)a.size(), min((ll)k, (ll)b.size()))-1; i >= 0; i--) {
        if (mind >= d.size()) break;
        //cout << i << ' ' << mind << endl;
        out -= a[i] + b[i];
        out += d[mind];
        o = min(out, o);
        mind++;
    }
    cout << o << endl;
    
}