#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> possible = { 
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
        31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 
    };

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    for (int start = 0; start < (int)possible.size() - n; start++) {
        bool b = true;
        for (int x = start; x < start + n; x++) {
            b &= possible[x] == v[x - start];
        }
        if (b) {
            cout << "Yes" << '\n';
            cout << '\n';
            
            return 0;
        }
    }
    cout << "No" << '\n';
    cout << '\n';
}