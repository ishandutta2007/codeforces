#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

struct KMP {
    char s[2000005];
    int sl[2000005];
    int n;

    void go() {
        n = strlen(s);
        sl[0] = -1;
        FO(i,1,n+1) {
            sl[i] = 0;
            for (int j = sl[i-1]; j != -1; j = sl[j]) {
                if (s[j] == s[i-1]) {
                    sl[i] = j+1;
                    break;
                }
            }
        }
    }
} k;

char s1[1000005];
char s2[1000005];
int n;

char opp(char c) {
    if (c == 'N' || c == 'S') return 'N'+'S'-c;
    if (c == 'E' || c == 'W') return 'E'+'W'-c;
    return '?';
}

int main() {
    scanf("%d", &n);
    n--;
    scanf("%s", s1);
    scanf("%s", s2);
    FO(i,0,n) s2[i] = opp(s2[i]);
    FO(i,0,n) k.s[i] = s1[n-i-1];
    FO(i,0,n) k.s[i+n] = s2[i];
    //printf("%s\n", k.s);
    k.go();
    if (k.sl[k.n]) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
}