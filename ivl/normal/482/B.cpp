#include <cstdio>
#include <cstdlib>

using namespace std;

void imp(){
     printf("NO\n");
     exit(0);
}

int loga[100005];
void add(int p, int v){
     while (p <= 100000){
           loga[p] += v;
           p += (p & -p);
     }
}
int sum(int p){
    int r = 0;
    while (p){
          r += loga[p];
          p -= (p & -p);
    }
    return r;
}

int n, m;
int l[100005], r[100005], q[100005];

int cnt[100005];

int sol[100005];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i){
        scanf("%d%d%d", l + i, r + i, q + i);
    }
    for (int t = 0; t < 30; ++t){
        for (int i = 0; i < m; ++i){
            if (q[i] & (1 << t)){
               add(l[i], 1);
               add(r[i] + 1, -1);
            }
        }
        for (int i = 1; i <= n; ++i){
            if (sum(i)) cnt[i] = 1;
            else cnt[i] = 0;
        }
        for (int i = 1; i <= 100000; ++i) loga[i] = 0;
        for (int i = 1; i <= n; ++i){
            //printf("%d ", cnt[i]);
            cnt[i] += cnt[i - 1];
        }
        //printf("\n");
        for (int i = 0; i < m; ++i){
            //printf(" -- %d %d %d\n", l[i], r[i], q[i]);
            if ((q[i] & (1 << t)) == 0 && cnt[r[i]] - cnt[l[i] - 1] == r[i] - l[i] + 1) imp();
        }
        for (int i = 1; i <= n; ++i) if (cnt[i] - cnt[i - 1]) sol[i] |= (1 << t);
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i) printf("%d ", sol[i]);
    printf("\n");
    return 0;
}