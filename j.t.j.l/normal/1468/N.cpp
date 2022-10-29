#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    long long c1,c2,c3;
    long long a1,a2,a3,a4,a5;
    while(T--) {
        cin >> c1 >> c2 >> c3;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        c1 -= a1;
        c2 -= a2;
        c3 -= a3;
        if (c1 < 0 || c2 < 0 || c3 < 0) {
            puts("NO");
            continue;
        }
        c1 -= a4;
        if (c1 < 0) c3 += c1;
        c2 -= a5;
        if (c2 < 0) c3 += c2;
        cout << (c3 < 0 ? "NO" : "YES") << endl;
    }
}