#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int l[200005], s[200005], n, a[200005], b[200005], c;

int gl(int i) {
    return i==l[i] ? i : l[i]=gl(l[i]);
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i+1);
    FO(i,1,n+1) l[i] = i;
    vector<pair<int,int>> v(n); FO(i,0,n) v[i] = {a[i+1],i+1};
    sort(v.begin(),v.end()); reverse(v.begin(),v.end());
    for (auto p : v) {
        int i = p.second; s[i] = 1;
        if (s[i-1]) {
            int u = gl(i-1), v = gl(i);
            l[u] = v; s[v] += s[u];
        }
        if (s[i+1]) {
            int u = gl(i+1), v = gl(i);
            l[u] = v; s[v] += s[u];
        }
        int ms = s[gl(i)];
        if (ms>c) {
            FO(j,c+1,ms+1) b[j] = a[i];
            c = ms;
        }
    }
    FO(i,1,n+1) printf("%d%c", b[i], " \n"[i==n]);
}