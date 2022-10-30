#include <cstdio>
#include <cstring>
#include <algorithm>

int count[10], prefix[4];
char buffer[1000001];

int main() {
    scanf("%s", buffer);
    memset(count, 0, sizeof(count));
    for (int i = 0; buffer[i]; ++ i) {
        count[buffer[i] - '0'] ++;
    }
    count[1] --;
    count[6] --;
    count[8] --;
    count[9] --;
    int remainder = 0;
    int base = 1;
    for (int i = 0; i < 10; ++ i) {
        for (int j = 0; j < count[i]; ++ j) {
            remainder *= 10;
            remainder += i;
            remainder %= 7;
            (base *= 10) %= 7;
        }
    }
    prefix[0] = 1;
    prefix[1] = 6;
    prefix[2] = 8;
    prefix[3] = 9;
    do {
        int new_remainder = 0;
        for (int i = 0; i < 4; ++ i) {
            new_remainder *= 10;
            new_remainder += prefix[i] * base % 7;
            new_remainder %= 7;
        }
        (new_remainder += remainder) %= 7;
        if (new_remainder == 0) {
            for (int i = 0; i < 4; ++ i) {
                putchar('0' + prefix[i]);
            }
            for (int i = 0; i < 10; ++ i) {
                for (int j = 0; j < count[i]; ++ j) {
                    putchar('0' + i);
                }
            }
            puts("");
            return 0;
        }
    } while (std::next_permutation(prefix, prefix + 4));
    puts("0");
    return 0;
}