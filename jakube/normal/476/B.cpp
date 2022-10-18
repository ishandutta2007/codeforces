#include <bits/stdc++.h>
using namespace std;

long long f(long long n) {
    long long r = 1;
    for (int i = 2; i <= n; i++)
        r *= i;
    return r;
}

long long nCr(long long n, long long k) {
    return f(n) / f(k) / f(n-k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    string a, b;
    cin >> a >> b;

    int t = 0;
    for (char c : a) {
        if (c == '+')
            t++;
        if (c == '-')
            t--;
    }
    int C = 0;
    for (char c : b) {
        if (c == '+')
            t--;
        if (c == '-')
            t++;
        if (c == '?')
            C++;
    }
    
    int plus = 0;
    int minus = 0;
    if (t > 0)
    {
        int tmp = C - t;
        if (tmp < 0)
        {
            cout << 0.0 << endl;
            return 0;
        }
        plus = t + tmp/2;
        minus = tmp/2;
    }
    else
    {
        int tmp = C + t;
        if (tmp < 0)
        {
            cout << 0.0 << endl;
            return 0;
        }
        plus = tmp/2;
        minus = tmp/2 + t;
    }


    cout << (double)nCr(C, plus) / pow(2.0, C) << endl;


        

    return 0;
}