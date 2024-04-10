#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> v;
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        v.push_back(s.length());
    }
    cin >> s;
    int l = s.length();
    sort(v.begin(), v.end());
    int mn, mx, tm = 0;
    for(int i = 0; i < n; ++i){
        ++tm;
        if(i > 0 && i % k == 0){
            tm += 5;
        }
        if(v[i] == l && (i == 0 || v[i - 1] < l)){
            mn = tm;
        }
        if(v[i] == l && (i == n - 1 || v[i + 1] > l)){
            mx = tm;
        }
    }
    cout << mn << " " << mx << endl;
}