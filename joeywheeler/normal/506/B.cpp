#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

vector<int> u[100005];
vector<int> u2[100005];
bool s[100005];
int deg[100005];

int n, m;

vector<int> c;

void fc(int i) {
    s[i] = true;
    c.push_back(i);
    for (int j : u2[i]) if (!s[j]) fc(j);
}

int Q[100005], qs, qe;

bool topsort(vector<int> v) {
    qs = qe = 0;
    for (int i : v) if (deg[i] == 0) Q[qe++] = i;
    while (qs != qe) {
        int i = Q[qs++];
        for (int j : u[i]) {
            deg[j]--;
            if (deg[j] == 0) Q[qe++] = j;
        }
    }
    return qe == sz(v);
}

int main() {
    scanf("%d%d", &n, &m);
    FO(i,0,m) {
        int x, y; scanf("%d %d", &x, &y); x--; y--;
        u[x].push_back(y); deg[y]++;
        u2[x].push_back(y);
        u2[y].push_back(x);
    }
    int res = 0;
    FO(i,0,n) if (!s[i]) {
        c.clear();
        fc(i);
        if (topsort(c)) res += sz(c)-1;
        else res += sz(c);
    }
    printf("%d\n", res);
}