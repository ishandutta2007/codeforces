#include <cstdio>
#include <cstring>

const int N = 100005;
char str[N];
long long ja, jb, oa, ob;
long long ansj, anso;

int main() {
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    for (int i = 1; i <= len; i++) {
    if (i % 2 && str[i] == 'a') ja++;
    if (i % 2 && str[i] == 'b') jb++;
    if (i % 2 == 0 && str[i] == 'a') oa++;
    if (i % 2 == 0 && str[i] == 'b') ob++;
    }
    ansj = ja * (ja - 1) / 2 + jb * (jb - 1) / 2 + oa * (oa - 1) / 2 + ob * (ob - 1) / 2;
    ansj += len;
    anso = ja * oa + jb * ob;
    printf("%lld %lld\n", anso, ansj);
    
    return 0;
}