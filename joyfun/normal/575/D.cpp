#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    printf("2000\n");
    for (int i = 1; i <= 1000; i++)
        printf("%d 2 %d 1\n", i, i);
    for (int i = 1000; i >= 1; i--)
        printf("%d 2 %d 1\n", i, i);
    return 0;
}