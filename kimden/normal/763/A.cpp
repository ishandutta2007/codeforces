#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n;
    cin >> n;
    vector<int> v, u;
    vector<int> c(n);
    int a, b;
    for(int i = 0; i < n - 1; ++i){
        cin >> a >> b;
        --a;
        --b;
        v.push_back(a);
        u.push_back(b);
    }
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    vector<int> cnt(n, 0);
    int val = 0;
    for(int i = 0; i < n - 1; ++i){
        if(c[u[i]] != c[v[i]]){
            ++cnt[u[i]];
            ++cnt[v[i]];
            ++val;
        }
    }
    for(int i = 0; i < n; ++i){
        if(cnt[i] == val){
            cout << "YES\n" << i + 1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;

}