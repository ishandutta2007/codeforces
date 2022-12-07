#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;

char a[N], b[N];

int main() {
    scanf("%s%s", a, b);
    int an = strlen(a);
    int bn = strlen(b);
    int i = 0, j = 0;
    while (i < an - 1 && a[i] == '0') i++;
    while (j < bn - 1 && b[j] == '0') j++;
    if (an - i > bn - j) printf(">");
    else if (an - i < bn - j) printf("<");
    else {
        int tmp = 0;
        while (i < an && j < bn) {
            if (a[i] < b[j]) {
                tmp = -1;
                break;
            }
            if (a[i] > b[j]) {
                tmp = 1;
                break;
            }
            i++; j++;
        }
        if (tmp == 0) printf("=");
        else if (tmp == 1) printf(">");
        else printf("<");
    }
    return 0;
}