#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
char str[100010], ans[100010];

int main(){
    scanf("%d%d", &n, &k);
    scanf("%s", str);
    for(int i = 0; i < n; i++){
        if(!k) break;
        int t = max(str[i] - 'a', 'z' - str[i]);
        if(t <= k) ans[i] = (str[i] - 'a' < 'z' - str[i]) ? ('z') : ('a'), k -= t;
        else ans[i] = (str[i] - k >= 'a') ? (str[i] - k) : (str[i] + k), k = 0;
    }
    if(k) puts("-1");
    else{
        for(int i = 0; i < n; i++) putchar(ans[i] ? ans[i] : str[i]);
    }
}