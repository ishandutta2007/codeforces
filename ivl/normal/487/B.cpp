#include <cstdio>
#include <algorithm>
#define x first
#define y second

using namespace std;

pair < int, int > merge(pair < int, int > a, pair < int, int > b){return make_pair(min(a.x, b.x), max(a.y, b.y));}
int m2(int a, int b){return min(a, b);}

pair < int, int > tur[1 << 18];
int slo, shi, sval;
void set(int id = 1, int lo = 0, int hi = (1 << 17) - 1){
     if (lo > slo || hi < slo) return;
     if (lo == hi){tur[id].x = tur[id].y = sval; return;}
     set(id * 2, lo, (lo + hi) / 2);
     set(id * 2 + 1, (lo + hi + 1) / 2, hi);
     tur[id] = merge(tur[id * 2], tur[id * 2 + 1]);
}
pair < int, int > ask(int id = 1, int lo = 0, int hi = (1 << 17) - 1){
     if (lo > shi || hi < slo) return make_pair(1000000000, -1000000000);
     if (lo >= slo && hi <= shi) return tur[id];
     return merge(ask(id * 2, lo, (lo + hi) / 2), ask(id * 2 + 1, (lo + hi + 1) / 2, hi));
}

int t2[1 << 18];
void set2(int id = 1, int lo = 0, int hi = (1 << 17) - 1){
     if (lo > slo || hi < slo) return;
     if (lo == hi){t2[id] = sval; return;}
     set2(id * 2, lo, (lo + hi) / 2);
     set2(id * 2 + 1, (lo + hi + 1) / 2, hi);
     t2[id] = m2(t2[id * 2], t2[id * 2 + 1]);
}
int ask2(int id = 1, int lo = 0, int hi = (1 << 17) - 1){
    if (lo > shi || hi < slo) return 1000000000;
    if (lo >= slo && hi <= shi) return t2[id];
    return m2(ask2(id * 2, lo, (lo + hi) / 2), ask2(id * 2 + 1, (lo + hi + 1) / 2, hi));
}

int n, s, l;
int a[100005];
int pt[100005];

int main(){
    for (int i = 0; i < (1 << 18); ++i) tur[i].x = tur[i].y = 1000000000;
    
    scanf("%d%d%d", &n, &s, &l);
    for (int i = 0; i < n; ++i){
        scanf("%d", a + i);
        slo = shi = i;
        sval = a[i];
        set();
    }
    
    for (int i = 0; i < n; ++i){
        int lo = i, hi = n - 1, mid = (lo + hi + 1) / 2;
        while (lo != hi){
              slo = i; shi = mid; pair < int, int > p = ask();
              if (p.y - p.x > s) hi = mid - 1;
              else lo = mid;
              mid = (lo + hi + 1) / 2;
        }
        pt[i] = mid;
        //printf("%d ", pt[i]);
    }
    //printf("\n");
    #define set BLABLABLA
    #define ask BLABLABLA
    for (int i = n; i >= 0; --i){
        if (i == n){
           slo = shi = i;
           sval = 0;
           set2();
           continue;
        }
        if (/*i + l > n || */pt[i] - i + 1 < l){
           slo = shi = i;
           sval = 1000000000;
           set2();
           continue;
        }
        //printf(" --- %d\n", i);
        slo = i + l; shi = pt[i] + 1; int curr = ask2();
        if (curr == 1000000000) sval = 1000000000;
        else sval = curr + 1;
        slo = shi = i; set2();
    }
    
    //for (int i = 0; i <= n; ++i){slo = shi = i; printf("%d\n", ask2());}
    
    slo = shi = 0;
    int r = ask2();
    if (r == 1000000000) r = -1;
    printf("%d\n", r);
    
    return 0;
}