#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, m;
bool r[100010], c[100010];
int rc, cc;
ll ans;

int main(){
    scanf("%d%d", &n, &m);
    ans = (ll)n * n;
    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        if(!r[x]){
            r[x] = true;
            rc++;
            ans -= (ll)(n - cc);
        }
        if(!c[y]){
            c[y] = true;
            cc++;
            ans -= (ll)(n - rc);
        }
        printf("%lld ", ans);
    }
}