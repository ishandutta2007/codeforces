#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int k;
    cin >> k;
    
    vector<int> d;
    while (k)
    {
        d.push_back(k%10);
        k /= 10;
    }

    cout << *max_element(d.begin(), d.end()) << endl;
    for (int i = 0; i < 10; i++) {
        bool b = 0;
        for (auto rit = d.rbegin(); rit != d.rend(); ++rit) {
            if (!b && *rit > i) b = true; 
            if (b && *rit > i) cout << 1;
            if (b && *rit <= i) cout << 0;
        }
        cout << " ";
    }
    cout << endl;

    return 0;
}