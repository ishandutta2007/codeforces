#include <bits/stdc++.h>

#define fo(i,a,b) for (int i=(a); i<(b); i++)
#define sz(v) int(v.size())

#define eb emplace_back
#define pb push_back

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

#define K 43200

bool bl[K];
bool rc[K];

int main() {
    int h, m, s, t1, t2;
    scanf("%d %d %d %d %d", &h, &m, &s, &t1, &t2);
    int tm = (h * 3600 + 60 * m + s) % K;
    t1 = (t1 * 3600) % K;
    t2 = (t2 * 3600) % K;

    bl[tm * (K / 43200) % K] = true;
    bl[tm * (K / 3600) % K] = true;
    bl[tm * (K / 60) % K] = true;

    rc[t1] = true;
    fo(_,0,10) {
        fo(i,0,K) if (rc[i]) {
            int ni = (i+1)%K;
            if (!bl[ni]) rc[ni] = true;
        }
        reverse(rc, rc+K);
        reverse(bl, bl+K);
    }
    if (rc[t2]) puts("YES");
    else puts("NO");
}