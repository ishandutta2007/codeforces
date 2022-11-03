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
    int x;
    vector<int> a(n), b(m);
    vector<vector<int>> c(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int j = 0; j < m; ++j) {
        cin >> b[j];
    }
    for(int bit = (1 << 30); bit; bit >>= 1){
        vector<int> v, w;
        for(int i = 0; i < n; ++i){
            if(a[i] & bit){
                v.push_back(i);
            }
        }
        for(int i = 0; i < m; ++i){
            if(b[i] & bit){
                w.push_back(i);
            }
        }
        if((w.size() + v.size()) % 2 == 1){
            cout << "NO" << endl;
            return 0;
        }
        for(int i = 0; i < min(v.size(), w.size()); ++i){
            c[v[i]][w[i]] ^= bit;
        }
        for(int i = min(v.size(), w.size()); i < w.size(); ++i){
            c[0][w[i]] ^= bit;
        }
        for(int i = min(v.size(), w.size()); i < v.size(); ++i){
            c[v[i]][0] ^= bit;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(j){
                cout <<  " ";
            }
            cout << c[i][j];
        }
        cout << endl;
    }

}