#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s;
    cin >> t;
    t += '$';
    t += s;
    vector<int> z(n + m + 1, 0);
    int le = -1, ri = -1;
    for(int i = 1; i < z.size(); ++i){
        if(i <= ri){
            z[i] = min(z[i - le], ri - i + 1);
        }
        while(i + z[i] < z.size() && t[i + z[i]] == t[z[i]]) {
            ++z[i];
        }
        if(i + z[i] - 1 > ri){
            le = i;
            ri = i + z[i] - 1;
        }
    }
    z[m] = 0;
    for(int i = m + 1; i < z.size(); ++i){
        if(z[i] == m){
            z[i] = 1;
        }else{
            z[i] = 0;
        }
        if(i > m + 1){
            z[i] += z[i - 1];
        }
    }
    int l, r;
    for(int i = 0; i < q; ++i){
        cin >> l >> r;
        l += m - 1;
        r += 1;
        if(r > l) {
            cout << z[r] - z[l] << endl;
        }else{
            cout << 0 << endl;
        }
    }

}