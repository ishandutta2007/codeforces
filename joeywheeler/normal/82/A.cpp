#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    unsigned long long num = 5;
    while (num < n) {
        n -= num;
        num *= 2;
    }

    num /= 5;

    if (n <= num) {
        printf("Sheldon\n");
    } else if (n <= 2*num) {
        printf("Leonard\n");
    } else if (n <= 3*num) {
        printf("Penny\n");
    } else if (n <= 4*num) {
        printf("Rajesh\n");
    } else if (n <= 5*num) {
        printf("Howard\n");
    }

}