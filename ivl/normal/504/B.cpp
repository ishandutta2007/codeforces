#include <cstdio>

using namespace std;

int tur[1 << 19];
int slo, shi; int sval;
void addt(int id = 1, int lo = 0, int hi = (1 << 18) - 1){
     if (lo > shi || hi < slo) return;
     if (lo == hi){
        tur[id] = sval;
        return;
     }
     int mid = (lo + hi) / 2;
     addt(id * 2, lo, mid);
     addt(id * 2 + 1, mid + 1, hi);
     tur[id] = tur[id * 2] + tur[id * 2 + 1];
}
int query(int id = 1, int lo = 0, int hi = (1 << 18) - 1){
    if (lo == hi) return lo;
    int mid = (lo + hi) / 2;
    if (slo < tur[id * 2]) return query(id * 2, lo, mid);
    slo -= tur[id * 2];
    return query(id * 2 + 1, mid + 1, hi);
}

int loga[200005];
void add(int pos){
     while (pos <= 200003){
           ++loga[pos];
           pos += (pos & -pos);
     }
}
int sum(int pos){
    int r = 0;
    while (pos){
          r += loga[pos];
          pos -= (pos & -pos);
    }
    return r;
}

int n;
int p[200005], q[200005];

int factBase[200005];
void build(int *row){
     for (int i = 0; i <= 200003; ++i) loga[i] = 0;
     for (int i = 0; i < n; ++i){
         int x = row[i];
         int cnt = x - 1 - sum(x - 1);
         factBase[n - i - 1] += cnt;
         add(x);
     }
}

int out[200005];
void generate(){
     for (int i = 1; i <= n; ++i){
         slo = shi = i;
         sval = 1;
         addt();
     }
     /*slo = 0; printf(" --- %d\n", query());
     slo = 1; printf(" --- %d\n", query());
     slo = shi = 1; sval = -1; addt();
     slo = 0; printf(" --- %d\n", query());
     return;*/
     for (int i = n - 1; i >= 0; --i){
         slo = factBase[i];
         out[n - 1 - i] = query();
         slo = shi = out[n - 1 - i];
         sval = 0;
         addt();
     }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){scanf("%d", p + i); ++p[i];}
    for (int i = 0; i < n; ++i){scanf("%d", q + i); ++q[i];}
    build(p);
    //for (int i = 0; i < n; ++i) printf("%d ", factBase[i]); printf("\n");
    build(q);
    //for (int i = 0; i < n; ++i) printf("%d ", factBase[i]); printf("\n");
    for (int i = 0; i < n; ++i){
        while (factBase[i] > i){
              factBase[i] -= i + 1;
              ++factBase[i + 1];
        }
    }
    generate();
    for (int i = 0; i < n; ++i) printf("%d ", out[i] - 1);
    return 0;
}