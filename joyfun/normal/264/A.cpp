#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;
char str[N];
int ans[N];

int main() {
    scanf("%s", str);
    int len = strlen(str);
    int rear = len - 1, head = 0;;
    for (int i = 0; i < len; i++) if (str[i] == 'l') ans[rear--] = i + 1;
    else ans[head++] = i + 1;
    for (int i = 0; i < len; i++) printf("%d\n", ans[i]);
    return 0;
}