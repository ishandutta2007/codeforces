#include <cstdio>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;
constexpr int block_size = 317;
constexpr int blocks = 317;
constexpr int maxvalue = 100000;
deque<int> dq[blocks];
int ms[blocks][maxvalue + 1];

inline int block_of(int i) { return i / block_size; }

void rotate(int l, int r) {
    int bl = block_of(l), br = block_of(r - 1);
    if(bl == br) {
        rotate(dq[bl].begin() + (l     - block_size * bl),
               dq[bl].begin() + (r - 1 - block_size * bl),
               dq[bl].begin() + (r     - block_size * bl));
    } else {
        int rr = dq[br][(r - 1) % block_size];
        dq[br].erase(dq[br].begin() + (r - 1) % block_size);
        ms[br][rr]--;

        dq[bl].insert(dq[bl].begin() + l % block_size, rr);
        ms[bl][rr]++;
        for(int i = bl, j = bl + 1; j <= br; i++, j++) {
            int bk = dq[i].back();
            dq[i].pop_back();
            ms[i][bk]--;
            dq[j].push_front(bk);
            ms[j][bk]++;
        }
    }
}
int count(int l, int r, int k) {
    int cnt = 0;
    for(int i = block_of(l); i <= block_of(r - 1); i++) {
        int nl = i * block_size, nr = (i + 1) * block_size;
        if(l <= nl && nr <= r) {
            cnt += ms[i][k];
        } else {
            for(int j = max(l - nl, 0); j < min(r - nl, (int) dq[i].size()); j++)
                if(dq[i][j] == k)
                    cnt++;
        }
    }
    return cnt;
}
/*
void debug() {
    printf(">");
    for(const auto& dq0: dq) {
        for(int i : dq0)
            printf(" %d", i);
        if(!dq0.empty())
            printf(";");
    }
    puts("");
}
*/
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        dq[block_of(i)].push_back(x);
        ms[block_of(i)][x]++;
    }
    int q;
    scanf("%d", &q);
    int lastans = 0;
    for(int i = 0; i < q; i++) {
        int cmd;
        scanf("%d", &cmd);
        if(cmd == 1) {
            int l, r;
            scanf("%d %d", &l, &r);
            l = (l + lastans - 1) % n + 1;
            r = (r + lastans - 1) % n + 1;
            if(l > r) swap(l, r);
            l--;
            rotate(l, r);
//            debug();
        } else if(cmd == 2) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            l = (l + lastans - 1) % n + 1;
            r = (r + lastans - 1) % n + 1;
            k = (k + lastans - 1) % n + 1;
            if(l > r) swap(l, r);
            l--;
            printf("%d\n", lastans = count(l, r, k));
        }
    }
}