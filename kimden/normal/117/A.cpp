#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int q;

int to(int t, int rem){
    rem %= q;
    if(t % q > rem){
        return t + q + rem - (t % q);
    }
    return t + rem - (t % q);
}

int go(int t, int floor){
    return min(to(t, floor), to(t, q - floor));
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    q = 2 * m - 2;
    int s, f, t;
    for(int i = 0; i < n; ++i){
        cin >> s >> f >> t;
        if(s == f){
            cout << t << endl;
            continue;
        }
        --s;
        --f;
        t = go(t, s);
        t = go(t, f);
        cout << t << endl;
    }
}