#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

#define SQRT 320

deque<int> d[SQRT];
int c[SQRT][100000];
int n;

void pd() {
    FO(i,0,SQRT) {
        FO(j,0,sz(d[i])) {
            printf("%d ", d[i][j]);
        }
    }
    printf("\n");
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        int x; scanf("%d", &x);
        d[i/SQRT].push_back(x);
        c[i/SQRT][x]++;
    }
    //pd();
    int q;
    scanf("%d", &q);
    int la = 0;
    FO(i,0,q) {
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        l = (l + la - 1) % n;
        r = (r + la - 1) % n;
        if (l > r) swap(l,r);
        if (t == 1) {
            int bl = l/SQRT;
            int br = r/SQRT;
            int v = d[br][r%SQRT];
            int _ = 0;
            deque<int>::iterator it = d[br].begin();
            while (_ < r%SQRT) it++, _++;
            d[br].erase(it);
            c[br][v]--;
            _ = 0;
            it = d[bl].begin();
            while (_ < l%SQRT) it++, _++;
            d[bl].insert(it, v);
            c[bl][v]++;

            FO(i,bl,br) {
                int x = d[i].back();
                d[i].pop_back();
                c[i][x]--;
                d[i+1].push_front(x);
                c[i+1][x]++;
            }
        } else {
            int k; scanf("%d", &k);
            k = (k + la - 1) % n;
            k++;
            int res = 0;
            int bl = l/SQRT;
            int br = r/SQRT;
            if (bl == br) {
                FO(i,l,r+1) res += d[i/SQRT][i%SQRT] == k;
            } else {
                FO(i,l,(bl+1)*SQRT) res += d[i/SQRT][i%SQRT] == k;
                FO(i,br*SQRT,r+1) res += d[i/SQRT][i%SQRT] == k;
                FO(i,bl+1,br) res += c[i][k];
            }
            printf("%d\n", res);
            la = res;
        }
        //pd();
    }
}