#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
long long in[200005];

long long s[200005];
long long cm[400005];
int pm[400005];

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i){
        scanf("%I64d", in + i);
    }
    s[0] = 0;
    for (int i = 1; i <= n; ++i){
        s[i] = s[i - 1] + in[i];
        if (i - k >= 1) s[i] -= in[i - k];
    }
    long long rez = 0;
    int cx = 0, cy = 0;
    for (int i = n; i >= 1; --i){
        if (rez <= s[i] + cm[i + k]){
           rez = s[i] + cm[i + k];
           cx = i;
           cy = pm[i + k];
        }
        
        cm[i] = cm[i + 1];
        pm[i] = pm[i + 1];
        if (s[i] >= cm[i]){
           cm[i] = s[i];
           pm[i] = i;
        }
    }
    printf("%d %d\n", cx - k + 1, cy - k + 1);
    return 0;
}