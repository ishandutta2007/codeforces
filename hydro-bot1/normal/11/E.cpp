// Hydro submission #6297574db0c5e75beb15a8a1@1654085454168
#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db eps = 1e-9;
const int maxn = 1e6+5;

db f[maxn<<1][2];
int n, tot, lst, mt, Xpos[maxn];
char s[maxn], cg[maxn<<1];

int main()
{
    scanf("%s", s+1);
    n = strlen(s+1);
    if(s[1] == s[n] && s[1] == 'R')
        cg[++tot] = 'X';
    mt = 0;
    for(int i = 1; i <= n; i += 1)
    {
        if(s[i] == s[i-1] && s[i] != 'X')
            cg[++tot] = 'X';
        if(tot+1&1 && s[i] == 'R' || !(tot+1&1) && s[i] == 'L')
            cg[++tot] = 'X', Xpos[++lst] = mt;
        cg[++tot] = s[i];
        if(s[i] != 'X')
            mt += 1;
    }
    if(s[1] == s[n] && s[1] == 'L')
        cg[++tot] = 'X';
    if(tot & 1)
    {
        cg[++tot] = 'X';
        if(s[1] != s[n])
            Xpos[++lst] = mt;
    }
    int matched = 0, fail = 0;
    for(int i = 1; i <= tot; i += 1)
    {
        if(cg[i] != 'X')
            matched += 1;
        else
            fail += 1;
    }
    for(int i = 1; i <= lst; i += 1)
    {
        if(matched <= fail)
            break;
        if(Xpos[i] + 1 == Xpos[i+1])
            matched -= 1, fail -= 1, i += 1;
    }
    long long rat = (long long)matched*100000000/(matched+fail);
    printf("%.6lf", rat/1e6);
    return 0;
}