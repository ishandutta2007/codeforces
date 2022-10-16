#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    vector<ll> d(n);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    ll x = d.back();
    ll y = 1;
    for(int i = 1; i < d.size(); i++) {
        //cout << i << endl;
        if(d[i] == d[i - 1]) {
            y = d[i];
            continue;
        }
        if(x % d[i] != 0) y = d[i];
    }
    cout << x << " " << y << endl;
    return 0;
}