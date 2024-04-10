#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100001], t[100001];
int main() {
    scanf("%s %s", s, t);
    printf("%d\n", (int) (strcmp(s, t) ? max(strlen(s), strlen(t)) : -1));
}