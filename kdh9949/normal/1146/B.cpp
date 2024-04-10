#include <bits/stdc++.h>
using namespace std;

int n;
char s[1000005], t[1000005];

int main(){
    scanf("%s", s);
    n = strlen(s);
    int m = n - count(s, s + n, 'a');
    if(m % 2){ puts(":("); return 0; }
    m /= 2;
    for(int i = 0, j = 0; i < n; i++) if(s[i] != 'a') t[j++] = s[i];
    for(int i = 0; i < m; i++) if(t[i] != t[i + m]){ puts(":("); return 0; }
    if(count(s, s + n - m, 'a') != count(s, s + n, 'a')){ puts(":("); return 0; }
    s[n - m] = 0;
    puts(s);
}