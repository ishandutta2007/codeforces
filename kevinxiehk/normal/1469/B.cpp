#include <bits/stdc++.h>
using namespace std;
 
int t; //number of test cases
int n;
int r[205];
int m;
int b[205];
int ansn;
int ansm;
int i; //the dumb integer angin only helpful for searching
int _;

int main () {
    
    cin >> t;
    for (_ = 1; _ <= t; _++) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> r[i];
        }
        cin >> m;
        for (i = 1; i <= m; i++) {
            cin >> b[i];
        }
        ansn = 0;
        for (i = 1; i <= n; i++) {
            r[i] += r[i - 1];
            ansn = max(ansn, r[i]);
        }
        ansm = 0;
        for (i = 1; i <= m; i++) {
            b[i] += b[i - 1];
            ansm = max(ansm, b[i]);
        }
        cout << ansn + ansm << endl;
    }
}