#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int n; scanf("%d", &n);
    char b[1000]; scanf(" %s", b);
    FO(i,0,n) {
        FO(j,i+1,n) {
            int dv = j-i;
            bool bad = false;
            FO(k,0,5) {
                if (i+dv*k < n && b[i+dv*k] == '*');
                else bad = true;
            }
            if (!bad) {
                printf("yes\n");
                return 0;
            }
        }
    }
    printf("no\n");
}