#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int n, m, a, b, ok=1;
int l[100005];
vector <int> v[100005];

void dfs (int cvor, int boja, int par) {
    l[cvor]=boja;
    for (int i=0; i<v[cvor].size(); i++) {
        if (v[cvor] [i]!=par) {
            if (l[v[cvor] [i]]==0) {
                if (boja==1) dfs(v[cvor] [i], 2, cvor); else dfs(v[cvor] [i], 1, cvor);
            } else {
                if (boja==l[v[cvor] [i]]) ok=0;
            }
        }
    }
}

int main () {
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        if (l[i]==0) {
            dfs(i, 1, 0);
        }
    }
    if (ok) {
        a=0;
        for (int i=1; i<=n; i++) {
            if (l[i]==1) a++;
        }
        printf("%d\n", a);
        for (int i=1; i<=n; i++) {
            if (l[i]==1) printf("%d ", i);
        }
        printf("\n");
        a=0;
        for (int i=1; i<=n; i++) {
            if (l[i]==2) a++;
        }
        printf("%d\n", a);
        for (int i=1; i<=n; i++) {
            if (l[i]==2) printf("%d ", i);
        }
        printf("\n");
    } else {
        cout << -1;
    }
    return 0;
}