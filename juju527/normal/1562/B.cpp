#include<bits/stdc++.h>
using namespace std;
char s[55];
int d[10];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
    int T;
    T=read();
    while(T--){
        int k;
        k=read();
        scanf("%s",s+1);
        for(int i=0;i<10;i++)d[i]=0;
        for(int i=1;i<=k;i++)d[s[i]-'0']++;
        bool flag=0;
        for(int i=1;i<10;i++){
            if(i==2||i==3||i==5||i==7)continue;
            if(d[i]){printf("1\n%d\n",i);flag=1;break;}
        }
        if(flag)continue;
        for(int i=2;i<=k;i++){
            if(s[i]=='2'){printf("2\n%d2\n",s[1]-'0');flag=1;break;}
            if(s[i]=='5'){printf("2\n%d5\n",s[1]-'0');flag=1;break;}
        }
        if(flag)continue;
        if(d[3]>1){printf("2\n33\n");continue;}
        if(d[7]>1){printf("2\n77\n");continue;}
        if(d[2])printf("2\n27\n");
        if(d[5])printf("2\n57\n");
    }
    return 0;
}