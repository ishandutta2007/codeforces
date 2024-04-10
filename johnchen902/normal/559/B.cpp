#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[200001];
char b[200001];
void normalize(char * s, int n) {
    if(n % 2 == 0) {
        normalize(s,         n / 2);
        normalize(s + n / 2, n / 2);
        if(strncmp(s, s + n / 2, n) > 0)
            rotate(s, s + n / 2, s + n);
    }
}
int main() {
    scanf("%s %s", a, b);
    normalize(a, strlen(a));
    normalize(b, strlen(b));
    puts(strcmp(a, b) ? "NO" : "YES");
}