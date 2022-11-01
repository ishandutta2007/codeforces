#include <cstdio>
#include <map>

using namespace std;

const long long MOD = 1000000000039LL;
long long F(long long x){x %= MOD; if (x < 0) x += MOD; return x;}
const long long P = 41;
long long HASH(char *r){
    if (*r == '\0') return 0;
    return F(HASH(r + 1) * P + *r);
}

map < long long, long long > M;
map < long long, int > M2;

int n, m;
char in[1000005];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i){
        scanf("%s", in);
        long long H = HASH(in);
        for (long long x = 0, cp = 1; in[x] != '\0'; ++x, cp = F(cp * P)){
            long long H2 = F(H - in[x] * cp);
            if (M.count(H2) == 0 || M[H2] != H) ++M2[H2];
            M[H2] = H;
        }
    }
    for (int i = 0; i < m; ++i){
        scanf("%s", in);
        bool r = false;
        long long H = HASH(in);
        for (long long x = 0, cp = 1; in[x] != '\0'; ++x, cp = F(cp * P)){
            long long H2 = F(H - in[x] * cp);
            if (M2[H2] == 0) continue;
            if (M[H2] == H && M2[H2] == 1) continue;
            r = true;
        }
        if (r) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}