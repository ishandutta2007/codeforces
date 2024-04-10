#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

bool b[1000002];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    for(int i = 0; i < m; ++i){
        cin >> x;
        b[--x] = true;
    }

    int cur = 0;
    if(b[cur]){
        cout << cur + 1 << endl;
        return 0;
    }
    for(int i = 0; i < k; ++i){
        cin >> x >> y;
        x--;
        y--;
        if(cur == x){
            cur = y;
        }else if(cur == y){
            cur = x;
        }
        if(b[cur]){
            cout << cur + 1 << endl;
            return 0;
        }
    }
    cout << cur + 1 << endl;
    return 0;
}