#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, a[N], b[N];

bool judge() {
    for (int i = 0; i < n; i++)
    if (a[i] != b[i]) return true;
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    scanf("%d%d", &a[i], &b[i]);
    if (judge()) printf("Happy Alex\n");
    else printf("Poor Alex\n");
    return 0;
}