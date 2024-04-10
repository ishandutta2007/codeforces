#include <cstdio>
#include <algorithm>
using namespace std;

int n, a, b, t;
char str[500010], rstr[500010];
int fr, bk;
int ct, ans = 1;

int main(){
    scanf("%d%d%d%d%s", &n, &a, &b, &t, str + 1);
    for(int i = 1; str[i]; i++) rstr[i] = str[i];
    reverse(rstr + 2, rstr + n + 1);
    fr = 1; bk = n + 1;
    if(t < ((str[1] == 'w') ? b + 1 : 1)){puts("0"); return 0;}
    ct = ((str[1] == 'w') ? b + 1 : 1);
    for(int i = n; i > 1; i--){
        if(ct + 2 * a + ((str[i] == 'w') ? b + 1 : 1) > t) break;
        ct += 2 * a + ((str[i] == 'w') ? b + 1 : 1);
        bk = i;
    }
    ans = max(ans, n - bk + 2);
    for(int i = 2; i <= n; i++){
        if(bk == n + 1) break;
        ct += a + ((str[i] == 'w') ? b + 1 : 1);
        fr = i;
        while(bk <= n && ct > t){
            ct -= 2 * a + ((str[bk] == 'w') ? b + 1 : 1);
            bk++;
        }
        if(bk == n + 1) break;
        //printf("%d %d : %d\n", fr, bk, ct);
        ans = max(ans, n - bk + fr + 1);
    }
    if(ct > t) fr--;
    for(; fr <= n;){
        if(fr == n) break;
        if(ct + a + ((str[fr + 1] == 'w') ? b + 1 : 1) > t) break;
        ct += a + ((str[fr + 1] == 'w') ? b + 1 : 1);
        fr++;
    }
    ans = max(ans, fr);
    for(int i = 1; i <= n; i++) str[i] = rstr[i];
    fr = 1; bk = n + 1; ct = 0;
    if(t < ((str[1] == 'w') ? b + 1 : 1)){puts("0"); return 0;}
    ct = (str[1] == 'w') ? b + 1 : 1;
    for(int i = n; i > 1; i--){
        if(ct + 2 * a + ((str[i] == 'w') ? b + 1 : 1) > t) break;
        ct += 2 * a + ((str[i] == 'w') ? b + 1 : 1);
        bk = i;
    }
    ans = max(ans, n - bk + 2);
    for(int i = 2; i <= n; i++){
        if(bk == n + 1) break;
        ct += a + ((str[i] == 'w') ? b + 1 : 1);
        fr = i;
        while(bk <= n && ct > t){
            ct -= 2 * a + ((str[bk] == 'w') ? b + 1 : 1);
            bk++;
        }
        if(bk == n + 1) break;
        ans = max(ans, n - bk + fr + 1);
        //printf("%d %d : %d\n", fr, bk, ct);
    }
    if(ct > t) fr--;
    for(; fr <= n;){
        if(fr == n) break;
        if(ct + a + ((str[fr + 1] == 'w') ? b + 1 : 1) > t) break;
        ct += a + ((str[fr + 1] == 'w') ? b + 1 : 1);
        fr++;
    }
    ans = max(ans, fr);
    printf("%d", min(n, ans));
}