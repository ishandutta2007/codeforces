#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int g = 0;
    int n;
    cin >> n;
    vector<int> grundy = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        g ^= grundy[s];
    }
    
    cout << (g ? "NO" : "YES") << endl;
}