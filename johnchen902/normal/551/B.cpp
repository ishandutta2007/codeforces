#include <cstdio>
#include <algorithm>
using namespace std;

char a[100001], b[100001], c[100001];
int ca[26], cb[26], cc[26];

bool ok(int x) {
    for(int i = 0; i < 26; i++)
        if(ca[i] < cb[i] * x)
            return false;
    return true;
}

int cnt(int x) {
    int mini = 100000;
    for(int i = 0; i < 26; i++)
        if(cc[i])
            mini = min(mini, (ca[i] - cb[i] * x) / cc[i]);
    return mini;
}

int main() {
    scanf("%s %s %s", a, b, c);
    for(char *p = a; *p; p++) ca[*p - 'a']++;
    for(char *p = b; *p; p++) cb[*p - 'a']++;
    for(char *p = c; *p; p++) cc[*p - 'a']++;
    int best_i = 0, best_j = 0;
    for(int i = 0; ok(i); i++) {
        int j = cnt(i);
        if(i + j > best_i + best_j) {
            best_i = i;
            best_j = j;
        }
    }
    for(int i = 0; i < best_i; i++) fputs(b, stdout);
    for(int j = 0; j < best_j; j++) fputs(c, stdout);
    for(int i = 0; i < 26; i++) {
        int r = ca[i] - cb[i] * best_i - cc[i] * best_j;
        for(int j = 0; j < r; j++) putchar('a' + i);
    }
}