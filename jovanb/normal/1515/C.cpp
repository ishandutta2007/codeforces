#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll a[100005];

void solve(){
    int n, m, x;
    cin >> n >> m >> x;
    for(int i=1; i<=n; i++) cin >> a[i];
    cout << "YES\n";
    set <pair <ll, int>> q;
    for(int i=1; i<=m; i++){
        q.insert({0, i});
    }
    for(int i=1; i<=n; i++){
        auto c = *q.begin();
        q.erase(q.begin());
        cout << c.second << " ";
        c.first += a[i];
        q.insert(c);
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
	cout.precision(10);
	cout << fixed;

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}