#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<deque>
using namespace std;
int n,k;
int ans[1000005]={0};
int main()
{
    scanf("%d%d",&n,&k);
    if(n<3*k){
               printf("-1\n");
               return 0;
    }
    if(k%2==0){
        for (int i=1;i<=k;i++)ans[i]=i;
        for (int i=k+1;i<=2*k;i++)ans[i]=2*k+1-i;
        for (int i=k*2+1;i<=3*k;i++)ans[i]=i-2*k;
    }else{
          for (int i=1;i<=k;i++)ans[i]=i;
          for (int i=k+1;i<=2*k;i++)ans[i]=i-k;
          ans[2*k+1]=k;
          for (int i=2*k+2;i<=3*k;i++)ans[i]=i-2*k-1;
    }

    for (int i=3*k+1;i<=n;i++)ans[i]=1;
    int fl=0;
    for (int i=1;i<=n;i++){
        if(fl)printf(" ");
        else fl=1;
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}