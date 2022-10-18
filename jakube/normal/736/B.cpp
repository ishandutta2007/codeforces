#include <bits/stdc++.h>
using namespace std;

int biggest(int n) {
    int m = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) 
            m = i;
    }
    return m;
}

bool isPrime(int n) {
    bool prime = true;
    for (int div = 3; div*div <= n; div += 2) {
        if (n % div == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long n;
    cin >> n;

    if (n < 100) {
        int m = biggest(n);

        for (int i = 2; i < n; i++) {
            for (int j = 2; i + j <= n; j++) {
                if (i + j == n) {
                    m = min(m, biggest(i) + biggest(j));
                }
                int k = n - i - j;
                if (k >= 2) {
                    m = min(m, biggest(i) + biggest(j) + biggest(k));
                }
            }
        }

        cout << m << endl;
        return 0;
    }

    if (n % 2 == 0) {
        cout << 2 << endl;
        return 0;
    }
    
    

    if (isPrime(n)) {
        cout << 1 << endl;
    }
    else {
        if (isPrime(n-2)) {
           cout << 2 << endl;
        }
        else {
            cout << 3 << endl;
        }
    }

    return 0;
}