#include <bits/stdc++.h>
using namespace std;

int arr[101010];
int main() {
    int n;
    scanf("%d", &n);

    int maxi = 0;
    int cnt = 0;
    int maxcnt = 0;
    int a;
    for (int i=0; i<n; i++) {
        scanf("%d", &a);
        if (a>maxi) {
            maxi = a;
            cnt = 1;
            maxcnt = 0;
        }
        else if (a==maxi) {
            cnt++;
        }
        else {
            cnt = 0;
        }

        if (cnt > maxcnt) {
            maxcnt = cnt;
        }
    }

    printf("%d", maxcnt);
}