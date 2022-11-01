#include <cstdio>

using namespace std;

const int M = 1000000007;
const int P = 101;

char s[100005], t[100005];
int sl, tl;

long long hs[100005];
long long ht;
long long pw[100005];

long long hash(int a, int b){ // [a,b]
     if (a == 0) return hs[b];
     long long r = hs[b] - hs[a - 1] * pw[b - a + 1];
     r %= M;
     if (r < 0) return r + M;
     return r;
}

bool valid[100005];
int nxt[100005];

long long dpp[100005];
long long dpp2[100005];

long long f(long long a){a %= M; if (a < 0) return a + M; return a;}

int main(){ pw[0] = 1; for (int i = 1; i <= 100000; ++i) pw[i] = (pw[i - 1] * P) % M;
    scanf("%s%s", s, t);
    while (s[sl] != '\0') ++sl;
    while (t[tl] != '\0') ++tl;
    hs[0] = s[0];
    for (int i = 1; i < sl; ++i) hs[i] = (P * hs[i - 1] + s[i]) % M;
    for (int i = 0; i < tl; ++i) ht = (ht * P + t[i]) % M;
    for (int i = 0; i < sl; ++i){
        if (i + tl - 1 >= sl) break;
        long long x = hash(i, i + tl - 1);
        if (x == ht) valid[i] = true;
    }
    int a = -1;
    for (int i = sl - 1; i >= 0; --i){
        if (valid[i]) a = i;
        nxt[i] = a;
    }
    dpp[sl] = 0;
    for (int i = sl - 1; i >= 0; --i){
        if (nxt[i] == -1){dpp[i] = 0; continue;}
        dpp[i] = f(dpp[i + 1] + dpp2[nxt[i] + tl] + (sl - nxt[i] - tl + 1));
        dpp2[i] = f(dpp[i] + dpp2[i + 1]);
    }
    printf("%I64d\n", f(dpp[0]));
    return 0;
}