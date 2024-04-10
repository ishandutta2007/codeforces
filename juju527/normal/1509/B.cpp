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
        int n;
        n=read();
        scanf("%s",s+1);
        int num=0;
        for(int i=1;i<=n;i++)if(s[i]=='M')num++;
        if(num!=(n/3)){puts("NO");continue;}
        int sum=0;
        bool flag=0;
        for(int i=1;i<=n;i++){
            sum+=(s[i]=='T'?1:-1);
            if(sum<0){flag=1;break;}
        }
        sum=0;
        for(int i=n;i>=1;i--){
            sum+=(s[i]=='T'?1:-1);
            if(sum<0){flag=1;break;}
        }
        if(flag)puts("NO");
        else puts("YES");
    }
    return 0;
}