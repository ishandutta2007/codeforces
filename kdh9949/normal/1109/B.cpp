#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n;
char s[2 * N];

int main(){
    scanf("%s", s);
    n = strlen(s);
    for(int i = 0; i < n; i++) s[i + n] = s[i];
    for(int i = 1; i < n; i++){
        int t = 0;
        for(int j = 0; j < n; j++) if(s[j] != s[i + j]){ t = 1; break; }
        if(!t) continue;
        for(int j = 0; j <= n / 2; j++) if(s[i + j] != s[i + n - 1 - j]){
            t = 0; break; }
        if(t){ puts("1"); return 0; }
    }
    if(count(s, s + n, s[0]) >= n - 1) puts("Impossible");
    else puts("2");
}