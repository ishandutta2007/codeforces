#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
string s[105];
bool le[27][27];
bool dd[27];

char buf[105];
int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf(" %s", buf);
        s[i] = buf;
    }
    FO(i,0,n-1) {
        int diff = -1;
        for (int j = 0; j < min(sz(s[i]),sz(s[i+1])); j++) {
            if (s[i][j] != s[i+1][j]) {
                diff = j;
                le[s[i][j]-'a'][s[i+1][j]-'a'] = true;
                break;
            }
        }
        if (diff == -1) {
            if (sz(s[i]) >= sz(s[i+1])) {
                printf("Impossible\n");
                return 0;
            }
        }
    }
    FO(i,0,26) FO(j,0,26) FO(k,0,26) le[j][k] |= le[i][j]&le[j][k];
    char ret[100] = {};
    FO(Z,0,26) {
        bool done = false;
        FO(i,0,26) {
            if (dd[i]) continue;
            int id = 0;
            FO(j,0,26) if (le[j][i]) id++;
            if (id == 0) {
                FO(j,0,26) le[i][j] = 0;
                dd[i] = true;
                done = true;
                ret[Z] = 'a'+i;
                break;
            }
        }
        if (!done) {
            printf("Impossible\n");
            return 0;
        }
    }
    printf("%s\n", ret);
}