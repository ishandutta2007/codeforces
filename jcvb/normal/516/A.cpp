#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
int deg[10]={0};
char str[10];
int ans[10]={0};

void add(int x,int fl){
    if(x<=1)return;
    for (int i=2;i<=7;i++)while(x%i==0)deg[i]+=fl,x/=i;
}
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    for (int i=1;str[i];i++){
        for (int k=str[i]-'0';k>=1;k--)add(k,1);
    }
    while(deg[7]){
        ans[7]++;
        for (int i=1;i<=7;i++)add(i,-1);
    }
    while(deg[5]){
        ans[5]++;
        for (int i=1;i<=5;i++)add(i,-1);
    }
    while(deg[3]){
        ans[3]++;
        for (int i=1;i<=3;i++)add(i,-1);
    }
    while(deg[2]){
        ans[2]++;
        for (int i=1;i<=2;i++)add(i,-1);
    }
    for (int i=7;i>=2;i--){
        while(ans[i]){
            printf("%d",i);
            ans[i]--;
        }
    }
    printf("\n");
    return 0;
}