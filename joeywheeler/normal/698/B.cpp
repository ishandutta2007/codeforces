#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int p[200005];
bool s[200005];
int np[200005];

bool cmp(int i, int j) {
    return abs(p[i]-i) < abs(p[j]-j);
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d", p+i);
        p[i]--;
    }

    vector<int> v;
    FO(i,0,n) if (!s[i]) {
        set<int> u;
        int j;
        for (j = i; !s[j]; j = p[j]) {
            u.insert(j);
            s[j] = true;
        }
        if (!u.count(j)) continue;
        v.push_back(j);
    }

    sort(v.begin(), v.end(), cmp);
    FO(i,0,n) np[i] = p[i];
    for (int x : v) np[x] = v[0];

    int r = 0;
    FO(i,0,n) r += p[i] != np[i];
    printf("%d\n", r);
    FO(i,0,n) printf("%d%c", 1+np[i], " \n"[i+1==n]);
}