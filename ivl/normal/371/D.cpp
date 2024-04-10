#include <cstdio>

using namespace std;

int n;
long long a[200005];
long long p[200005];
int m;

int gr[200005];
int un(int p){
  //  printf("%d %d\n", p, gr[p]);
    if (p == gr[p]) return p;
    return gr[p] = un(gr[p]);
}

int main(){
    for (int i = 0; i <= 200004; ++i) gr[i] = i;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%I64d", a + i);
    a[n + 1] = 1000000000000000000LL;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i){
        int t;
        scanf("%d", &t);
        if (t == 1){
           long long s;
           int x;
           scanf("%d%I64d", &x, &s);
           //printf("A");
           x = un(x);
           while (s > 0){
                 //printf("%I64d --- %d (%I64d)\n", s, x, a[x]);
                 //if (x > n + 3) return 0;
                 p[x] += s;
                 s = p[x] - a[x];
                 if (p[x] >= a[x]){p[x] = a[x]; gr[x] = x + 1;}
                 x = un(x);
           }
//           return 0;
        }
        else {
             int k;
             scanf("%d", &k);
             printf("%I64d\n", p[k]);
        }
    }
    return 0;
}