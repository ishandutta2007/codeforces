#include <bits/stdc++.h>

#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int q(vector<int> a, vector<int> b, int v) {
    if (sz(a) == 0 || sz(b) == 0) return 0;
    printf("%d\n", sz(a));
    fo(i,0,sz(a)) printf("%d ", a[i]);
    printf("\n%d\n", sz(b));
    fo(i,0,sz(b)) printf("%d ", b[i]);
    printf("\n");
    printf("%d\n", v);
    fflush(stdout);
    int x; scanf("%d", &x);
    return x;
}

pair<int,int> ss[5005];
int par[5005];

int main() {
    int n; scanf("%d", &n);
    vector<int> u,v;
    fo(i,2,n+1) v.push_back(i);
    u.push_back(1);
    fo(i,2,n+1) ss[i] = make_pair(q(u, v, i), i);
    sort(ss+2,ss+n+1);

    v.clear();
    fo(z,2,n+1) {
        int _q, i; tie(_q, i) = ss[z];
        int nc = q(u, v, i);
        while (nc) {
            int s = 0, e = sz(v)-1, b = sz(v)-1;
            while (s <= e) {
                int md = (s+e)/2;
                vector<int> tv = v;
                tv.resize(md+1);
                if (q(u, tv, i)) {
                    b = md;
                    e = md-1;
                } else s = md+1;
            }
            par[v[b]] = i;
            v.erase(v.begin()+b);
            nc--;
        }
        v.push_back(i);
    }
    for (int x : v) par[x] = 1;
    printf("ANSWER\n");
    fo(i,2,n+1) printf("%d %d\n", par[i], i);
    return 0;
}