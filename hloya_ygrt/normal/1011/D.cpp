#include <bits/stdc++.h>

using namespace std;

int p[60];

int main() {
    int m, n;
    cin >> m >> n;
    
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        cout << 1 << endl;
        cnt += 1;
        int res;
        cin >> res;
        if (res == 0) {
            return 0;
        }
        if (res == -1) {
            p[i] = 0;
        } else {
            p[i] = 1;
        }
    }
    
    int i = 0;
    int l = 1, r = m;
    while (l < r) {
        int c = (l + r) >> 1;
        cout << c << endl;
        cnt += 1;
        
        int res;
        cin >> res;
        if (res == 0) {
            return 0;
        }
        
        if (cnt == 60) {
            assert(0);
        }
        
        if (p[i] == 0) {
            res = -res;
        }
        
        if (res == -1) {
            r = c - 1;
        } else {
            l = c + 1;
        }
        
        i++;
        i %= n;
    }
    
    assert(l == r);
    if (cnt == 60) {
        assert(0);
    }
    
    cout << l << endl;
    return 0;
}