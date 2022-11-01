#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

void imp(){printf("0\n"); exit(0);}

class UnionFind{
      public:
      int *gr;
      int N;
      UnionFind(int _N = 200005){N = _N; gr = new int[N]; for (int i = 0; i < N; ++i) gr[i] = i;}
      int un(int x){if (x == gr[x]) return x; return gr[x] = un(gr[x]);}
      void join(int a, int b){if (un(a) > un(b)) swap(a, b); gr[un(b)] = un(a);}
} G1, G2;

int n, k;
int inv(int x){if (x <= 100000) return x + 100001; return x - 100001;}

int main(){
    scanf("%d%d", &n, &k); char x[2];
    
    for (int i = 0; i < k; ++i){
        int a, b, c;
        scanf("%d%d%s", &a, &b, &x); c = (*x == 'o');
        int lo, hi;
        lo = b - a + 1;
        hi = b + a - 1;
        UnionFind *G;
        if (lo & 1) G = &G1; else G = &G2;
        if (lo < 1) lo = 2 - lo;
        if (hi > n) hi = 2 * n - hi;
        lo = (lo + 1) / 2;
        hi = (hi + 1) / 2;
        --lo;
        //printf(" --- %d %d\n", lo, hi);
        if (!c) G->join(lo, hi), G->join(inv(lo), inv(hi));
        else G->join(inv(lo), hi), G->join(lo, inv(hi));
    }
    //printf("%d %d %d\n", G1.un(0), G1.un(1), G1.un(2));
    for (int i = 0; i <= n; ++i) if (G1.un(i) == G1.un(inv(i)) || G2.un(i) == G2.un(inv(i))) imp();
    //for (int i = 0; i <= n; ++i) printf("%d %d\n", G2.un(i), G2.un(inv(i)));
    for (int i = 0; i <= n; ++i) G1.join(i, inv(i)), G2.join(i, inv(i));
    
    int cnt = 0;
    int up = (n + 1) / 2;
    for (int i = 1; i <= up; ++i) if (G1.gr[i] == i) ++cnt/*, printf("%d\n", i)*/;
    up = n / 2;
    for (int i = 1; i <= up; ++i) if (G2.gr[i] == i) ++cnt/*, printf("%d\n", i)*/;
    
    int R = 1;
    for (int i = 0; i < cnt; ++i)
        R = (R * 2) % 1000000007;
    
    printf("%d\n", R);
    
    return 0;
}