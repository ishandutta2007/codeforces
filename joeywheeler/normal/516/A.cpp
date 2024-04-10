#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int cnt[10];
char buf[10000] = {};

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        char ch; scanf(" %c", &ch);
        cnt[ch-'0']++;
    }
    cnt[1] = cnt[0] = 0;
    {
        cnt[3] += 2*cnt[9];
        cnt[2] += cnt[9];
        cnt[7] += cnt[9];
        cnt[9] = 0;
    }
    {
        cnt[7] += cnt[8];
        cnt[2] += 3*cnt[8];
        cnt[8] = 0;
    }
    {
        cnt[5] += cnt[6];
        cnt[3] += cnt[6];
        cnt[6] = 0;
    }
    {
        cnt[3] += cnt[4];
        cnt[2] += 2*cnt[4];
        cnt[4] = 0;
    }
    int p = 0;
    for (int i=9; i > 1; i--) FO(j,0,cnt[i]) buf[p++] = i+'0';
    printf("%s\n", buf);
}