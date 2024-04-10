#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int nxt[1000005][26];
int ew[1000005];
int cn;

void adw(char *s, int ind) {
    int i = 0;
    while (*s) {
        if (!nxt[i][*s-'a']) nxt[i][*s-'a'] = ++cn;
        i = nxt[i][*s-'a'];
        s++;
    }
    ew[i] = ind;
}

int n;
char s[10005];
vector<pair<string,string> > w;
int c[10005];
char wbuf[1005];

int main() {
    scanf("%d", &n);
    scanf(" %s", s);
    int m; scanf("%d", &m);
    FO(z,0,m) {
        scanf(" %s", wbuf);
        string ow = wbuf;
        int len = strlen(wbuf);
        FO(i,0,len) wbuf[i] = tolower(wbuf[i]);
        reverse(wbuf,wbuf+len);
        adw(wbuf,z+1);
        w.emplace_back(wbuf,ow);
    }

    c[0] = 1;
    FO(i,0,n) if (c[i]) {
        int nd = 0;
        FO(j,i,n) {
            nd = nxt[nd][s[j]-'a'];
            if (nd == 0) break;
            if (ew[nd]) c[j+1] = ew[nd];
        }
    }

    vector<int> ans;
    for (int i = n; i != 0; ) {
        int j = c[i]-1;
        ans.push_back(j);
        i -= sz(w[j].first);
    }
    reverse(ans.begin(),ans.end());
    for (int x : ans) {
        printf("%s ", w[x].second.c_str());
    }
    printf("\n");
}