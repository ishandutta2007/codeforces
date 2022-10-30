#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

pair<int,int> p[200005];
int m[200005];
int nm[200005];

int main() {
    int n; scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d", m+i);
        p[i] = make_pair(m[i]+i, i);
    }
    sort(p,p+n);
    FO(i,0,n) {
        int l = p[i].second;
        nm[i] = m[l] - i + l;
        if (nm[i] < 0) {
            printf(":(\n");
        return 0;
        }
    }
    FO(i,0,n-1) if (nm[i] > nm[i+1]) {
        printf(":(\n");
        return 0;
    }
    FO(i,0,n) printf("%d%c", nm[i], " \n"[i+1==n]);
}