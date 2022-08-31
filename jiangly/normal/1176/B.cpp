#include<bits/stdc++.h>
using namespace std;
int t,n;
int cnt[3];
int main(){
    scanf("%d",&t);
    for(;t--;){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            int a;
            scanf("%d",&a);
            ++cnt[a%3];
        }
        printf("%d\n",cnt[0]+min(cnt[1],cnt[2])+abs(cnt[1]-cnt[2])/3);
        memset(cnt,0,sizeof(cnt));
    }
    return 0;
}