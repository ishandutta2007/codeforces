#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int n;

bool judge(int n) {
  for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    int f = judge(n);
    if (f) printf("1\n");
    else if (n % 2 == 0) printf("2\n");
    else {
        n -= 2;
        if (judge(n)) printf("2\n");
        else printf("3\n");
    }
    return 0;
}