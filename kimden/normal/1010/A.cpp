#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    ld x = m;

    if(b[0] == 1){
        cout << -1 << endl;
        return 0;
    }
    x /= (1 - 1. / b[0]);
    for(int i = n - 1; i >= 1; --i){
        if(a[i] == 1){
            cout << -1 << endl;
            return 0;
        }
        x /= (1 - 1. / a[i]);
        if(b[i] == 1){
            cout << -1 << endl;
            return 0;
        }
        x /= (1 - 1. / b[i]);
    }
    if(a[0] == 1){
        cout << -1 << endl;
        return 0;
    }
    x /= (1 - 1. / a[0]);
    x -= m;
    cout << setprecision(12) << fixed << x << endl;


    return 0;
}