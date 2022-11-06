//Problem B
#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],x[100005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)scanf("%d",&b[i]);
    for(x[1]=0;x[1]<4;x[1]++){
        int f=1;
        for(int i=1;i<n;i++)x[i+1]=a[i]+b[i]-x[i];
        for(int i=1;i<n;i++)if((x[i]|x[i+1])!=a[i]||(x[i]&x[i+1])!=b[i])f=0;
        for(int i=1;i<=n;i++)if(x[i]<0||x[i]>3)f=0;
        if(f){
        printf("YES\n");
        for(int i=1;i<=n;i++)printf("%d ",x[i]);
        return 0;}
    }
    printf("NO");
    return 0;
}