#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int pd[10],bo[40];
int main(){
    int k1;
    scanf("%d",&k1);
    char ch[100]; scanf("%s",ch+1); scanf("%s",ch+1);
    if (ch[1]=='w') pd[k1]=1; else bo[k1]=1;
    int a=5,d=1,m=1,ans=0;
    for (int i=1;i<=366;i++){
        if (pd[a]||bo[d]) ans++;
        if (a==7) a=1; else a++;
        d++;
        if (m==1||m==3||m==5||m==7||m==8||m==10||m==12){
            if (d==32) d=1,m++; 
        } else if (m==2){
            if (d==30) d=1,m++;
        } else if (d==31){
            d=1; m++;
        }
    }
    printf("%d\n",ans);
    return 0;
}