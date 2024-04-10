#include<bits/stdc++.h>
using namespace std;
int t[105];
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
        int n;
        n=read();
        for(int i=0;i<=100;i++)t[i]=0;
        for(int i=1;i<=n;i++)t[read()]++;
        int pos=0;
        for(int i=0;i<=100;i++){
            if(t[i])pos++,t[i]--;
            else break;
        }
        for(int i=0;i<pos;i++)printf("%d ",i);
        for(int i=0;i<=100;i++){
            for(int j=1;j<=t[i];j++)printf("%d ",i);
        }
        puts("");
    }
    return 0;
}