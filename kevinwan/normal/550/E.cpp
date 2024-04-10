#include<bits/stdc++.h>
using namespace std;
const int mn=1e5+10;
int a[mn];
void die(){
    printf("NO\n");
    exit(0);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    if(a[n-1])die();
    else if(n==1){
        printf("YES\n0");
        return 0;
    }
    else if(a[n-2]){
        printf("YES\n%d",a[0]);
        for(int i=1;i<n;i++)printf("->%d",a[i]);
        return 0;
    }
    else{
        int pos=-1;
        for(int i=0;i<n-2;i++)if(!a[i])pos=i;
        if(pos==-1)die();
        printf("YES\n");
        for(int i=0;i<pos;i++)printf("%d->",a[i]);
        for(int i=pos;i<=n-3;i++)printf("(%d->",a[i]);
        printf("%d",a[n-2]);
        for(int i=pos;i<=n-3;i++)printf(")");
        printf("->0");
    }
}