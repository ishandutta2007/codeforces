#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, l, x, y;
vector<int> p;

vector<int> exists(int t) {
    int i0 = 0, i1 = 0;
    vector<int> res;
    while (i0 < sz(p) && i1 < sz(p)) {
        if (p[i1]-p[i0]==t) {
            res.push_back(p[i0]);
            i1++;
        } else if (p[i1]-p[i0] > t) i0++;
        else i1++;
    }
    return res;
}

int main() {
    scanf("%d %d %d %d", &n, &l, &x, &y);
    FO(i,0,n) {
        int v; scanf("%d", &v); p.push_back(v);
    }
    if (sz(exists(x)) && sz(exists(y))) printf("0\n");
    else if (!sz(exists(x)) && !sz(exists(y))) {
        if (sz(exists(x+y))) {
            printf("1\n%d\n", exists(x+y)[0]+x);
        } else {
            vector<int> r = exists(y-x);
            FO(i,0,sz(r)) {
                if (r[i]>=x) {
                    printf("1\n%d\n",r[i]-x);
                    return 0;
                } else if (r[i]+y<=l) {
                    printf("1\n%d\n",r[i]+y);
                    return 0;
                }
            }
            printf("2\n%d %d\n", x, y);
        }
    } else {
        if (!sz(exists(x))) printf("1\n%d\n",x);
        else printf("1\n%d\n",y);
    }
}