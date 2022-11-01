#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<pair<int,int> > p,q; double bl=-1;
    FO(i,-1,2) FO(j,-1,2) {
        FO(x,0,2) FO(y,0,2) {
            int a = x*n+i, b = y*m+j;
            if (0 <= a && a <= n && 0 <= b && b <= m) p.emplace_back(a,b);
        }
    }
    sort(p.begin(),p.end());
    p.resize(unique(p.begin(),p.end())-p.begin());
    //fprintf(stderr, "%d\n", sz(p));
    do {
        double len = 0;
        FO(i,0,3) len += sqrt(pow(p[i+1].first-p[i].first,2)+pow(p[i+1].second-p[i].second,2));
        if (len > bl) {
            bl = len;
            q = p;
        }
        sort(p.begin()+4,p.end());
        reverse(p.begin()+4,p.end());
    } while (next_permutation(p.begin(),p.end()));
    FO(i,0,4) printf("%d %d\n", q[i].first, q[i].second);
}