#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    if (n > m) swap(n, m);
    printf("%s\n", n % 2 ? "Akshat" : "Malvika");
    return 0;
}