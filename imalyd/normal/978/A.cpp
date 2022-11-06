#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,a[N],b[N],m;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int f=1;
        for(int j=i+1;j<=n;j++)if(a[i]==a[j])f=0;
        if(f)b[++m]=a[i];
    }
    printf("%d\n",m);
    for(int i=1;i<=m;i++)printf("%d ",b[i]);
    return 0;
}