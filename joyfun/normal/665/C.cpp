#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;

char str[N];

int main() {
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    printf("%c", str[1]);
    for (int i = 2; i <= n; i++) {
        if (str[i] == str[i - 1]) {
            for (int j = 0; j < 26; j++) {
                if (j != str[i - 1] - 'a' && (i == n || j != str[i + 1] - 'a')) {
                    str[i] = j + 'a';
                    break;
                }
            }
        }
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}