#include<stdio.h>
#include<algorithm>
using namespace std;
int a[6],b[6],c[6],s,u,sum;
int main(){
    for(int i=0;i<5;++i)scanf("%d",a+i);
    for(int i=0;i<5;++i)scanf("%d",b+i);
    scanf("%d%d",&s,&u);
    for(int i=0;i<5;++i)c[i]=500*i+500;
    for(int i=0;i<5;++i){
        sum+=max((c[i]*3/10),(c[i]*(250-a[i])/250)-(50*b[i]));
    }
    sum+=s*100;
    sum-=u*50;
    printf("%d",sum);
}