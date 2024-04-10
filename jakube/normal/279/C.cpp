#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> increasing(n);
    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) 
            increasing[i] = n-1;
        else if (v[i] <= v[i+1])
            increasing[i] = increasing[i+1];
        else
            increasing[i] = i;
    }

    vector<int> decreasing(n);
    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) 
            decreasing[i] = n-1;
        else if (v[i] >= v[i+1])
            decreasing[i] = decreasing[i+1];
        else
            decreasing[i] = i;
    }


    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (decreasing[increasing[l]] >= r)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}