#include <bits/stdc++.h>

using namespace std;

int N, M, a, b;
int s[200010];

bool check(int x) {
    int maxt = 0;
    int B = b;
    for (int i=1;i<=x;i++) {
        maxt = max(maxt, i + s[x + 1 - i]);
    }
    B -= x;
    if (B <= a) return false;
    return x + B - 1 >= maxt;
}  

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d%d",&N,&M,&a,&b);
        if (a > b) {
            a = N + 1 - a;
            b = N + 1 - b;
        }
        for (int i=1;i<=M;i++) {
            scanf("%d",&s[i]);
        }
        sort(s+1,s+M+1);
        int L = 0, R = M + 1;
        while(L < R - 1) {
            int mid = (L + R) / 2;
            if (check(mid)) L = mid;
            else R = mid;
        }
        printf("%d\n",L);
    }
}