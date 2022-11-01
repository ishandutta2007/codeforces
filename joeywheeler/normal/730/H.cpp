#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define N 123
int n, m, a[N], len[N], is[N];
char str[N][N], ch[N];
bool sh[N];
int main() {
    scanf("%d %d", &n, &m);
    fo(i,0,n) scanf("%s", str[i]), len[i] = strlen(str[i]);
    fo(i,0,m) scanf("%d", a+i), a[i]--, is[a[i]] = 1;
    fo(i,1,m) if (len[a[i]] != len[a[0]]) {
        puts("No"); return 0;
    }
    int nn = len[a[0]];
    fo(i,0,len[a[0]]) ch[i] = str[a[0]][i];
    fo(i,0,len[a[0]]) sh[i] = 1;
    fo(i,0,m) fo(j,0,nn) if (str[a[i]][j] != ch[j]) sh[j] = 0;
    fo(i,0,n) if (!is[i]) {
        if (len[i] != len[a[0]]) continue;
        char g = 1;
        fo(j,0,nn) if (sh[j] && str[i][j] != ch[j]) g = 0;
        if (g) {
            puts("No"); return 0;
        }
    }
    puts("Yes");
    fo(i,0,nn) {
        if (!sh[i]) putchar('?');
        else putchar(ch[i]);
    }
    puts("");

    return 0;
}