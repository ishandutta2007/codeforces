#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int g, t;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'G'){
            g = i;
        }
        if(s[i] == 'T'){
            t = i;
        }
    }
    if(g > t){
        swap(g, t);
    }
    if((t - g) % k != 0) {
        cout << "NO" << endl;
        return 0;
    }
    for(int i = g; i < t; i += k){
        if(s[i] == '#'){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}