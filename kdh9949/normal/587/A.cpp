#include <stdio.h>
#include <algorithm>

int table[1000110],n,cur,ans;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&cur);
        table[cur]++;
    }
    for(int i=0;i<=1000101;i++){
        table[i+1]+=table[i]/2;
        table[i]%=2;
        ans+=table[i];
    }
    printf("%d",ans);
}