#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
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
        scanf("%s",s+1);
        int n=strlen(s+1);
        int o=0,z=0;
        for(int i=1;i<=n;i++)if(s[i]=='0')z++;else o++;
        if(o&&!z)puts("0");
        else if(!o&&z)puts("1");
        else{
            int num=0;
            for(int i=1;i<=n;i++)if(s[i]=='0')break;else num++;
            for(int i=n;i>=1;i--)if(s[i]=='0')break;else num++;
            if(num==o){puts("1");continue;}
            else puts("2");
        }
    }
    return 0;
}