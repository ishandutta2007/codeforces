#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#define x first
#define y second

using namespace std;

const long long oo = 1000000000000000LL;

void imp(){printf("-1\n"); exit(0);}

int gcd(int a, int b){
    while (b){a %= b; swap(a, b);}
    return a;
}

int n;
int l[305], c[305];

map < pair < int, int >, long long > M;
long long dp(int pos, int cg){
     if (pos == n){
        if (cg == 1) return 0;
        return oo;
     }
     if (M.count(make_pair(pos, cg))) return M[make_pair(pos, cg)];
     return M[make_pair(pos, cg)] = min(dp(pos + 1, cg), dp(pos + 1, gcd(cg, l[pos])) + c[pos]);
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", l + i);
    for (int i = 0; i < n; ++i) scanf("%d", c + i);
    int x = 0;
    for (int i = 0; i < n; ++i) x = gcd(x, l[i]);
    if (x != 1) imp();
    
    
    printf("%I64d\n", dp(0, 0));
    
    //for (map < pair < int, int >, long long >::iterator it = M.begin(); it != M.end(); ++it) printf("%d %d: %I64d\n", it->x.x, it->x.y, it->y);
    
    return 0;
}