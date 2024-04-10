#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int v[100005];
pair<int,int> s[100005];
int pr[100005];

void go(int rs, int re, set<int> &kk, int par) {
    if (sz(kk) == 0) return;
    else {
        int r = *kk.begin();
        pr[r] = par;
        int j = -1;
        FO(i,0,1000000) {
            if (s[rs+i].second == r) {
                j = rs+i;
                break;
            }
            if (s[re-i-1].second == r) {
                j = re-i-1;
                break;
            }
        }
        if (j-rs < re-j) {
            FO(i,rs,j+1) {
                kk.erase(s[i].second);
            }
            go(j+1, re, kk, r);
            kk.clear();
            FO(i,rs,j) {
                kk.insert(s[i].second);
            }
            go(rs, j, kk, r);
        } else {
            FO(i,j,re) {
                kk.erase(s[i].second);
            }
            go(rs, j, kk, r);
            kk.clear();
            FO(i,j+1,re) {
                kk.insert(s[i].second);
            }
            go(j+1, re, kk, r);
        }
    }
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", v+i);
    FO(i,0,n) s[i] = make_pair(v[i],i);
    sort(s,s+n);
    set<int> kk;
    FO(i,0,n) kk.insert(i);
    go(0,n,kk,-1);
    FO(i,1,n) printf("%d%c", v[pr[i]], " \n"[i+1==n]);
}