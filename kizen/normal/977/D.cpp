#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL NS = 104;
LL N;
LL arr[NS], num[NS], start;

void out(LL x){
    LL i;
    for(i=1;i<=N;i++) if(num[i]==x) break;
    if(num[i]==x) out(i);
    printf("%I64d ", arr[x]);
}

int main(){
    scanf("%I64d", &N);
    for(LL i=1;i<=N;i++) scanf("%I64d", arr+i);
    for(LL i=1;i<=N;i++){
        for(LL j=1;j<=N;j++){
            if(arr[i]*2==arr[j]) num[i] = j;
            if(arr[i]%3==0&&arr[i]/3==arr[j]) num[i] = j;
        }
        if(num[i]==0) start = i;
    }
    out(start);

    return 0;
}