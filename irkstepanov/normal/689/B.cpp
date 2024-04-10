#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pll;
typedef pair<int, int> pii;

const int inf = 1e9;

int main()
{

    //ifstream cin("input.txt");

    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }

    vector<int> ans(n, inf);
    ans[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v && ans[v - 1] > ans[v] + 1) {
            ans[v - 1] = ans[v] + 1;
            q.push(v - 1);
        }
        if (v != n - 1 && ans[v + 1] > ans[v] + 1) {
            ans[v + 1] = ans[v] + 1;
            q.push(v + 1);
        }
        if (ans[a[v]] > ans[v] + 1) {
            ans[a[v]] = ans[v] + 1;
            q.push(a[v]);
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");

}