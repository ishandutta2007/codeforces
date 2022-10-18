#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int cnt = 0; 
    int x = n;
    for (int i = n-1; i >= 0; i--) {
        if (i < x)
            cnt++;
        x = min(x, i - v[i]);
    }
    cout << cnt << endl;
}