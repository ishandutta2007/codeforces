#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<bitset>
using namespace std;
const int maxn=2e5+5,maxm=0,mod=0;
int n;
char s[maxn];
int cnt[maxn];
inline int read(){
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
void ADK(int p,int q){
    putchar('a'+p);--cnt[p];
    while(cnt[q])--cnt[q],putchar('a'+q);
    while(cnt[p])--cnt[p],putchar('a'+p);
}
void ADK2(int p,int q){
    putchar('a'+p);--cnt[p];
    putchar('a'+q);--cnt[q];
    while(cnt[p])--cnt[p],putchar('a'+p);
    for(int i=q+1;i<26;++i)
        if(cnt[i]){
            --cnt[i];putchar('a'+i);break;
        }
    for(int i=q;i<26;++i)
        while(cnt[i])--cnt[i],putchar('a'+i);
}
void Sub3(int p){
    for(int i=p+1;i<26;++i)
        if(cnt[i]>0){
            if(cnt[i]+cnt[p]==n)ADK(p,i);
            else ADK2(p,i);
            return;
        }
}
void proc(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=0;i<26;++i)
        cnt[i]=0;
    for(int i=1;i<=n;++i)
        ++cnt[s[i]-'a'];
    //f=0/f=n-1;
    for(int i=0;i<26;++i)
        if(cnt[i]){
            if(cnt[i]==n){
                while(cnt[i])--cnt[i],putchar('a'+i);
                puts("");
                return;
            }
            if(cnt[i]==1){
                putchar('a'+i);--cnt[i];
                for(int j=0;j<26;++j){
                    while(cnt[j])--cnt[j],putchar('a'+j);
                }
                puts("");
                return;
            }
        }
    for(int i=0;i<26;++i)
        if(cnt[i]){
            //Guaranteed that f(i)=1.
            //I Can Put 2 Front,Or only 1 Front.
            //Firstly Try put 2.
            if(cnt[i]-2<=n-cnt[i]){
                putchar('a'+i);
                putchar('a'+i);
                cnt[i]-=2;
                while(cnt[i]){
                    for(int j=0;j<26;++j)
                        if(cnt[j]&&i!=j){
                            putchar('a'+j);--cnt[j];break;
                        }
                    putchar('a'+i);
                    --cnt[i];
                }
                for(int j=0;j<26;++j){
                    while(cnt[j])--cnt[j],putchar('a'+j);
                }
                puts("");
                return;
            }
            else{
                Sub3(i);
                puts("");
                return;
            }
        }
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}