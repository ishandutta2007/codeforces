#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int N = 50005;
char tmp[55];
string str[N];
int n;

bool cmp(string a, string b) {
    return a + b < b + a;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        str[i] = tmp;
    }
    sort(str, str + n, cmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < str[i].length(); j++)
            printf("%c", str[i][j]);
    }
    printf("\n");
    return 0;
}