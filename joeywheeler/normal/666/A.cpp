#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[10005];
int n;
set<string> f;

int bf[10005][5];

string gs(int a, int b) {
    return string(s+a,s+b);
}

bool cf(int i, int l) {
    if (i+l > n) return false;
    if (i+l == n) return true;
    if (bf[i][l] != -1) return bf[i][l];
    FO(nl,2,4) {
        if (cf(i+l,nl) && gs(i,i+l) != gs(i+l,i+l+nl)) {
            return bf[i][l] = true;
        }
    }
    return bf[i][l] = false;
}

int main() {
    memset(bf,-1,sizeof bf);

    scanf(" %s", s);
    n = strlen(s);
    FO(i,5,n) {
        FO(l,2,4) {
            if (cf(i,l)) f.insert(gs(i,i+l));
        }
    }
    printf("%d\n", sz(f));
    for (string r : f) printf("%s\n", r.c_str());
}