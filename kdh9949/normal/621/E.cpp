#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll mod = 1000000007;

struct Matrix{
    int n;
    ll val[101][101];
    Matrix operator*(const Matrix &a) const {
        Matrix ret;
        ret.n = n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ret.val[i][j] = 0;
                for(int k = 0; k < n; k++){
                    ret.val[i][j] += val[i][k] * a.val[k][j];
                    ret.val[i][j] %= mod;
                }
            }
        }
        return ret;
    }
};

int n, b, k, x;
int c, cnt[10];
Matrix ans, cur;
ll ansx;

int main(){
    scanf("%d%d%d%d", &n, &b, &k, &x);
    for(int i = 0; i < n; i++){
        scanf("%d", &c);
        cnt[c]++;
    }
    ans.n = cur.n = x;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            ans.val[i][j] = (i == j);
            cur.val[i][j] = 0;
            for(int k = 0; k < 10; k++) cur.val[i][j] += ((10 * j + k) % x == i) * cnt[k];
        }
    }
    
    for(int i = 0; (1ll << i) <= b; i++){
        if((1ll << i) & (long long)b) ans = ans * cur;
        cur = cur * cur;
    }
    printf("%I64d", ans.val[k][0]);
}