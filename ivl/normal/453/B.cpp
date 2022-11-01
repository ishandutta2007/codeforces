#include <cstdio>
#include <algorithm>

using namespace std;

int erat[105];


const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int inv_p[105];
const int cpr = 16;

int gb[105];

int get_bit(int a){
    if (gb[a]) return gb[a];
    if (a == 1) return 0;
    return gb[a] = (get_bit(a / erat[a]) | (1 << inv_p[erat[a]]));
}

int n;
int a[105];

int limit;

bool bio[105][1 << 16];
int memo[105][1 << 16];
int dp(int pos, int bit){
    if (pos == n) return 0;
    int &r = memo[pos][bit];
    if (bio[pos][bit]++) return r;
    r = dp(pos + 1, bit) + a[pos] - 1;
    for (int i = 1; i <=58; ++i){
        int x = get_bit(i);
        if (x & bit) continue;
        r = min(r, dp(pos + 1, bit | x) + abs(a[pos] - i));
    }
    return r;
}

int main(){
    for (int i = 0; i < cpr; ++i) for (int j = primes[i]; j <= 100; j += primes[i]) erat[j] = primes[i];
    for (int i = 0; i < cpr; ++i) inv_p[primes[i]] = i;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", a + i);
        limit += a[i] - 1;
    }
    dp(0, 0);
    int cp = 0, cbit = 0;
    while (cp != n){
          int cr = dp(cp, cbit);
          for (int i = 1; i <= 58; ++i){
              int x = get_bit(i);
              if (x & cbit) continue;
              if (dp(cp + 1, cbit | x) + abs(a[cp] - i) == cr){printf("%d ", i); cbit |= x; break;}
          }
          ++cp;
    }
    return 0;
}