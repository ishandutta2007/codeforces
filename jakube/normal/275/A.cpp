#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    vector<int> v(9);
    for (int idx = 0; idx < 9;  idx++)
        cin >> v[idx];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int c = 1;
            if (i)
                c += v[(i-1)*3+j];
            if (j)
                c += v[i*3+j-1];
            if (i<2)
                c += v[(i+1)*3+j];
            if (j<2)
                c += v[i*3+j+1];
            c += v[i*3+j];
            cout << c%2;
        }
        cout << endl;
    }

    return 0;
}