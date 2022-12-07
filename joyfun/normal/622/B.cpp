#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int h, m;

int main() {
    scanf("%d:%d", &h, &m);
    int sb = h * 60 + m;
    int a;
    scanf("%d", &a);
    sb += a;
    sb %= 1440;
    h = sb / 60;
    m = sb % 60;
    printf("%02d:%02d\n", h, m);
    return 0;
}