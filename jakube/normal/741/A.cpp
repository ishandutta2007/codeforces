#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    
    return gcd(b, a%b);
}


long long lcm(long long a, long long b) {
    return a*b/gcd(a, b);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n;  idx++) 
    {
        cin >> v[idx];
        v[idx]--;
    }
    
    vector<int> t;
    long long g = 1;

    for (int i = 0; i < n; i++) {
        int j = i;
        int c = 0;
        vector<bool> b(n, false);
        while (!b[j]) {
            b[j] = true;
            c++;
            j = v[j];

        }

        if (i != j) 
        {
            cout << -1 << endl;
            return 0;
        }

        // cout << c << endl;
        if (c % 2 == 0)
            g = lcm(g, c/2);
        else
            g = lcm(g, c);
    }

    cout << g << endl;


    return 0;
}