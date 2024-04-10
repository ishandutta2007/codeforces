#include <cstdio>
#include <algorithm>
using namespace std;

struct Solver{
    int n, m;
    bool on[1000][1000];
    int cnt[1000][1000];
    void bd(){
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                cnt[x][y] = on[x][y] ? (y == 0 ? 1 : cnt[x][y - 1] + 1) : 0;
            }
        }
    }
    void flip(int x, int y){
        on[x][y] = !on[x][y];
        cnt[x][y] = on[x][y] ? (y == 0 ? 1 : cnt[x][y - 1] + 1) : 0;
        for(y++; y < m; y++){
            cnt[x][y] = on[x][y] ? (y == 0 ? 1 : cnt[x][y - 1] + 1) : 0;
        }
    }
    int query(int x, int y){
        int z = cnt[x][y];
        int l = x, r = x, maxi = (r - l + 1) * z;
        do {
            while(l > 0     && cnt[l - 1][y] >= z) l--;
            while(r < n - 1 && cnt[r + 1][y] >= z) r++;
            maxi = max(maxi, (r - l + 1) * z);
        } while(z--);
        return maxi;
    }
};

Solver sa, sb, sc, sd;

int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    sa.n = sb.n = sc.m = sd.m = n;
    sa.m = sb.m = sc.n = sd.n = m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            int xx; scanf("%d", &xx);
            sa.on[i][j] = xx;
            sb.on[n - 1 - i][m - 1 - j] = xx;
            sc.on[j][i] = xx;
            sd.on[m - 1 - j][n - 1 - i] = xx;
        }
    }
    sa.bd(); sb.bd(); sc.bd(); sd.bd();
    for(int i = 0; i < q; i++){
        int qq, x, y; scanf("%d %d %d", &qq, &x, &y); x--; y--;
        if(qq == 1) {
            sa.flip(x, y);
            sb.flip(n - 1 - x, m - 1 - y);
            sc.flip(y, x);
            sd.flip(m - 1 - y, n - 1 - x);
        } else {
            int t = sa.query(x, y);
            t = max(t, sb.query(n - 1 - x, m - 1 - y));
            t = max(t, sc.query(y, x));
            t = max(t, sd.query(m - 1 - y, n - 1 - x));
            printf("%d\n", t);
        }
    }
}