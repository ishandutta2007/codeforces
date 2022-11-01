#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    if(n <= 3) {
        puts("NO");
        return 0;
    }
    if(n % 4 == 0) {
        puts("YES");
        puts("1 * 2 = 2");
        puts("2 * 3 = 6");
        puts("6 * 4 = 24");
        for(int i = 5, x = 24; i < n;) {
            printf("%d + %d = %d\n", x, i, x + i); x += i; i++;
            printf("%d - %d = %d\n", x, i, x - i); x -= i; i++;
            printf("%d - %d = %d\n", x, i, x - i); x -= i; i++;
            printf("%d + %d = %d\n", x, i, x + i); x += i; i++;
        }
        return 0;
    }
    if(n % 4 == 1) {
        // (1 - 2 + 4 + 5) * 3
        puts("YES");
        puts("1 - 2 = -1");
        puts("-1 + 4 = 3");
        puts("3 + 5 = 8");
        puts("8 * 3 = 24");
        for(int i = 6, x = 24; i < n;) {
            printf("%d + %d = %d\n", x, i, x + i); x += i; i++;
            printf("%d - %d = %d\n", x, i, x - i); x -= i; i++;
            printf("%d - %d = %d\n", x, i, x - i); x -= i; i++;
            printf("%d + %d = %d\n", x, i, x + i); x += i; i++;
        }

        return 0;
    }
    if(n % 4 == 2) {
        puts("YES");
        puts("2 * 3 = 6");
        puts("6 * 4 = 24");
        puts("24 - 1 = 23");
        puts("23 - 5 = 18");
        puts("18 + 6 = 24");
        for(int i = 7, x = 24; i < n;) {
            printf("%d + %d = %d\n", x, i, x + i); x += i; i++;
            printf("%d - %d = %d\n", x, i, x - i); x -= i; i++;
            printf("%d - %d = %d\n", x, i, x - i); x -= i; i++;
            printf("%d + %d = %d\n", x, i, x + i); x += i; i++;
        }
        return 0;
    }
    if(n % 4 == 3) {
        puts("YES");
        puts("1 - 2 = -1");
        puts("-1 + 3 = 2");
        puts("2 + 4 = 6");
        puts("6 + 5 = 11");
        puts("11 + 6 = 17");
        puts("17 + 7 = 24");
        for(int i = 8, x = 24; i < n;) {
            printf("%d + %d = %d\n", x, i, x + i); x += i; i++;
            printf("%d - %d = %d\n", x, i, x - i); x -= i; i++;
            printf("%d - %d = %d\n", x, i, x - i); x -= i; i++;
            printf("%d + %d = %d\n", x, i, x + i); x += i; i++;
        }
        return 0;
    }
}