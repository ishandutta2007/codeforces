//Problem C
#include<bits/stdc++.h>
using namespace std;

int n,x[200005],u;
char a[100005];

int main(){
    scanf("%s",a+1),n=strlen(a+1);
    for(int i=1;i<n;i++)x[i]=x[i+n]=(a[i]!=a[i+1]);
    x[n]=x[n<<1]=(a[1]!=a[n]);
    int f=1;
    for(int i=1;i<=n;i++)f&=x[i];
    //for(int i=1;i<=(n<<1);i++)printf("%d",x[i]);
    if(f)printf("%d",n);
    else{
        int cur=0;
        for(int i=1;i<=(n<<1);i++){
            if(x[i])u=max(u,++cur);
            else cur=0;//printf("%d %d\n",i,cur);
        }
        printf("%d",u+1);
    }
    
    return 0;
}