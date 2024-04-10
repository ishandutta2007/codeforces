#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

char s[200005];
vector<int> l[200005];
set<int> t[2][2];
int n;
int ReS;

void mv(int x, int v) {
    l[x].push_back(v);
    FO(i,0,2) FO(j,0,2) if (t[i][j].count(x)) {
        t[i][j].erase(x);
        t[i][!j].insert(x);
        return;
    }
}

bool frst = true;
char prv = '?';

void print(int x) {
    //printf("PRINTING %d\n", x);
    for (int y : l[x]) {
        if (!frst) printf(" ");
        frst = false;
        printf("%d", y);
        assert(s[y-1] != prv);
        prv = s[y-1];
    }
}

int getd(int i) {
    int res = 0;
    FO(j,0,2) res += sz(t[j][i]);
    return res;
}

bool go(int a, int b, bool printa=false) {
    FO(i,0,2) FO(j,0,2) t[i][j].clear();
    FO(i,0,a+b) l[i].clear();
    FO(i,0,a) t[0][0].insert(i);
    FO(i,a,a+b) t[1][1].insert(i);
    //printf("a=%d,b=%d\n", a, b);
    FO(i,0,n) {
        if (s[i] == 'R') {
            int k;
            for (k = 1; k >= 0; k--) if (sz(t[k][1])) {
                mv(*t[k][1].begin(), i+1);
                break;
            }
            assert(k >= 0);
        } else {
            int k;
            for (k = 0; k <= 1; k++) if (sz(t[k][0])) {
                mv(*t[k][0].begin(), i+1);
                break;
            }
            assert(k <= 1);
        }
    }
    int start = 0;
    FO(i,0,2) {
        int ind = 0, outd = 0;
        FO(j,0,2) ind += sz(t[j][i]), outd += sz(t[i][j]);
        if (abs(ind-outd) > 1) return false;
        //printf("%d,%d\n", ind, outd);
        if (ind+outd == 0) start = !i;
        if (ind < outd) start = i;
    }
    if (!sz(t[start][!start]) && sz(t[!start][!start])) return false;
    if (printa) {
        //printf("start=%d\n", start);
        //printf("?PRINTING\n");
        printf("%d\n", a+b-1);
        for (int x : t[start][start]) print(x);
        if (sz(t[start][!start])) {
            print(*t[start][!start].begin());
            t[start][!start].erase(t[start][!start].begin());
            for (int x : t[!start][!start]) print(x);
            start = !start;
            while (sz(t[start][!start]) || sz(t[!start][start])) {
                assert(sz(t[start][!start]));
                print(*t[start][!start].begin());
                t[start][!start].erase(t[start][!start].begin());
                start = !start;
            }
        }
        printf("\n");
    }
    return true;
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    int d = 0;
    int cnt = 0;
    FO(i,0,n) {
        if (s[i] == 'L') d--;
        else d++;
        cnt = max(cnt, -d);
    }
    d = 0;
    int res = cnt;
    FO(i,0,n) {
        if (s[i] == 'L') d--;
        else d++;
        res = max(res, cnt+d);
    }
    ReS = res;
    assert(go(cnt,res-cnt,true));
}