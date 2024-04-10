#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())
#define mp make_pair
#define eb emplace_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char s[200005];
int pr[200005], nk[200005];
int n;

int nr[200005];

int main() {
    memset(nr, -1, sizeof nr);

    scanf(" %s", s);
    n = strlen(s);
    vector<int> v;
    vector<vector<int> > res;
    fo(i,0,n) {
        if (s[i] == '0') {
            v.push_back(i);
        } else {
            if (sz(v) == 0) {
                printf("-1\n");
                return 0;
            } else {
                int x = v.back();
                v.pop_back();
                pr[i] = x;
                nr[x] = i;
            }
        }
    }
    v.clear();
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '0') {
            v.push_back(i);
        } else {
            if (sz(v) == 0) {
                printf("-1\n");
                return 0;
            } else {
                int x = v.back();
                v.pop_back();
                nk[i] = x;
                nr[i] = x;
            }
        }
    }

    fo(i,0,n) if (nr[i] != -2) {
        vector<int> t;
        for (int j = i; j != -1; j = nr[j]) {
            t.push_back(j);
        }
        for (int j : t) nr[j] = -2;
        res.push_back(t);
    }

    printf("%d\n", sz(res));
    for (auto v : res) {
        printf("%d", sz(v));
        for (int x : v) printf(" %d", x+1);
        printf("\n");
    }
}