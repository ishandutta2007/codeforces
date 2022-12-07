#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int a, ta, b, tb, hh, mm;

int main() {
    scanf("%d%d", &a, &ta);
    scanf("%d%d", &b, &tb);
    scanf("%d:%d", &hh, &mm);
    int ti = (hh - 5) * 60 + mm;
    int ans = 0;
    int cao = min(18 * 60 + 59, ta + ti);
    int sb = cao / b;
    for (int i = 0; i <= sb; i++)
        if (ti - i * b < tb && ta + ti - i * b != 0) ans++;
    printf("%d\n", ans);
    return 0;
}