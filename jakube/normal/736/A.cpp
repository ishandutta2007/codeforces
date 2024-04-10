#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    long long n;
    cin >> n;
    
    std::vector<long long> fib(1000);
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < fib.size(); ++i) {
        fib[i] = fib[i-1] + fib[i-2];
        if (fib[i] > n) {
            cout << i-1 << endl;
            return 0;
        }
    }



    return 0;
}