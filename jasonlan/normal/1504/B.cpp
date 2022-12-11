#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=300010;
int n;
char s1[maxn],s2[maxn];
bool a[maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int main(){
    int T=read();
    while(T--){
        n=read();
        scanf("%s%s",s1+1,s2+1);
        for(int i=1,cnt=0;i<=n;++i){
            cnt+=(s1[i]=='1')?1:-1;
            a[i]=cnt==0;
        }
        bool can=true;
        for(int i=n,type,flag=0;i;--i){
            type=(s1[i]-'0')^flag;
            if(s2[i]-'0'!=type){
                if(!a[i]){
                    can=false;break;
                }
                flag^=1;
            }
        }
        puts(can?"YES":"NO");
    }
    return 0;
}