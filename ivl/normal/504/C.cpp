#include <cstdio>
#include <algorithm>

using namespace std; // sweep

int n;
int a[100005];
int b[100005]; // b = inv(a)

bool prefGood[100005], suffGood[100005]; // suff zanemariv
bool midGood[100005];

int cnt[100005];
int g1 = 0, g2 = 0, neg = 0; int lo = 1, hi = 0; int lo2 = n + 1, hi2 = n;
void add(int x){// printf("A %d\n", x);
     if (cnt[x] < 0) --neg;
     else {
          g2 -= cnt[x] / 2;
          if (cnt[x] & 1) --g1;
     }
     ++cnt[x];
     if (cnt[x] < 0) ++neg;
     else {
          g2 += cnt[x] / 2;
          if (cnt[x] & 1) ++g1;
     }
}
void rem(int x){// printf("R %d\n", x);
     if (cnt[x] < 0) --neg;
     else {
          g2 -= cnt[x] / 2;
          if (cnt[x] & 1) --g1;
     }
     --cnt[x];
     if (cnt[x] < 0) ++neg;
     else {
          g2 += cnt[x] / 2;
          if (cnt[x] & 1) ++g1;
     }
}

bool GOOD(){//printf("%d %d [%d] (%d, %d)\n", lo, hi, cnt[2], lo2, hi2);
     if (lo > hi || neg != 0) return false;
     int x = min(lo, n + 1 - hi); //printf("passed cnt\n");
     if (!prefGood[x - 1]) return false; //printf("passed prefix\n");
     if (hi < (n + 1) / 2){
        int x = hi + 1;
        if (!midGood[x]) return false;
     } //printf("passed m1\n");
     if (lo > (n + 2) / 2){
        int x = lo - 1;
        x = n + 1 - x;// printf("m2 %d\n", x);
        if (!midGood[x]) return false;
     } //printf("passed m2\n");
     
     int pres = max(0, max(hi - (n + 1 - hi) + 1, n + 1 - lo - lo + 1));
     //printf("passed added [%d, %d, %d]\n", g1, g2, pres);
     if (g2 - pres / 2 > 0) return false; //printf("A");
     if (g1 > 1) return false;// printf("A");
     if (g1 == 1 && (n % 2 == 0 || pres == 0)) return false;
     //printf("passed\n");
     
     return true;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= n; ++i) b[i] = a[n + 1 - i];
    prefGood[0] = true;
    for (int i = 1; i <= n; ++i) prefGood[i] = prefGood[i - 1] && (a[i] == b[i]);
    suffGood[0] = true;
    for (int i = 1; i <= n; ++i) suffGood[i] = suffGood[i - 1] && (a[n + 1 - i] == b[n + 1 - i]);
    
    int x = (n + 1) / 2;
    midGood[x] = (a[x] == b[x]);
    for (int i = x - 1; i >= 0; --i) midGood[i] = midGood[i + 1] && (a[i] == b[i]);
    
    //printf(" --- "); for (int i = 1; i <= x; ++i) printf("%d ", (int)midGood[i]); printf("\n");
    
    long long r = 0; lo2 = n + 1; hi2 = n;
    while (lo <= n){
          while (hi < n && !GOOD()){
                ++hi;
                add(a[hi]);
                if (hi >= lo2 && hi <= hi2) add(a[hi]);
                --lo2;
                if (lo2 < lo || lo2 > hi) rem(a[lo2]);
          }
          if (!GOOD()) break;
          r += n - hi + 1;
          rem(a[lo]); if (lo >= lo2 && lo <= hi2) rem(a[lo]);
          ++lo;
          if (hi2 < lo || hi2 > hi) add(a[hi2]);
          --hi2;
    }
    printf("%I64d\n", r);
    return 0;
}