#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char a[100005];
char b[35];
int n, m;

int t[35][26];

int mb(string s) {
    while (s != string(b,b+sz(s))) {
        s = s.substr(1,sz(s)-1);
    }
    return sz(s);
}

int d[35];
int nd[35];

int main() {
    scanf(" %s %s", a, b);
    n = strlen(a);
    m = strlen(b);
    FO(i,0,m) {
        FO(j,0,26) {
            // currently match i letters, and i add a j, what next?
            string s(b,b+i);
            s += 'a'+j;
            int l = mb(s);
            if (l == m) l = -1;
            //printf("%d %c: %d\n", i, j+'a', l);
            t[i][j] = l;
        }
    }
    d[0] = 0;
    FO(i,1,m) d[i] = n+5;
    FO(i,0,n) {
        int c = a[i]-'a';
        FO(j,0,m) nd[j] = n+5;
        FO(j,0,m) {
            int nj = t[j][c];
            if (nj != -1) nd[nj] = min(nd[nj], d[j]);
            nd[0] = min(nd[0],d[j]+1);
        }
        FO(j,0,m) d[j] = nd[j];
    }
    int res = n+5;
    FO(i,0,m) res = min(res, d[i]);
    printf("%d\n", res);
}