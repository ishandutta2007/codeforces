#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    int last = 1;
    while (k) {
        last++;
        int x = last;
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        if (sum == 10)
           k--;
    }
    cout << last << '\n';
    
}