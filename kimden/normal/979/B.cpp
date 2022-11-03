#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> v(3);
    vector<int> a(3, 0);
    for(int i = 0; i < 3; ++i){
        cin >> v[i];
        map<char, int> mp;
        for(int j = 0; j < v[i].length(); ++j){
            ++mp[v[i][j]];
        }
        int mx = 0;
        for(auto p: mp){
            mx = max(mx, p.second);
        }
        if(mx == v[i].length() && n == 1 && mx > 1){
            a[i] = mx - 1;
        }else {
            a[i] = min<int>(v[i].length(), mx + n);
        }
    }
    if(a[0] > a[1] && a[0] > a[2]){
        cout << "Kuro" << endl;
        return 0;
    }
    if(a[1] > a[0] && a[1] > a[2]){
        cout << "Shiro" << endl;
        return 0;
    }
    if(a[2] > a[0] && a[2] > a[1]){
        cout << "Katie" << endl;
        return 0;
    }
    cout << "Draw" << endl;
}