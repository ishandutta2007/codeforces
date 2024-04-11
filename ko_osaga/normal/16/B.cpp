#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long lint;

int cnt[15], n, m;

int main(){
    scanf("%d %d",&n,&m);
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        cnt[b] += a;
    }
    int ret = 0;
    for (int i=10; i>=0; i--) {
        ret += min(n,cnt[i]) * i;
        n -= min(n,cnt[i]);
    }
    printf("%d",ret);
}