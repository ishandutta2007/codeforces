#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

multiset<int> m[55];
int p[55];
int n;

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x;
        FO(j,0,n) {
            scanf("%d", &x);
            m[i].insert(x);
        }
    }
    FO(i,1,n) {
        int mc = 0, mi = 0;
        FO(j,0,n) if (m[j].count(i) > mc) {
            mc = m[j].count(i);
            mi = j;
        }
        p[mi] = i;
        m[mi].clear();
    }
    FO(i,0,n) if (p[i] == 0) p[i] = n;
    FO(i,0,n) printf("%d%c", p[i], " \n"[i+1==n]);
}