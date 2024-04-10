#include <cstdio>
#include <algorithm>
#define x first
#define y second

using namespace std;

long long tsum[1 << 18];
int tmax[1 << 18];
int tpos[1 << 18];
int slo, shi, sval;
void set(int p = 1, int l = 0, int d = (1 << 17) - 1){
     if (l > slo || d < slo) return;
     if (l == d){tsum[p] = tmax[p] = sval; tpos[p] = l; return;}
     set(p * 2, l, (l + d) / 2);
     set(p * 2 + 1, (l + d + 1) / 2, d);
     tsum[p] = tsum[p * 2] + tsum[p * 2 + 1];
     tmax[p] = max(tmax[p * 2], tmax[p * 2 + 1]);
     if (tmax[p] == tmax[p * 2]) tpos[p] = tpos[p * 2];
     else tpos[p] = tpos[p * 2 + 1];
}
long long suma(int p = 1, int l = 0, int d = (1 << 17) - 1){
     if (l > shi || d < slo) return 0;
     if (l >= slo && d <= shi) return tsum[p];
     return
           suma(p * 2, l, (l + d) / 2) + 
           suma(p * 2 + 1, (l + d + 1) / 2, d);
}
pair < int, int > maks(int p = 1, int l = 0, int d = (1 << 17) - 1){
     if (l > shi || d < slo) return make_pair(-1, -1);
     if (l >= slo && d <= shi) return make_pair(tmax[p], tpos[p]);
     return max(
            maks(p * 2, l, (l + d) / 2),
            maks(p * 2 + 1, (l + d + 1) / 2, d)
     );
}

int n, m;
int a[100005];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        scanf("%d", a + i);
        slo = shi = i;
        sval = a[i];
        set();
    }
    for (int i = 0; i < m; ++i){
        int type;
        scanf("%d", &type);
        if (type == 1){
           scanf("%d%d", &slo, &shi);
           --slo;
           --shi;
           printf("%I64d\n", suma());
        }
        if (type == 2){
           int l, r, x;
           scanf("%d%d%d", &l, &r, &x);
           --l;
           --r;
           slo = l;
           shi = r;
           for (pair < int, int > p = maks(); p.x >= x; p = maks()){
               a[p.y] %= x;
               slo = shi = p.y;
               sval = a[p.y];
               set();
               slo = l;
               shi = r;
           }
        }
        if (type == 3){
           int k, x;
           scanf("%d%d", &k, &x);
           slo = shi = k - 1;
           sval = x;
           a[k - 1] = x;
           set();
        }
    }
    return 0;
}