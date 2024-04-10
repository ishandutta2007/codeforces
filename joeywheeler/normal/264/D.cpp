#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[1000005];
char t[1000005];
int is[1000005], it[1000005];
int l[1000005];
int r[1000005];
vector<int> pos[3][3];

int co(int i, int j, int l, int r) {
    int x = lower_bound(pos[i][j].begin(), pos[i][j].end(), l) - pos[i][j].begin();
    if (x == sz(pos[i][j])) return 0;
    if (pos[i][j][x] > r) return 0;
    int y = lower_bound(pos[i][j].begin(), pos[i][j].end(), r) - pos[i][j].begin();
    while (y == sz(pos[i][j]) || pos[i][j][y] > r) y--;
    return y-x+1;
}

int main() {
    scanf("%s %s", s, t);
    int a=strlen(s), b=strlen(t);
    FO(i,0,a) is[i] = string("RGB").find(s[i]);
    FO(i,0,b) it[i] = string("RGB").find(t[i]);
    FO(i,1,b) {
        pos[it[i-1]][it[i]].push_back(i);
    }
    FO(i,1,a) {
        l[i] = l[i-1];
        if (l[i] < b && s[i-1] == t[l[i]]) l[i]++;
    }
    int cr=0;
    FO(i,0,a) {
        while (cr < b && t[cr] != s[i]) cr++;
        r[i] = cr;
        if (cr < b) cr++;
    }
    long long res = 0;
    FO(i,0,a) {
        res += min(r[i],b-1)-l[i]+1;
        if (i && is[i] != is[i-1]) res -= co(is[i],is[i-1],l[i],min(r[i],b-1));
    }
    printf("%lld\n", res);
}