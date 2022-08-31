#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n;
struct node{
    int a,b;
}t[5005];
int cmp(const node&x,const node&y){
    if(x.a==y.a)return x.b<y.b;
    else return x.a<y.a;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d%d",&t[i].a,&t[i].b);
    sort(t+1,t+1+n,cmp);
    int cur=0;
    for (int i=1;i<=n;i++){
        if(t[i].b>=cur)cur=t[i].b;
        else cur=t[i].a;
    }
    printf("%d\n",cur);
    return 0;
}