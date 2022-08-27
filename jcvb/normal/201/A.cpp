#include<cstring>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int ans=1000000;
int x;
int workeven(){
    int p=x/4;
    for (int n=2;n<=200;n+=2)if((((n/2-1)*(n/2-1)+1)/2)>=p)return n;
}
int workodd(){
    if(x&1)x--;
    for (int n=1;n<=200;n+=2){
        int nn=(n+1)/2;
        int p=(nn*nn)/2;
        p=p*4-(nn/2)*4;
        if(p>=x)return n;
    }
}
int main()
{
    scanf("%d",&x);
    if(x<=1){
        printf("1\n");
        return 0;
    }if(x==3){
        printf("5\n");
        return 0;
    }
    if(x%4==0)ans=min(ans,workeven());
    ans=min(ans,workodd());
    printf("%d\n",ans);
    return 0;
}