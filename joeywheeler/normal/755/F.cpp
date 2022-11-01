#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int p[1000005];
int c[1000005];
bool s[1000005];
int n, k;
vector<int> v;

bitset<1000001> can;

int main() {
    scanf("%d %d", &n, &k);
    FO(i,1,n+1) {
        scanf("%d", p+i);
    }
    FO(i,1,n+1) if (!s[i]) {
        int nm = 1;
        for (int j = p[i]; j != i; j = p[j]) {
            nm++;
            s[j] = true;
        }
        s[i] = true;

        c[nm]++;

        int nm2 = nm;
        FO(z,0,nm) {
            v.push_back(min(nm2,2));
            nm2 -= v.back();
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    int rmax = 0, rmin = 0;
    FO(i,0,k) rmax += v[i];

    can[0] = 1;
    FO(i,0,1000005) if (c[i]) {
        int gs = i, cnt = c[i], cm = 1;
        while (cnt >= cm) {
            can |= can << (gs * cm);
            cnt -= cm;
            cm *= 2;
        }
        if (cnt) {
            can |= can << (gs * cnt);
        }
    }
    if (can[k]) rmin = k;
    else rmin = k+1;

    printf("%d %d\n", rmin, rmax);
}