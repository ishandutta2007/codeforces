#include <cstdio>
typedef long long lint;

int n;
lint a[500005], sum[500005];
lint first[500005], second[500005];

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%I64d",&a[i]);
        if(i == 0) sum[i] = a[i];
        else sum[i] = sum[i-1] + a[i];
    }
    if(sum[n-1]%3 != 0){
        puts("0");
        return 0;
    }
    lint t = sum[n-1]/3;
    for (int i=0; i<n; i++) {
        if(sum[i] == t){
            first[i] ++;
        }
        if(sum[i] == t*2){
            second[i] ++;
        }
    }
    for (int i=1; i<n; i++) {
        second[i] += second[i-1];
    }
    lint res = 0;
    for (int i=0; i<n-1; i++) {
        res += first[i] * (second[n-2] - second[i]);
    }
    printf("%I64d",res);
}