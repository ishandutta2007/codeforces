#include<bits/stdc++.h>
using namespace std;
int n,m,a[233],t;
int main(){
    scanf("%d%d",&n,&m);
    while(n--){
        int l,r;
        scanf("%d%d",&l,&r);
        for(;l<=r;l++)a[l]=1;
    }
    for(int i=1;i<=m;i++)if(!a[i])++t;
    printf("%d\n",t);
    for(int i=1;i<=m;i++)if(!a[i])printf("%d ",i);
    return 0;
}