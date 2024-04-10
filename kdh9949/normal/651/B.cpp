#include <cstdio>
#include <algorithm>
using namespace std;

int n, c, cnt[1010], mx;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &c);
        cnt[c]++;
    }
    for(int i = 1; i <= 1000; i++){
        mx = max(mx, cnt[i]);
    }
    printf("%d", n - mx);
}