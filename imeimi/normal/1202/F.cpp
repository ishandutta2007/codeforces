#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;

int pos[4001];
int main() {
    const int S = 1000000;
    int a, b;
    cin >> a >> b;
    //(k)*m+(...)
    //A+B=k, 0<=a-Am<=A, 0<=b-Bm<=B
    //a/m>=A>=a/(m+1), b/m>=B>=b/(m+1)
    //m <= S
    int ans = 0;
    int mn = 2e9 + 5;
    for (int m = 1; m <= S; ++m) {
        int minA = (a + m) / (m + 1);
        int minB = (b + m) / (m + 1);
        int maxA = a / m;
        int maxB = b / m;
        if (minA > maxA || minB > maxB) continue;
        ans += min(maxA + maxB, mn - 1) - (minA + minB) + 1;
        mn = minA + minB;
    }
    for (int A = 1; A <= 2000; ++A) {
        for (int B = 1; B <= 2000; ++B) {
            int mn = max((a + A - 1) / A, (b + B - 1) / B) - 1;
            int mx = min(a / A, b / B);
            if (mn > mx) continue;
            if (mn <= S) continue;
            pos[A + B] = 1;
        }
    }
    for (int i = 1; i <= 4000; ++i) ans += pos[i];
    printf("%d\n", ans);
    return 0;
}