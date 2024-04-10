#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    vector<int> res;
    for (int i = 1; n; i++) {
        if (i <= n)
        {
            res.push_back(i);
            n -= i;
        }
        else 
        {
            res.back() += n;
            n = 0;
        }
    }

    cout << res.size() << endl;
    for (int c : res)
        cout << c << " ";
    cout << endl;

    return 0;
}