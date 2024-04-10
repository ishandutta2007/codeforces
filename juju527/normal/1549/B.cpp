#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char s[maxn],t[maxn];
bool vis[maxn];
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
        for(int i=1;i<=n;i++)vis[i]=0;
        int num=0;
        for(int i=1;i<=n;i++){
            if(t[i]=='0')continue;
            if(i>1&&s[i-1]=='1')s[i-1]='2',vis[i-1]=1,num++;
            else if(s[i]=='0')s[i]='2',vis[i]=1,num++;
            else if(i<n&&s[i+1]=='1')s[i+1]='2',vis[i+1]=1,num++;
        }
        printf("%d\n",num);
    }
    return 0;
}