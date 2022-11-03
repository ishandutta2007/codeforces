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
    int k;
    vector<int> v(12);
    cin >> k;
    for(int i = 0; i < 12; ++i){
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    int sum = 0;
    if(sum >= k){
        cout << "0\n";
        return 0;
    }
    for(int i = 0; i < 12; ++i){
        sum += v[i];
        if(sum >= k){
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}