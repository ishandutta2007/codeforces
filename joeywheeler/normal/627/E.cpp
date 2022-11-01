#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int h, w, n, k;

int nek[11], pre[11];
int nge[11], pge[11];
int nks, prs;

struct thing {
    int v[3005];
    int prv[3005], nxt[3005]; // prv, nxt non 0 vals
    int tot;

    void init() {
        int lp = -1;
        FO(i,0,h) {
            if (v[i]) {
                //printf("i=%d\n", i);
                prv[i] = lp;
                lp = i;
            }
        }
        lp = -1;
        for (int i = h-1; i >= 0; i--) {
            if (v[i]) {
                nxt[i] = lp;
                lp = i;
            }
        }
        tot = 0;
        int j = 0, cs = 0;
        FO(i,0,h) {
            while (j<h && cs < k) {
                cs += v[j];
                j++;
            }
            if (cs >= k) {
                tot += h-j+1;
            }
            cs -= v[i];
        }
    }

    int contrib(int i) {
        //printf("?i=%d\n", i);
        // how many use ind i
        nks = prs = 0;
        for (int j = nxt[i]; j != -1 && nks < 10; j = nxt[j]) {
            nek[nks++] = j;
        }
        for (int j = prv[i]; j != -1 && prs < 10; j = prv[j]) {
            pre[prs++] = j;
        }

        nek[nks++] = h;
        pre[prs++] = -1;

        //FO(i,0,nks) printf("nek[%d]=%d\n", i, nek[i]);
        //FO(i,0,prs) printf("pre[%d]=%d\n", i, pre[i]);

        // no more prv, nxt!!!

        FO(j,0,11) {
            nge[j] = pge[j] = 0;
        }
        int cp = -1;
        int cs = v[i];
        FO(j,0,11) {
            if (cs < j) {
                cp++;
                if (nek[cp] == h) cs += 420;
                else cs += v[nek[cp]];
            }
            nge[j] = h-(cp == -1 ? i : nek[cp]);
        }


        cp = -1;
        cs = v[i];
        FO(j,0,11) {
            if (cs < j) {
                cp++;
                if (pre[cp] == -1) cs += 420;
                else cs += v[pre[cp]];
            }
            pge[j] = (cp == -1 ? i : pre[cp]) +1;
        }
        //FO(i,0,11) printf("nge[%d]=%d\n", i, nge[i]);
        //FO(i,0,11) printf("pge[%d]=%d\n", i, pge[i]);

        int res = nge[k] * pge[0];
        FO(t,0,k) res += (nge[t]-nge[t+1]) * pge[max(k-t+v[i],0)]; // nek use = i
        //printf("res=%d\n", res);
        return res;
    }

    void dc(int i) {
        // decrement pos i
        tot -= contrib(i);
        //printf("1tot=%d\n", tot);
        v[i]--;
        tot += contrib(i);
        //printf("2tot=%d\n", tot);

        if (v[i] == 0) {
            int nk = nxt[i];
            int pr = prv[i];
            if (nk != -1) prv[nk] = pr;
            if (pr != -1) nxt[pr] = nk;
        }
    }
} t;

vector<int> y[3005];

int main() {
    scanf("%d%d%d%d", &h, &w, &n, &k);
    FO(i,0,n) {
        int x, yy; scanf("%d%d", &yy, &x); yy--; x--;
        y[x].push_back(yy);
    }
    long long ans = 0;
    FO(x,0,w) {
        FO(yy,0,h) t.v[yy] = 0;
        //first x at x
        FO(j,x,w) {
            for (int yy : y[j]) t.v[yy]++;
        }
        t.init();
        //printf("x=%d, tot=%d\n", x, t.tot);
        ans += t.tot;
        for (int j = w-1; j > x; j--) {
            for (int yy : y[j]) t.dc(yy);
            ans += t.tot;
        }
    }
    printf("%lld\n", ans);
}