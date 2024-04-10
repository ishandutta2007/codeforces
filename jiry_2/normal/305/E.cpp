#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
char ch[6000];
int f[5010],pd[5010],n;
int main(){
    scanf("%s",ch+1); n=strlen(ch+1);
    memset(f,0x00,sizeof f); f[1]=1;
    for (int i=2;i<=n;i++){
        memset(pd,0x00,sizeof pd);
        pd[f[i-2]]=1;
        for (int j=2;j<=i-1;j++) pd[f[j-2]^f[i-j-1]]=1;
        for (int j=0;j<=n;j++) if (pd[j]==0){f[i]=j; break;}
    }
    memset(pd,0x00,sizeof pd);
    for (int i=2;i<n;i++) if (ch[i-1]==ch[i+1]) pd[i]=1;
    for (int i=1;i<=n;i++)
        if (pd[i]){
            int ans=0,now=0,k1=pd[i-1],k2=pd[i],k3=pd[i+1]; pd[i-1]=0; pd[i]=0; pd[i+1]=0;
            for (int j=1;j<=n;j++)
                if (pd[j]) now++; else {ans^=f[now]; now=0;}
            if (ans==0){
                cout<<"First"<<endl; cout<<i<<endl; return 0;
            }
            pd[i-1]=k1; pd[i]=k2; pd[i+1]=k3;
        }
    cout<<"Second"<<endl;
    return 0;
}