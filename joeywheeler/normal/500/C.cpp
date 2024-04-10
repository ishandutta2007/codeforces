#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> p;
int n,m;
bool seen[505];
int w[505];

vector<int> op;

int main() {
    scanf("%d %d", &n, &m);
    FO(i,0,n) {
        scanf("%d", &w[i]);
    }
    FO(i,0,m) {
        int x; scanf("%d", &x); x--;
        op.push_back(x);
        if (!seen[x]) p.push_back(x);
        seen[x] = true;
    }
    FO(i,0,n) if (!seen[i]) p.push_back(i);
    reverse(p.begin(),p.end());

    long long ans = 0;
    FO(i,0,m) {
        int x = op[i];
        int j;
        for (j = sz(p)-1; j >= 0; j--) {
            if (p[j] == x) break;
            ans += w[p[j]];
        }
        p.erase(p.begin()+j);
        p.push_back(x);
    }
    printf("%lld\n", ans);
}