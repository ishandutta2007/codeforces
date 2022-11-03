#include <stdio.h>
#include <stdlib.h>


int main() {
    int a[100005];
    int b[100005];
    int cnt[100005];
    for(int i = 0; i < 100005; ++i){
        cnt[i] = 0;
    }
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    l--;
    r--;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < l; ++i){
        if(a[i] != b[i]){
            printf("LIE\n");
            return 0;
        }
    }
    for(int i = r + 1; i < n; ++i){
        if(a[i] != b[i]){
            printf("LIE\n");
            return 0;
        }
    }
    for(int i = l; i <= r; ++i){
        cnt[a[i]]++;
        cnt[b[i]]--;
    }
    for(int i = 0; i <= n; ++i){
        if(cnt[i] != 0){
            printf("LIE\n");
            return 0;
        }
    }
    printf("TRUTH\n");
    return 0;
}