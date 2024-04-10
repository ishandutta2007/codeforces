#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    vector<int> c(5, 0);
    for (int i : v) c[i]++;

    if (c[3] > c[1]) 
    {
        cout << c[4] + c[3] + (c[2] + 1)/2 << endl;
    }
    else 
    {
        int a = c[1] - c[3];
        int b = c[2];

        if (b % 2 == 1)
            a+=2;

        cout << (a + 3) / 4 + b / 2 + c[3] + c[4] << endl;
    }




    return 0;
}