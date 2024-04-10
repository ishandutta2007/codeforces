#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    int n;
    cin >> n;
    vector<int> v;
    v.resize(n);
    int mx = -1;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    bool flag = false;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if (v[i] == mx) {
            flag = true;
            ++cnt;
        }
        if (i == 0) {
            continue;
        }
        if (!flag && v[i] <= v[i - 1]) {
            cout << "NO" << endl;
            return 0;
        }
        if(flag){
            if(v[i] < v[i - 1] || (v[i] == v[i - 1] && v[i] == mx) || (cnt == 1 && v[i] == mx)){

            }else{
                cout << "NO" << endl;
                return 0;
            }
        }
    }
   /* if(cnt == 1){
        cout << "NO" << endl;
        return 0;
    }*/
    cout << "YES" << endl;



    return 0;
}