#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a, b, c;

int main() {
    int flag = 0;
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 0; i <= 10000; i++) {
        if (a * i > c) break;
        if ((c - a * i) % b == 0) flag = 1;
    }
    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}