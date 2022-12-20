#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

void bad() {
    cout << "NO" << endl;
    exit(0);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    pii last = mp(0, 0);
    int n;
    cin >> n;
    ll out = 1;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        ll comp = min(a, b) - max(last.first, last.second) + 1;
        if (last.first == last.second) comp--;
        out += max((ll)0, comp);
        last = mp(a, b);
    }
    cout << out << endl;
}