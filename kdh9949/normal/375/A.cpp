#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

char s[N];
int n, v[N];

int main(){
    scanf("%s", s);
    n = strlen(s);
    sort(s, s + n);
    v[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--) v[i] = v[i + 1] * 3 % 7;
    for(int i = 1; i < n; i++) if(s[i] == '1') swap(s[0], s[i]);
    for(int i = 2; i < n; i++) if(s[i] == '6') swap(s[1], s[i]);
    for(int i = 3; i < n; i++) if(s[i] == '8') swap(s[2], s[i]);
    for(int i = 4; i < n; i++) if(s[i] == '9') swap(s[3], s[i]);
    do{
        int t = 0;
        for(int i = 0; i < n; i++) t += v[i] * (s[i] - '0');
        t %= 7;
        if(!t){ puts(s); return 0; }
    }while(next_permutation(s, s + 4));
}