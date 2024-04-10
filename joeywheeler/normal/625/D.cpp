#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[100005];
int res[100005];
int n;

int gl(int x) {
    if (x <= 9) return x;
    else return x-9;
}

bool seen[100005][2][2];

// needs cl, has cr
bool dp(int i, int cl, int cr) {
    int j = n-1-i;
    if (i-1 == j) {
        return cl == cr;
    }
    if (seen[i][cl][cr]) return false;
    seen[i][cl][cr] = true;
    if (i == j) {
        FO(d,0,19) if (d%2 == 0) {
            if (i == 0 && d == 0) continue;
            int dd = d+cr;
            if (dd/10 != cl) continue;
            if (dd%10 != s[i]-'0') continue;
            res[i] = d/2;
            return true;
        }
    } else {
        FO(d,0,19) {
            if (i == 0 && d == 0) continue;
            int dl = d, dr = d+cr;
            if (dr%10 != s[i]-'0') continue;
            int nc = cl*10+s[j]-'0'-dl;
            if (nc != 0 && nc != 1) continue;
            if (dp(i+1, nc, dr/10)) {
                res[j] = gl(d);
                res[i] = d-gl(d);
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf(" %s", s);
    n = strlen(s);
    reverse(s,s+n);
    if (dp(0,0,0)) {
        reverse(res,res+n);
        FO(i,0,n) printf("%d", res[i]);
        printf("\n");
        return 0;
    } else {
        memset(seen,0,sizeof seen);
        n--;
        if (s[n] == '1' && dp(0,1,0)) {
            reverse(res,res+n);
            FO(i,0,n) printf("%d", res[i]);
            printf("\n");
            return 0;
        }
    }
    printf("0\n");
}