#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lint;

int a[100005], n, m;
int tmp[100005];

int trial(lint x){
    memcpy(tmp,a,sizeof(tmp));
    int pos = n;
    for (int i=0; i<m; i++) {
        while(pos && tmp[pos] == 0){
            pos--;
        }
        if(pos == 0) break;
        lint quota = x - pos;
        while (quota && pos) {
            lint diff = min(quota, 1ll * tmp[pos]);
            tmp[pos] -= diff;
            quota -= diff;
            if(tmp[pos] == 0) pos--;
        }
    }
    while (pos) {
        if(tmp[pos]) return 0;
        pos--;
    }
    return 1;
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    while (a[n] == 0) {
        n--;
    }
    lint s = n, e = 1e15;
    while (s != e) {
        lint m = (s + e)/2;
        if(trial(m)) e = m;
        else s = m+1;
    }
    printf("%lld",s);
}