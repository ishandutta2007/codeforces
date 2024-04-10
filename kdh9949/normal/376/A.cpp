#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1000005;

char s[N];
ll v, w;

int main(){
    scanf("%s", s);
    for(; s[w] != '^'; w++);
    for(int i = 0; s[i]; i++, w--) if('0' <= s[i] && s[i] <= '9')
        v += w * (s[i] - '0');
    puts(v > 0 ? "left" : v < 0 ? "right" : "balance");
}