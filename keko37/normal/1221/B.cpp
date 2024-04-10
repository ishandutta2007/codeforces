#include<bits/stdc++.h>

using namespace std;

int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ((i + j) & 1) cout << 'W'; else cout << 'B';
        }
        cout << endl;
    }
    return 0;
}