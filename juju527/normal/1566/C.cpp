#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn],t[maxn];
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
        scanf("%s",t+1);
        int num=0;
        bool flag=0;
        int res=0;
        for(int i=1;i<=n;i++){
            if(s[i]!=t[i]){
                res+=flag?0:num;
                num=0;res+=2;
            }
            else{
                if(s[i]=='1'){
                    if(num&&!flag)res+=num+1,num=0;
                    else num++,flag=1;
                }
                else{
                    if(num&&flag)res+=2,num=0;
                    else num++,flag=0;
                }
            }
        }
        if(!flag)res+=num;
        printf("%d\n",res);
    }
    return 0;
}