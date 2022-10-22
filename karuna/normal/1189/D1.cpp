#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, a, b, cnt, tmp;
bool chk[101010], flag;
vector<vector<int>> v;
queue<int> q;

int main() {
    scanf("%d", &n);
    v.resize(n+1);

    for (int i=0; i<n-1; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }


    for (int i=1; i<=n; i++) {
        if (v[i].size() == 2) {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
}