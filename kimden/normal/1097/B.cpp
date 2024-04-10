#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> v(360 * 15 + 9, 0);
    v[0] = 1;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        for(int j = (int)v.size() - 1; j >= 0; --j){
            if ((j - a[i] >= 0 && v[j - a[i]]) || (j - 360 + a[i] >= 0 && v[j - 360 + a[i]])) {
                v[j] = 1;
            }else {
                v[j] = 0;
            }
        }
    }
    for(int i = 0; i < v.size(); i += 360) {
        if(v[i]) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;

}