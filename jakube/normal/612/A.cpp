#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p >> q;

    string s;
    cin >> s;

    for (int c1 = 0; c1 <= n / p; c1++)
    {
        int c2 = (n - c1*p) / q;
        if (c1*p + c2*q == n)
        {
            cout << c1 + c2 << endl;
            for (int i = 0; i < c1; i++)
                cout << s.substr(i*p, p) << endl;
            for (int i = 0; i < c2; i++)
                cout << s.substr(c1*p + i*q, q) << endl;
            return 0;
        }
    }
    cout << -1;
}