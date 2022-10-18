#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    
    int all = 4*60 - k;

    int i = 0;
    for (;; i++) {
        if (all >= 5*(i+1)) {
            all -= 5*(i+1);
        }
        else 
            break;
    }

    cout << min(i, n) << endl;
    

    return 0;
}