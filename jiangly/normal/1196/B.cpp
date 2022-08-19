#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int q,n,k;
int a[N];
int main(){
    scanf("%d",&q);
    for(int _case=1;_case<=q;++_case){
        scanf("%d%d",&n,&k);
        int cnt=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            cnt+=(a[i]&1);
        }
        if(cnt>=k&&!((cnt-k)&1)){
            puts("YES");
            for(int i=1,j=1;j<k;++i){
                if(a[i]&1){
                    printf("%d ",i);
                    ++j;
                }
            }
            printf("%d\n",n);
        }else{
            puts("NO");
        }
    }
    return 0;
}