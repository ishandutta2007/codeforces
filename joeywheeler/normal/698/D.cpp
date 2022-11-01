#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

struct p {
    ll y, x;
};

bool cln(p a, p b, p c) {
    // are a, b, c collinear in that order?
    
    ll t = (b.y-a.y) * (c.x-a.x) - (b.x-a.x) * (c.y-a.y);
    if (t != 0) return false;
    if (a.x == b.x) {
        if (a.y <= b.y && b.y <= c.y) return true;
        swap(a,c);
        if (a.y <= b.y && b.y <= c.y) return true;
        return false;
    }
    if (a.x <= b.x && b.x <= c.x) return true;
    swap(a,c);
    if (a.x <= b.x && b.x <= c.x) return true;
    return false;
}

p s[10];
p m[1005];
int n, k;
vector<int> v[10][1005];
bool bd[10][1005];
int p[10];

int l[70];
int lf, le;

int ht[1005], T;

int main() {
    scanf("%d %d", &k, &n);
    FO(i,0,k) {
        scanf("%lld %lld", &s[i].x, &s[i].y);
    }
    FO(i,0,n) {
        scanf("%lld %lld", &m[i].x, &m[i].y);
    }
    FO(i,0,k) FO(j,0,n) {
        FO(l,0,n) if (l != j && cln(s[i], m[l], m[j])) {
            v[i][j].push_back(l);
        }
        if (sz(v[i][j]) >= 7) {
            v[i][j].clear();
            v[i][j].shrink_to_fit();
            bd[i][j] = true;
        }
    }

    int ans = 0;
    FO(i,0,n) {
        FO(j,0,k) p[j] = j;
        bool found = false;
        do {
            lf = le = 0;
            l[le++] = i;
            T++;
            ht[i] = T;
            FO(j,0,k) {
                if (le == lf) break;
                int wm = l[lf++];
                // p[j] hits wm
                if (bd[p[j]][wm]) goto notfound;
                for (int x : v[p[j]][wm]) if (ht[x] != T) {
                    ht[x] = T;
                    l[le++] = x;
                }
                if (le > 10) goto notfound;
            }
            if (le == lf) {
                found = true;
                break;
            }
notfound:;
        } while (next_permutation(p,p+k));
        if (found) ans++;
    }

    printf("%d\n", ans);
}