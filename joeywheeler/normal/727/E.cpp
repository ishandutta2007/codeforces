#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

ll MOD[2] = {1000000009ll, 1000000007ll};
ll BASE[2] = {137ll,137ll};

struct hsh {
    ll val[2];

    bool operator<(const hsh &o) const {
        FO(i,0,2) if (val[i] != o.val[i]) return val[i]<o.val[i];
        return false;
    }
};

ll pw[2][100005];
int n, k, g;
char s[1000005];

void rlhsh(hsh &h, int f, int l) {
    FO(i,0,2) {
        h.val[i] = h.val[i] * BASE[i] + l - f * pw[i][k];
        h.val[i] %= MOD[i];
        if (h.val[i] < 0) h.val[i] += MOD[i];
    }
}

hsh h1;
hsh sh[1000005];
pair<hsh,int> gh[100005];
int seen[100005];

int ingh(hsh h) {
    int s = 0, e = g-1;
    while (s <= e) {
        int m = (s+e)/2;
        if (gh[m].first.val[0] == h.val[0] &&
                gh[m].first.val[1] == h.val[1]) {
            return gh[m].second;
        } else if (gh[m].first < h) {
            s = m+1;
        } else e = m-1;
    }
    return -1;
}

int main() {
    FO(i,0,2) {
        pw[i][0] = 1;
        FO(j,1,100005) pw[i][j] = pw[i][j-1] * BASE[i] % MOD[i];
    }

    scanf("%d %d", &n, &k);
    scanf(" %s", s);

    FO(i,0,k) rlhsh(h1, 0, s[i]);
    FO(i,0,n*k) {
        sh[i] = h1;
        int ni = i+k;
        if (ni >= n*k) ni -= n*k;
        rlhsh(h1, s[i], s[ni]);
    }

    scanf("%d", &g);
    FO(i,0,g) {
        scanf(" %s", s);
        h1.val[0] = h1.val[1] = 0;
        FO(j,0,k) rlhsh(h1, 0, s[j]);
        gh[i] = make_pair(h1, i+1);
    }
    sort(gh, gh+g);

    FO(i,0,k) {
        vector<int> ls;
        FO(j,0,n) {
            int p = i + j*k;
            int o = ingh(sh[p]);
            if (o == -1 || seen[o] == i+1) break;
            seen[o] = i+1;
            ls.push_back(o);
        }
        if (sz(ls) == n) {
            printf("YES\n");
            for (int x : ls) printf("%d ", x);
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
}