#include<iostream>
using namespace std;
int main() {
    #ifdef ldxcaicai
    freopen("lx.in", "r", stdin);
    #endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        scanf("%d", &x);
        cout << (x / 3 + (x % 3 == 1)) << ' ' << (x / 3 + (x % 3 == 2)) << '\n';
    }
    return 0;
}