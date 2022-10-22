#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
int n;
char S[MAXN + 5];

bool check(int mid) {
    int c0 = 0, rm1 = 0;
    for (int i = 0; i < n; i++)
        if (S[i] == '1')
            rm1++;
    if (max(c0, rm1) <= mid)
        return 1;
    for (int i = 0, p = 0; i < n; i++) {
        if (S[i] == '0')
            c0++;
        else
            rm1--;
        while (p < i && c0 > mid) {
            if (S[p] == '0')
                c0--;
            else
                rm1++;
            p++;
        }
        if (max(c0, rm1) <= mid)
            return 1;
    }
    return 0;
}

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        scanf("%s", S);
        n = strlen(S);
        int a = 0, b = n;
        while (a < b) {
            int mid = (a + b) >> 1;
            if (check(mid))
                b = mid;
            else
                a = mid + 1;
        }
        printf("%d\n", a);
    }
    return 0;
}