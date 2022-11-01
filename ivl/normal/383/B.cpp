#include <cstdio>
#define x first
#define y second
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int oo = 1500000000;

int n, m;
pair < int, int > in[500005];

vector < int > h;
map < int, int > M;

int tur[1 << 20], slo, shi, sval, lazy[1 << 20];
bool ll[1 << 20];

void init(int pos = 1, int lo = 0, int hi = (1 << 19) - 1){
     tur[pos] = oo;
     if (lo == hi) return;
     init(pos * 2, lo, (lo + hi) >> 1);
     init(pos * 2 + 1, (lo + hi + 1) >> 1, hi);
}

void update(int pos, int lo, int hi){
     if (ll[pos]){
        lazy[pos * 2] = lazy[pos * 2 + 1] = lazy[pos];
        ll[pos * 2] = ll[pos * 2 + 1] = true;
        ll[pos] = false;
        if (lazy[pos]){
           tur[pos * 2] = lo;
           tur[pos * 2 + 1] = (lo + hi + 1) >> 1;
        }
        else tur[pos * 2] = tur[pos * 2 + 1] = oo;
     }
}

void set(int pos = 1, int lo = 0, int hi = (1 << 19) - 1){
     if (lo > shi || hi < slo) return;
     if (lo >= slo && hi <= shi){
        lazy[pos] = sval;
        ll[pos] = true;
        if (sval) tur[pos] = lo; else tur[pos] = oo;
        return;
     }
     update(pos, lo, hi);
     set(pos * 2, lo, (lo + hi) >> 1);
     set(pos * 2 + 1, (lo + hi + 1) >> 1, hi);
     tur[pos] = min(tur[pos * 2], tur[pos * 2 + 1]);
     //printf("%d %d == %d\n", lo, hi, tur[pos]);
}

int mini(int pos = 1, int lo = 0, int hi = (1 << 19) - 1){
    if (lo > shi || hi < slo) return oo;
    if (lo >= slo && hi <= shi) return tur[pos];
    update(pos, lo, hi);
    return min(mini(pos * 2, lo, (lo + hi) >> 1), mini(pos * 2 + 1, (lo + hi + 1) >> 1, hi));
}

int main(){
    init();
    h.push_back(1);
    scanf("%d%d", &n, &m);
    h.push_back(n);
    for (int i = 0; i < m; ++i){
        scanf("%d%d", &in[i].x, &in[i].y);
        h.push_back(in[i].y);
        if (in[i].y - 1 != 0) h.push_back(in[i].y - 1);
        if (in[i].y + n <= n) h.push_back(in[i].y + 1);
    }
    sort(h.begin(), h.end());
    int p = 1;
    for (int i = 0; i < h.size(); ++i) if (M[h[i]] == 0) M[h[i]] = p++;
    sval = 1;
    slo = M[1];
    shi = M[1];
    set();
    int bbbb = p;
    p = m;
    for (int i = 0; i < m; ++i){
        in[p++] = make_pair(in[i].x, -1);
        if (in[i].x - 1 != 0) in[p++] = make_pair(in[i].x - 1, -1);
        if (in[i].x + 1 <= n) in[p++] = make_pair(in[i].x + 1, -1);
    }
    m = p;
    sort(in, in + m);
    if (in[0].x != 1){
       shi = M[n];
       set();
    }
    for (int i = 0, j = 0; i < m; i = j){/*
        for (int k = 1; k < bbbb; ++k){
            slo = shi = k;
            printf("%d ", (int)mini());
        }
        printf("\n");*/
        while (j < m && in[j].x == in[i].x) ++j;
        int prev = 0;
        for (int k = i; k < j; ++k){
            if (in[k].y == -1) continue;
            slo = prev;
            shi = M[in[k].y] - 1;
            int x = mini();
            if (x != oo){
               slo = x;
               sval = 1;
               set();
            }
            slo = shi = M[in[k].y];
            sval = 0;
            set();
            prev = M[in[k].y] + 1;
        }
        slo = prev;
        shi = M[n];
        //printf("%d %d\n", slo, shi);
        int x = mini();
        //printf("%d\n", x);
        if (x != oo){
           slo = x;
           sval = 1;
           //printf("-----------> \n");
           set();
           //printf("<-----------\n");
           //system("pause");
        }
    }/*
        for (int k = 1; k < bbbb; ++k){
            slo = shi = k;
            printf("%d ", (int)mini());
        }
        printf("\n");*/
    slo = shi = M[n];
    if (in[m - 1].x != n) slo = M[1];
    if (mini() != oo) printf("%d\n", n * 2 - 2);
    else printf("-1\n");
    return 0;
}