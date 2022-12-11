#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> nx(n, n);
    map<int, int> lst;
    for (int i = n - 1; i >= 0; --i) {
        if (lst.count(a[i])) {
            nx[i] = lst[a[i]];
        }
        lst[a[i]] = i;
    }

    ll sum = -n;
    ll curr = 0;
    for (int i = n - 1; i >= 0; --i) {
        curr -= (n - nx[i]);
        curr += (n - i);
        sum += ll(2) * curr;
    }

    ld res = ld(sum) / ld(n) / ld(n);
    cout << fixed;
    cout.precision(20);
    cout << res << "\n";

}