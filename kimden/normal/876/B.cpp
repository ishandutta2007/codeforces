#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n, k, m;
    cin >> n >> k >> m;
    int x;
    vector<multiset<int>> v(m);
    for(int i = 0; i < n; ++i){
        cin >> x;
        v[x % m].insert(x);
    }
    for(int i = 0; i < m; ++i){
        if(v[i].size() >= k){
            cout << "Yes" << endl;
            int cnt = 0;
            for(auto u: v[i]){
                cout << u;
                if(++cnt == k){
                    break;
                }
                cout << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;


}