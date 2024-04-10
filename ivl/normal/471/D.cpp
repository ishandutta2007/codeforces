#include <cstdio>

using namespace std;

int n, w;
int a[200005], b[200005];

int kn, kw;
int ka[200005], kb[200005];

int t[200005];

int main(){
    scanf("%d%d", &n, &w);
    if (w == 1){printf("%d\n", n); return 0;}
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < w; ++i) scanf("%d", b + i);
    kn = n - 1;
    kw = w - 1;
    for (int i = 0; i < kn; ++i) ka[i] = a[i] - a[i + 1];
    for (int i = 0; i < kw; ++i) kb[i] = b[i] - b[i + 1];
    kb[kw] = 1000000001;
    
    t[0] = -1;
    t[1] = 0;
    for (int i = 2; i <= kw; ++i){
        int &tmp = t[i];
        tmp = t[i - 1];
        while (tmp >= 0 && kb[tmp] != kb[i - 1]) tmp = t[tmp];
        ++tmp;
    }
    
    int r = 0, cp = 0;
    for (int i = 0; i < kn; ++i){
        
        while (cp >= 0 && ka[i] != kb[cp]) cp = t[cp];
        ++cp;
        
        if (cp == kw){++r; cp = t[cp];}
    }
    
    printf("%d\n", r);
    
    return 0;
}