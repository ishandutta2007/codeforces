#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
char s[maxn];
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
        scanf("%s",s+1);
        bool flag=0;
        for(int i=n/2+1;i<=n;i++)if(s[i]=='0'){printf("1 %d 1 %d\n",i,i-1);flag=1;break;}
        if(flag)continue;
        int lim=n-(n/2);
        for(int i=1;i<=lim;i++)if(s[i]=='0'){printf("%d %d %d %d\n",i,n,i+1,n);flag=1;break;}
        if(flag)continue;
        printf("%d %d %d %d\n",1,n/2*2,1,n/2);
    }
    return 0;
}