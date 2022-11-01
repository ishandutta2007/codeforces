#include <cstdio>
#include <algorithm>
using namespace std;

char str1[100001], str2[100001];

int main(void) {
    scanf("%s%s", str1, str2);
    int m1 = 0, m2 = 0;
    for (int i = 0; str1[i] != 0; i++) {
        if (str1[i] != str2[i]) {
            if (str1[i] == '4')
                ++m1;
            else
                ++m2;
        }
    }
    printf("%d\n", max(m1, m2));
    return 0;
}