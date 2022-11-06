//Problem C
#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,d,a[N],b[N];
int main(){
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=a[d];for(int i=d;i<n;i++)a[i]=a[i+1];
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    //for(int i=0;i<n;i++)printf("%d ",a[i]);printf("\n");
    //for(int i=0;i<n;i++)printf("%d ",b[i]);printf("\n");
    int r=n-1;
    for(int i=1;i<n;i++)if(a[i]+b[r]<=a[0]+b[0])--r;
    //for(int i=1;i<=n;i++)if(a[i]+b[i]>a[d]+b[d])++ans;
    printf("%d",r+1);
    return 0;
}