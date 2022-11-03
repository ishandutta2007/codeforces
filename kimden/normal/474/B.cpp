#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);

    int n, m, x;
    cin >> n;
    vector<int> v(1000002, -1);
    int ptr = 0;
    for(int i = 0; i < n; ++i){
        cin >> x;
        while(x--){
            v[ptr++] = i;
        }
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> x;
        cout << v[x - 1] + 1 << endl;
    }
}