//Problem A
#include<bits/stdc++.h>
using namespace std;

int a,b,n,x[100005],y[100005],p,q;

int main(){
    scanf("%d%d",&a,&b);
    while((long long)n*(n+1)/2<=a+b)++n;--n;
    for(int i=n;i;i--){
        if(i<=a)a-=i,x[++p]=i;
        else y[++q]=i;
    }
    printf("%d\n",p);
    for(int i=1;i<=p;i++)printf("%d ",x[i]);
    printf("\n%d\n",q);
    for(int i=1;i<=q;i++)printf("%d ",y[i]);
    return 0;
}