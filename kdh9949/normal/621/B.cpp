#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, x, y;
ll ucnt[1010][1010], dcnt[1010][1010];
ll ans;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        ucnt[x][y]++;
        dcnt[x][y]++;
    }
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            ucnt[i][j] += ucnt[i - 1][j - 1];
            dcnt[i][j] += dcnt[i - 1][j + 1];
        }
    }
    for(int i = 1; i <= 1000; i++) ans += ucnt[1000][i] * (ucnt[1000][i] - 1ll) / 2ll;
    for(int i = 1; i <= 999; i++) ans += ucnt[i][1000] * (ucnt[i][1000] - 1ll) / 2ll;
    for(int i = 2; i <= 1000; i++) ans += dcnt[1000][i] * (dcnt[1000][i] - 1ll) / 2ll;
    for(int i = 1; i <= 1000; i++) ans += dcnt[i][1] * (dcnt[i][1] - 1ll) / 2ll;
    printf("%I64d", ans);
}