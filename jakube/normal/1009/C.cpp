#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    double mean = 0;
    long long highest = 0;
    long long lowest = 0;
    for (int i = 0; i < n; i++) {
        highest += abs(i - 0);
        lowest += abs(i - n / 2);
    }

    long long sum = 0;
    for (int i = 0; i < m; i++) {
        int x, d;
        cin >> x >> d;
        mean += x;
        if (d >= 0)
            sum += highest * d;
        else
            sum += lowest * d;
    }
    
    std::cout << std::fixed << std::setprecision(12);
    cout << mean + sum / (double)n << '\n';
}