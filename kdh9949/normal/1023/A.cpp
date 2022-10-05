#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
char s[N], t[N];

int main(){
    scanf("%d%d%s%s", &n, &m, s, t);
    int i; for(i = 0; i < n; i++) if(s[i] == '*') break;
    if(i == n){ puts(!strcmp(s, t) ? "YES" : "NO"); return 0; }
    if(!strncmp(s, t, i) && !strncmp(s + i + 1, t + m - (n - i - 1), n - i - 1)
        && m >= n - 1)
        puts("YES");
    else puts("NO");
    return 0;
}