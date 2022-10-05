#include <cstdio>
#include <algorithm>
using namespace std;

int n, a;
int c[100010];
int ans;
int av;
int cur;

int main(){
    scanf("%d%d", &n, &a);
    for(int i = 1; i <= n; i++) scanf("%d", c + i);
    if(c[a]) ans++;
    for(int i = 1; i <= n; i++){
        av = 2; cur = 0;
        if(a + i > n) av--;
        else{
            if(c[a + i]) cur++;
        }
        if(a - i < 1) av--;
        else{
            if(c[a - i]) cur++;
        }
        if(av == cur) ans += cur;
    }
    printf("%d", ans);
}