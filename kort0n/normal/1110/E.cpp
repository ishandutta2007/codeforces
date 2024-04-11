#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    ll n;
    cin >> n;
    vector<ll> c(n);
    vector<ll> t(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    if(c[0] != t[0]) {
        cout << "No" << endl;
        return 0;
    }
    if(c[n - 1] != t[n - 1]) {
        cout << "No" << endl;
        return 0;
    }
    vector<ll> delta1, delta2;
    for(int i = 1; i < n; i++) {
        delta1.push_back(c[i] - c[i - 1]);
        delta2.push_back(t[i] - t[i - 1]);
    }
    sort(delta1.begin(), delta1.end());
    sort(delta2.begin(), delta2.end());
    for(int i = 0; i < n - 1; i++) {
        if(delta1[i] != delta2[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}