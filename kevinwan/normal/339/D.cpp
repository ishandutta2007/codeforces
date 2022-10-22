#include<bits/stdc++.h>
using namespace std;
int a[1<<18];
int main(){
    int n,p,i,j,w,e;
    scanf("%d%d",&n,&p);
    for(i=1<<n;i<2<<n;i++)scanf("%d",a+i);
    for(j=1;j<=n;j++){
        for(i=(1<<(n-j+1))-1;i>=1<<(n-j);i--){
            if(j&1)a[i]=a[i*2]|a[i*2+1];
            else a[i]=a[i*2]^a[i*2+1];
        }
    }
    while(p--){
        scanf("%d%d",&w,&e);
        w+=(1<<n)-1;
        a[w]=e;
        for(j=1;j<=n;j++){
            w>>=1;
            if(j&1)a[w]=a[w*2]|a[w*2+1];
            else a[w]=a[w*2]^a[w*2+1];
        }
        printf("%d\n",a[1]);
    }
}