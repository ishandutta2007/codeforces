#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define N 10001111

bool done[N];
long long ans = 0;
int l, r;

int main() {
    cin >> l >> r;
    r += l - 1;

    for (int i = 3500; i; --i) {
        int sqr = i * i;
        
        for (int j = sqr, cost = 1; j <= r; j += sqr, ++cost)
            if (!done[j]) {
                done[j] = 1;
                if (j >= l) ans += cost;
            }
    }
    cout << ans << endl;
        
    return 0;
}