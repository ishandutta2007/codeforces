#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    bool ans = false;
    for(int x1 = 1; x1 < a; x1++){
        int y1 = (int)(sqrt(a * a - x1 * x1) + 0.5);
        if(x1 * x1 + y1 * y1 != a * a) continue;
        for(int x2 = 1; x2 < b; x2++){
            int y2 = (int)(sqrt(b * b - x2 * x2) + 0.5);
            if(x2 * x2 + y2 * y2 != b * b) continue;
            int x3 = x1 + x2;
            int y3 = abs(y2 - y1);
            if(y3 == 0) continue;
            if(x3 * x3 + y3 * y3 != a * a + b * b) continue;
            ans = true;
            cout << "YES" << endl;
            printf("%d %d\n", x1, 0);
            printf("%d %d\n", x1 + x2, y2);
            printf("%d %d\n", 0, y1);
            goto OUTPUT;
        }
    }
OUTPUT:
    if(!ans) cout << "NO" << endl;
    return 0;
}