#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<vector<int>> v;

int dist(int a, int b) {
    if (a>b) return b-a+n;
    else return b-a;
}
int main() {
    scanf("%d%d", &n, &m);
    v.resize(n);

    int a, b;
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);

        if (a>b) swap(a, b);
        if (b-a <= a-b+n) v[b-a].push_back(a);
        if (b-a >= a-b+n) v[a-b+n].push_back(b);
    }

    int ans = 0;
    for (int i=1; i<n; i++) {
        if (v[i].size()>1) {
            sort(v[i].begin(), v[i].end());

            int sz = v[i].size();

            for (int j=1; j<sz; j++) {
                int dst = dist(v[i][0], v[i][j]);
                bool flag = true;

                for (int k=0; k<sz; k++) {
                    if (dst != dist(v[i][k], v[i][(j+k)%sz])) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    ans = __gcd(ans, n/dst);
                    break;
                }

                if (j==sz-1) ans=1;
            }
        }
        else if (v[i].size() == 1) ans = 1;

        if (ans==1) break;
    }

    if (ans==1) printf("No");
    else printf("Yes");
}