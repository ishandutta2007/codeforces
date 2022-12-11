#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 6e5 + 10;

int n, s[N];
char a[N], b[N];




int main() {
    scanf("%d%s%s", &n, a + 1, b + 1);
    for(int i = 1; i <= n; i ++) {
        a[i] -= 'a'; b[i] -= 'a';
        s[i] = a[i] + b[i];
    }
    //1330
    for(int i = 1; i <= n; i ++) {
        if(s[i] & 1) {
            s[i + 1] += 26;
        }
        s[i] >>= 1;
    }
    for(int i = n; i >= 1; i --) {
        s[i - 1] += s[i] / 26;
        s[i] %= 26;
    }
    for(int i = 1; i <= n; i ++)
        putchar(s[i] + 'a');
    return 0;
}
/*
aaa -> 1
aab
*/