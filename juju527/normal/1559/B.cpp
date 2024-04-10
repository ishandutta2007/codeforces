#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
char chg[1000];
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
    chg['B']='R';chg['R']='B';
    s[0]='?';
    while(T--){
        int n;
        n=read();
        scanf("%s",s+1);
        int p=0;
        for(int i=1;i<=n;i++)
            if(s[i]!='?'){
                p=i;
                t[i]=s[i];
                for(int j=i-1;j>=1;j--)t[j]=chg[t[j+1]];
                break;
            }
        if(!p){
            for(int i=1;i<=n;i++)putchar((i&1)?'B':'R');
            puts("");
            continue;
        }
        for(int i=p+1;i<=n;i++){
            if(s[i]!='?')t[i]=s[i];
            else t[i]=chg[t[i-1]];
        }
        for(int i=1;i<=n;i++)putchar(t[i]);
        puts("");
    }
    return 0;
}