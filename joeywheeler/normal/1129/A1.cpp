#include <bits/stdc++.h>

#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

typedef long long ll;

int n, m;
vector<int> v[5005];

int main() {
    scanf("%d %d", &n, &m);
    fo(i,0,m) {
        int a, b; scanf("%d %d", &a, &b); a--; b--;
        int d = (b-a+n) % n;
        v[a].push_back(d);
    }
    fo(i,0,n) sort(v[i].begin(), v[i].end());
    fo(i,0,n) {
        int t = 0;
        fo(j,0,n) {
            int l = (i+j) % n;
            if (sz(v[l])) {
                t = max(t, (sz(v[l])-1) * n + j + v[l][0]);
            }
        }
        printf("%d%c", t, " \n"[i+1==n]);
    }
}