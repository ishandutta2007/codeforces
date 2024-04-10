// Hydro submission #62c7c8258672efa577c0cf78@1657260069824
#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        vector<int> ivec;
        int n;
        scanf("%d", &n);
        ivec.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &ivec[i]);
        }
        int m;
        scanf("%d", &m);
        int ptr = 1;
        for (int i = 1; i <= m; i++) {
            int x;
            scanf("%d", &x);
            ptr = (ptr + x) % n;
        }
        if (!ptr) ptr = n;
        printf("%d\n", ivec[ptr]);
    }
}