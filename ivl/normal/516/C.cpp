#include <cstdio>
#include <algorithm>

using namespace std;

const int BAD = -42;
class node{
      public:
      long long TT, TL, TR, sum;
      node(long long a = 0, long long b = 0, long long c = 0, long long d = 0) : TT(a), TL(b), TR(c), sum(d){}
};
node merge(node a, node b, int D){
     if (a.TT == BAD) return b;
     if (b.TT == BAD) return a;
     node r;
     r.TT = max(a.TT, b.TT);
     r.TT = max(r.TT, a.TR + D + b.TL);
     r.sum = a.sum + D + b.sum;
     r.TL = max(b.TL + D + a.sum, a.TL);
     r.TR = max(a.TR + D + b.sum, b.TR);
     
     return r;
}

int n, m;
int d[500005];
int h[500005];

const int offset = 1 << 18;
node TUR[offset * 2];
void TUR_INIT(int id = 1, int lo = 0, int hi = offset - 1){
     node &T = TUR[id];
     if (lo == hi){
        T.TT = T.sum = 0, T.TL = T.TR = 2 * h[lo];
        return;
     }
     int mid = (lo + hi) / 2;
     TUR_INIT(id * 2, lo, mid);
     TUR_INIT(id * 2 + 1, mid + 1, hi);
     T = merge(TUR[id * 2], TUR[id * 2 + 1], d[mid]);
}
node query(int id, int lo, int hi, int slo, int shi){
     if (lo > shi || hi < slo) return node(BAD);
     if (lo >= slo && hi <= shi) return TUR[id];
     int mid = (lo + hi) / 2;
     return merge(
              query(id * 2, lo, mid, slo, shi),
              query(id * 2 + 1, mid + 1, hi, slo, shi),
              d[mid]
            );
}
long long query(int lo, int hi){
     if (lo > hi) return 0;
     node X =  query(1, 0, offset - 1, lo, hi);
     //printf("%I64d\n", X.sum);
     return X.TT;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", d + i);
    for (int i = 0; i < n; ++i) scanf("%d", h + i);
    for (int i = 0; i < n; ++i) d[n + i] = d[i], h[n + i] = h[i];
    TUR_INIT();
    //printf(" -- %I64d\n", query(0, n - 1));
    for (int i = 0; i < m; ++i){
        int a, b;
        scanf("%d%d", &a, &b); --a, --b;
        long long r = 0;
        if (a <= b){
           r = max(r, query(0, a - 1));
           r = max(r, query(b + 1, a - 1 + n));
           r = max(r, query(b + 1 + n, n + n - 1));
        }
        else {
             r = max(r, query(b + 1, a - 1));
             r = max(r, query(b + n + 1, a + n - 1));
        }
        printf("%I64d\n", r);
    }
    return 0;
}